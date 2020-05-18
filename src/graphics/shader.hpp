#pragma once

#include "shader.opengl.hpp"

namespace cardboard::graphics {
	class Shader {
	private:
		ShaderPlatformData data;

	public:
		Shader(const char* vertex_code, const char* fragment_code);
		
		void destroy();
		void bind();
	};
}
