#pragma once
#include "texture.hpp"
#include "shader.hpp"
#include <vector>

namespace cardboard::graphics {
	class TextureBatch {
	private:
		std::vector<unsigned int> loaded_textures;

	public:
		explicit TextureBatch() = default;
		explicit TextureBatch(const TextureBatch&) = default;
		explicit TextureBatch(TextureBatch&&) = default;
		~TextureBatch() = default;

		bool push(Texture& texture);
		unsigned int get(Texture& texture);
		void flush(Shader& shader);
	};
}
