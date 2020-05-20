#pragma once

#include "opengl/shader.hpp"

namespace cardboard::graphics {
	class Shader {
	private:
		ShaderPlatformData data;

	public:
		Shader(const char* vertex_code, const char* fragment_code);
		~Shader();
		
		void bind();
	};
}
