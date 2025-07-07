//
// Created by nguye on 7/6/2025.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <opengl/commands.hpp>

#include <vector>

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

	opengl::Commands::clear(0.5f, 0.5f, 0.5f, 1.0f);

	while (!window_closed)
	{
		glfwPollEvents();

		opengl::Commands::clear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		// not apply element buffer
		//glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		// opengl::Commands::draw_vertices(GL_TRIANGLES, vertices.size());

		// apply element buffer
		// glDrawElements(GL_TRIANGLES, elements.size(), GL_UNSIGNED_INT, nullptr);
		opengl::Commands::draw_elements(GL_TRIANGLES, elements.size());

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}