#include "../texture.hpp"
#include "glad/glad.h"
#include <utility>

namespace cardboard::graphics {
	TexturePlatformData::TexturePlatformData(glm::uvec2 dimensions, unsigned int channels, void* data_ptr) {
		glad_glGenTextures(GL_TEXTURE_2D, &this->texture_id);
		glad_glBindTexture(GL_TEXTURE_2D, this->texture_id);

		glad_glTexParameteri(this->texture_id, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glad_glTexParameteri(this->texture_id, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glad_glTexParameteri(this->texture_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glad_glTexParameteri(this->texture_id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		glad_glTexImage2D(this->texture_id, 0, GL_RGB, dimensions.x, dimensions.y, 0, GL_RGB, GL_UNSIGNED_BYTE, data_ptr);

		(void) channels;
	}

	TexturePlatformData::TexturePlatformData(TexturePlatformData&& data):
		texture_id(std::exchange(data.texture_id, 0)) {}

	TexturePlatformData::~TexturePlatformData() {
		if (this->texture_id) {
			glad_glDeleteTextures(1, &this->texture_id);
		}
	}

	Texture::Texture(glm::uvec2 dimensions, std::vector<glm::vec4> texture):
   		data(dimensions, 4, texture.data()),
   		dimensions(dimensions) {}

	Texture::Texture(glm::uvec2 dimensions, std::vector<glm::vec3> texture):
   		data(dimensions, 3, texture.data()),
   		dimensions(dimensions) {}

	Texture::Texture(glm::uvec2 dimensions, std::vector<glm::vec2> texture):
   		data(dimensions, 2, texture.data()),
   		dimensions(dimensions) {}

	Texture::Texture(glm::uvec2 dimensions, std::vector<unsigned char> texture):
   		data(dimensions, 1, texture.data()),
   		dimensions(dimensions) {}

	Texture::Texture(Texture&& texture):
		data(std::move(texture.data)),
   		dimensions(texture.dimensions) {}

	Texture::~Texture() {}

	void Texture::bind(unsigned int index) {
		glad_glBindTexture(GL_TEXTURE_2D, this->data.texture_id);

		(void)index;
	}

	glm::uvec2 Texture::get_dimensions() {
		return this->dimensions;
	}
}
