//
// Created by nguye on 7/9/2025.
//

#include "functions.hpp"
#include "functions/commands.hpp"

namespace opengl
{
	auto Functions::init() -> void
	{
		init_commands();
	}

	auto Functions::init_commands() -> void
	{
		if (const auto instance = LoadLibrary("opengl32.dll"))
		{
			functions::glClear = reinterpret_cast<functions::PFNGLCLEARPROC>(GetProcAddress(instance, "glClear"));

			FreeLibrary(instance);
		}
	}
}