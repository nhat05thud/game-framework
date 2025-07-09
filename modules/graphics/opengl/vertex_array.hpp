#ifndef VERTEXARRAY_HPP
#define VERTEXARRAY_HPP

#include "object.hpp"

namespace opengl
{
	class VertexArray : public Object
	{
	  public:
	    auto create()  -> void override;
	    auto destroy() -> void override;

		auto attach_vertices(unsigned int buffer, int stride) const -> void;
	    auto attach_elements(unsigned int buffer) const -> void;

		auto attribute(unsigned int index, int size, unsigned int type,
	                   unsigned char normalized, unsigned int offset) const -> void;
	    auto bind() const -> void;
	};
} // namespace opengl

#endif // VERTEXARRAY_HPP
