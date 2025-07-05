//
// Created by nguye on 7/6/2025.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

auto main() -> int
{
	if (glfwInit() != GLFW_TRUE)
	{
		return -1;
	}
	static auto window_width { 1366 };
	static auto window_height { 768 };
	static bool window_closed { };

	const auto window = glfwCreateWindow(window_width, window_height, "Game Framework", nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();

	glfwSetKeyCallback(window, [](int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			window_closed = true;
		}
	});

	glfwSetWindowCloseCallback(window, []
	{
		window_closed = true;
	});

	while (!window_closed)
	{
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}