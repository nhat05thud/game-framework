//
// Created by nguye on 7/9/2025.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace opengl
{
	class Object
	{
	  public:
	    virtual auto  create() -> void = 0;
	    virtual auto destroy() -> void = 0;

		[[nodiscard, maybe_unused]] auto handle() const -> unsigned int;
	    [[nodiscard, maybe_unused]] auto   info() const -> unsigned int;

	  protected:
		unsigned int _handle { };
	    unsigned int _info	 { };
	};
}

#endif // OBJECT_HPP