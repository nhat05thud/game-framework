//
// Created by nguye on 7/6/2025.
//

#include "commands.hpp"

#include <glad/glad.h>

namespace opengl
{
	auto Commands::clear(const float r, const float g, const float b, const float a) -> void
	{
		glClearColor(r, g, b, a);
	}

	auto Commands::clear(const unsigned int flags) -> void
	{
		glClear(flags);
	}

	auto Commands::draw_vertices(const unsigned int primitive, const int count, const int offset) -> void
	{
		glDrawArrays(primitive, offset, count);
	}

	auto Commands::draw_elements(const unsigned int primitive, const int count, int offset) -> void
	{
		glDrawElements(primitive, count, GL_UNSIGNED_INT, nullptr);
	}
}