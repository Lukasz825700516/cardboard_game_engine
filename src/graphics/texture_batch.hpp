#pragma once
#include "texture.hpp"
#include "shader.hpp"
#include <vector>

namespace cardboard::graphics {
	class TextureBatch {
	private:
		std::vector<unsigned int> loaded_textures;

	public:
		TextureBatch();
		TextureBatch(TextureBatch&&);

		bool push(Texture& texture);
		unsigned int get(Texture& texture);

		void flush(Shader& shader);
	};
}
