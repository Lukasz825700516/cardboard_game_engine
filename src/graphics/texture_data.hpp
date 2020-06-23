#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace cardboard::graphics {
	enum TextureChannels {
		CARDBOARD_TEXTURE_R,
		CARDBOARD_TEXTURE_RG,
		CARDBOARD_TEXTURE_RGB,
		CARDBOARD_TEXTURE_RGBA,
	};

	class TextureData {
	public:
		glm::uvec2 dimensions;
		TextureChannels channels;
		std::vector<unsigned char> data;

		TextureData();
		TextureData(glm::uvec2 dimensions, TextureChannels channels);
		TextureData(TextureData&& data);
		~TextureData();
	};
}

