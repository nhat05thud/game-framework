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
}