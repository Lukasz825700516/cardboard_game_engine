#include "../texture_batch.hpp"
#include "glad/glad.h"
#include <algorithm>
#include <iostream>

namespace cardboard::graphics {
	bool TextureBatch::push(Texture& texture) {
		// Check if texture already was pushed
		for (unsigned int id : this->loaded_textures) {
			if (id == texture.data().texture_id) {
				return true;
			}
		}

		// Push texture
		this->loaded_textures.push_back(texture.data().texture_id);

		return true;
	}

	unsigned int TextureBatch::get(Texture& texture) {
		for (size_t i = 0; i < this->loaded_textures.size(); i++) {
			if (this->loaded_textures[i] == texture.data().texture_id) return i;
		}

		return -1;
	}

	void TextureBatch::flush(Shader& shader) {
		for (size_t i = 0; i < this->loaded_textures.size(); i++) {
			glad_glActiveTexture(GL_TEXTURE0 + i);
			glad_glBindTexture(GL_TEXTURE_2D, this->loaded_textures[i]);
		}
		int textures[16];
		std::transform(this->loaded_textures.begin(), this->loaded_textures.end(), textures, [] (unsigned int t) {return t - 1;});
		shader.set_uniform("u_textures", this->loaded_textures.size(), textures);
	}
}
