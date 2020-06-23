#pragma once

#include "../graphics/texture.hpp"
#include "graphics/texture_data.hpp"
#include <optional>

using cardboard::graphics::Texture;
using cardboard::graphics::TextureData;

namespace cardboard::resources {
	class TextureLoader {
	public:
		static std::optional<std::vector<unsigned char>> load_bytes(const char* path);
		static std::optional<TextureData> load_texture(const char* path);
	};
}
