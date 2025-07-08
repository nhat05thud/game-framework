//
// Created by nguye on 7/9/2025.
//

#ifndef CONSTANTSCOMMANDS_HPP
#define CONSTANTSCOMMANDS_HPP

namespace opengl::functions
{
	typedef unsigned int GLbitfield;

	using PFNGLCLEARPROC = void(APIENTRY*)(GLbitfield mask);

	inline PFNGLCLEARPROC glClear;
}

#endif //CONSTANTSCOMMANDS_HPP
