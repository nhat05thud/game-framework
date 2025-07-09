//
// Created by nguye on 7/6/2025.
//

#include <opengl/commands.hpp>
#include <opengl/functions.hpp>
#include <opengl/debug.hpp>
#include <opengl/vertex_array.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include "opengl/constants/commands.hpp"

auto vertex_stage_source =
"#version 450\n"
"layout (location = 0) in vec3 in_position;\n"
"layout (location = 0) uniform mat4 u_model;\n"
"layout (location = 1) uniform mat4 u_view;\n"
"layout (location = 2) uniform mat4 u_proj;\n"
"void main()\n"
"{\n"
"	gl_Position = u_proj * u_view * u_model * vec4(in_position, 1.0);\n"
"}\n";
auto fragment_stage_source =
"#version 450\n"
"layout (location = 0) out vec4 out_color;\n"
"layout (location = 0) uniform vec3 u_color;\n"
"\n"
"void main()\n"
"{\n"
"	out_color = vec4(u_color, 1.0);\n"
"}\n";

auto main() -> int
{
	if (glfwInit() != GLFW_TRUE)
	{
		return -1;
	}
	static auto window_width { 1024 };
	static auto window_height { 768 };
	static bool window_closed { };

	const auto window = glfwCreateWindow(window_width, window_height, "Game Framework", nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, [](int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			window_closed = true;
		}
		if (key == GLFW_KEY_TAB && action == GLFW_PRESS) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
	});

	glfwSetWindowCloseCallback(window, []
	{
		window_closed = true;
	});

	glfwMakeContextCurrent(window);

	gladLoadGL();

	opengl::Functions::init();
        opengl::Debug::init();

	const std::vector vertices
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
	};

	const std::vector<unsigned int> elements
	{
		0, 1, 2,
		1, 2, 3,
	};

	uint32_t vbo, ebo;
	// vao: vertex array object
	// vbo: vertex buffer object
	// ebo: element buffer object

	glCreateBuffers(1, &vbo);
	glNamedBufferStorage(vbo, vertices.size() * sizeof(float), vertices.data(), 0);

	glCreateBuffers(1, &ebo);
	glNamedBufferStorage(ebo, elements.size() * sizeof(unsigned int), elements.data(), 0);

	opengl::VertexArray vao;
	vao.create();

	vao.attach_vertices(vbo, sizeof(float) * 3);
	vao.attach_elements(ebo);

	vao.attribute(0, 3, GL_FLOAT, GL_FALSE, 0);

	const auto vert_stage = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_stage, 1, &vertex_stage_source, nullptr);
	glCompileShader(vert_stage);

	const auto frag_stage = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_stage, 1, &fragment_stage_source, nullptr);
	glCompileShader(frag_stage);

	const auto shader = glCreateProgram();
	glAttachShader(shader, vert_stage);
	glAttachShader(shader, frag_stage);
	glLinkProgram(shader);

	opengl::Commands::clear(0.5f, 0.5f, 0.5f, 1.0f);

	auto view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
	auto proj = glm::perspective(glm::radians(45.0f), static_cast<float>(window_width) / static_cast<float>(window_height), 0.1f, 1000.0f);

	while (!window_closed)
	{
		glfwPollEvents();

		opengl::Commands::clear(opengl::constants::color_buffer);

		glUseProgram(shader);

		glUniformMatrix4fv(1, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(2, 1, GL_FALSE, glm::value_ptr(proj));

		vao.bind();

		glUniform3f(3, 1.0, 0.502, 0.251);

		auto model = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			 model = glm::rotate(model, static_cast<float>(glfwGetTime()), glm::vec3(0.0f, 0.0f, 1.0f));

		glUniformMatrix4fv(0, 1, GL_FALSE, glm::value_ptr(model));
		opengl::Commands::draw_elements(opengl::constants::triangles, elements.size());
		
		glUniform3f(3, 0.0f, 1.0f, 0.0f);

		model = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, static_cast<float>(glfwGetTime()), glm::vec3(0.0f, 0.0f, 1.0f));

		glUniformMatrix4fv(0, 1, GL_FALSE, glm::value_ptr(model));
		opengl::Commands::draw_elements(opengl::constants::triangles, elements.size());

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}