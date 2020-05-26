#pragma once

#include <glm/fwd.hpp>
#include <vector>
#include <glm/glm.hpp>
#include "opengl/texture.hpp"

namespace cardboard::graphics {
	class Texture {
	private:
		TexturePlatformData data;
		glm::uvec2 dimensions;

	public:
		Texture(glm::uvec2 dimensions, std::vector<glm::vec4> texture);
		Texture(glm::uvec2 dimensions, std::vector<glm::vec3> texture);
		Texture(glm::uvec2 dimensions, std::vector<glm::vec2> texture);
		Texture(glm::uvec2 dimensions, std::vector<unsigned char> texture);
		Texture(Texture&& texture);
		~Texture();

		void bind(unsigned int index);

		glm::uvec2 get_dimensions();
	};
}
