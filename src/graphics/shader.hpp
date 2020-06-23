#pragma once

#include "opengl/shader.hpp"

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include "texture.hpp"

namespace cardboard::graphics {
	class Shader {
	private:
		ShaderPlatformData data;

	public:
		Shader(const char* vertex_code, const char* fragment_code);
		~Shader();
		
		void bind();

		void set_uniform(glm::mat4& value, const char* name);
		void set_uniform(glm::mat3& value, const char* name);
		void set_uniform(glm::mat2& value, const char* name);
		void set_uniform(glm::vec4 value, const char* name);
		void set_uniform(glm::vec3 value, const char* name);
		void set_uniform(glm::vec2 value, const char* name);
		void set_uniform(float value, const char* name);
		void set_uniform(glm::ivec4 value, const char* name);
		void set_uniform(glm::ivec3 value, const char* name);
		void set_uniform(glm::ivec2 value, const char* name);
		void set_uniform(int value, const char* name);

		void set_uniform(const char* name, size_t size, int* value);
	};
}
