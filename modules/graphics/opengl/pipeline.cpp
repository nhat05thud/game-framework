#include "pipeline.hpp"
#include <glad/glad.h>

namespace opengl
{
	auto Pipeline::enable(const unsigned int flag) -> void 
	{
		glEnable(flag);
	}

	auto Pipeline::disable(const unsigned int flag) -> void 
	{ 
		glDisable(flag);
	}

}