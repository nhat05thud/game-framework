#include "debug.hpp"
#include "pipeline.hpp"
#include <glad/glad.h>
#include <iostream>

namespace opengl 
{
	auto Debug::init() -> void 
	{ 
		Pipeline::enable(GL_DEBUG_OUTPUT);
        Pipeline::enable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

		glDebugMessageCallback([](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam) 
		{
              std::cerr << std::format("{}\n", message) << std::endl;
		}, nullptr);
	}
}