#pragma once

#include <vector>
#include <glm/glm.hpp>

namespace cardboard::graphics {
	class TexturePlatformData {
	public:
		unsigned int texture_id;

		TexturePlatformData(glm::uvec2 dimensions, unsigned int channels, void* data_ptr);
		TexturePlatformData(TexturePlatformData&& data);
		~TexturePlatformData();
	};
}
