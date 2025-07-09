//
// Created by nguye on 7/9/2025.
//

#ifndef PIPELINE_HPP
#define PIPELINE_HPP

namespace opengl
{
	class Pipeline
	{
	  public:
	    static auto  enable(unsigned int flag) -> void;
	    static auto disable(unsigned int flag) -> void;

		Pipeline() = delete;


	  private:
		
	};
} // namespace opengl

#endif // PIPELINE_HPP
