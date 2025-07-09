#include "vertex_array.hpp"
#include <glad/glad.h>

namespace opengl
{
	auto VertexArray::create() -> void 
	{
        glCreateVertexArrays(1, &_handle);
	}

	auto VertexArray::destroy() -> void 
	{ 
        glDeleteVertexArrays(1, &_handle);
	}

    auto VertexArray::attach_vertices(const unsigned int buffer, const int stride) const -> void
    {
	    glVertexArrayVertexBuffer(_handle, 0, buffer, 0, stride);
    }

    auto VertexArray::attach_elements(const unsigned int buffer) const -> void 
    {
	    glVertexArrayElementBuffer(_handle, buffer);
    }

    auto VertexArray::attribute(const unsigned int index, const int size,
                                const unsigned int type,
                                const unsigned char normalized,
                                const unsigned int offset) const -> void
    {
	    glVertexArrayAttribFormat(_handle, index, size, type, normalized, offset);
	    glVertexArrayAttribBinding(_handle, 0, 0);

	    glEnableVertexArrayAttrib(_handle, 0);
    }

    auto VertexArray::bind() const -> void 
    { 
        glBindVertexArray(_handle);
    }
} 