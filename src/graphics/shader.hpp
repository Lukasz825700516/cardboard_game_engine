#pragma once

#include "opengl/shader.hpp"

#include <glm/glm.hpp>

namespace cardboard::graphics {
	class Shader {
	private:
		ShaderPlatformData data;

	public:
		Shader(const char* vertex_code, const char* fragment_code);
		~Shader();
		
		void bind();

		void set_uniform(glm::mat4& value, const char* name);
		void set_uniform(glm::vec2 value, const char* name);
		void set_uniform(glm::vec3 value, const char* name);
	};
}
