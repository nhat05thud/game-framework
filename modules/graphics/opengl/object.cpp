#include "object.hpp"

#include <cstdint>

namespace opengl
{
	auto Object::handle() const -> uint32_t 
	{ 
		return _handle; 
	}

	auto Object::info() const -> uint32_t 
	{ 
		return _info; 
	}
}