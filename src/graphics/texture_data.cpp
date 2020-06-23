#include "texture_data.hpp"
#include <utility>

namespace cardboard::graphics {
	TextureData::TextureData() {}

	TextureData::TextureData(glm::uvec2 dimensions, TextureChannels channels):
   		dimensions(dimensions),
		channels(channels) {}

	TextureData::TextureData(TextureData&& data):
   		dimensions(data.dimensions),
		channels(data.channels),
		data(std::move(data.data)) {}

	TextureData::~TextureData() {}
}
