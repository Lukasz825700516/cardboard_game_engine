#include "../texture.hpp"
#include "glad/glad.h"
#include <utility>

namespace cardboard::graphics {
	TexturePlatformData::TexturePlatformData(TextureData& texture_data) {
		glad_glGenTextures(1, &this->texture_id);
		glad_glBindTexture(GL_TEXTURE_2D, this->texture_id);

		glad_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glad_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glad_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glad_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int channels = 0;

		switch(texture_data.channels) {
			case CARDBOARD_TEXTURE_R: channels = GL_R; break;
			case CARDBOARD_TEXTURE_RG: channels = GL_RG; break;
			case CARDBOARD_TEXTURE_RGB: channels = GL_RGB; break;
			case CARDBOARD_TEXTURE_RGBA: channels = GL_RGBA; break;
		}

		glad_glTexImage2D(
			GL_TEXTURE_2D,
			0,
			channels,
			texture_data.dimensions.x,
			texture_data.dimensions.y,
			0,
			channels,
			GL_UNSIGNED_BYTE,
			texture_data.data.data()); 

		glad_glBindTexture(GL_TEXTURE_2D, this->texture_id);
	}

	TexturePlatformData::~TexturePlatformData() {
		if (this->texture_id) {
			glad_glDeleteTextures(1, &this->texture_id);
		}
	}

	Texture::Texture(TextureData&& data):
		platform_data(data),
   		texture_data(std::move(data)) {
	
	}

	void Texture::bind(unsigned int index) {
		glad_glBindTexture(GL_TEXTURE_2D, this->platform_data.texture_id);

		(void)index;
	}
}
