//
// Created by nguye on 7/6/2025.
//

#ifndef COMMANDS_HPP
#define COMMANDS_HPP


namespace opengl
{
	class Commands {
	public:
		static auto clear(float r, float g, float b, float a) -> void;
		static auto clear(unsigned int flags) -> void;
	};
}

#endif //COMMANDS_HPP
