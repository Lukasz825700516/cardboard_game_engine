#include "texture_loader.hpp"
#include "graphics/texture_data.hpp"
#include <optional>
#include <stb_image.h>


namespace cardboard::resources {
	std::optional<TextureData> TextureLoader::load_texture(const char* path) {
		TextureData data;

		int x;
		int y;
		int channels;

		stbi_set_flip_vertically_on_load_thread(true);
		unsigned char* texture_begin = stbi_load(path, &x, &y, &channels, 0);
		unsigned char* texture_end = texture_begin + x * y * channels;

		switch (channels) {
			case 1: data.channels = graphics::CARDBOARD_TEXTURE_R; break;
			case 2: data.channels = graphics::CARDBOARD_TEXTURE_RG; break;
			case 3: data.channels = graphics::CARDBOARD_TEXTURE_RGB; break;
			case 4: data.channels = graphics::CARDBOARD_TEXTURE_RGBA; break;
		}

		data.dimensions = glm::uvec2(x, y);
		data.data = std::vector(
			std::vector<unsigned char>::iterator(texture_begin),
			std::vector<unsigned char>::iterator(texture_end));

		stbi_image_free(texture_begin);

		return std::optional(TextureData(data));
	}
}
