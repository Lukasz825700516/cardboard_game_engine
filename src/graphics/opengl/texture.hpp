#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "../texture_data.hpp"

namespace cardboard::graphics {
	class TexturePlatformData {
	public:
		unsigned int texture_id;

		TexturePlatformData(TextureData& texture_data);
		TexturePlatformData(TexturePlatformData&& data);
		~TexturePlatformData();
	};
}
