//
// Created by nguye on 7/6/2025.
//

#include <opengl/commands.hpp>
#include <opengl/functions.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include "opengl/constants/commands.hpp"

auto vertex_stage_source =
"#version 450\n"
"layout (location = 0) in vec3 in_position;\n"
"\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(in_position, 1.0);\n"
"}\n";
auto fragment_stage_source =
"#version 450\n"
"layout (location = 0) out vec4 out_color;\n"
"\n"
"void main()\n"
"{\n"
"	out_color = vec4(1.0, 0.502, 0.251, 1.0);\n"
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

	uint32_t vao, vbo, ebo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(unsigned int), elements.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
	glEnableVertexAttribArray(0);

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

	while (!window_closed)
	{
		glfwPollEvents();

		opengl::Commands::clear(opengl::constants::color_buffer);

		glUseProgram(shader);

		glBindVertexArray(vao);

		opengl::Commands::draw_elements(opengl::constants::triangles, elements.size());

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}