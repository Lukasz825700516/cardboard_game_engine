#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "../texture_data.hpp"

namespace cardboard::graphics {
	class TexturePlatformData {
	public:
		explicit TexturePlatformData();
		explicit TexturePlatformData(const TexturePlatformData&) = delete;
		explicit TexturePlatformData(TexturePlatformData&&) = default;
		~TexturePlatformData();

		explicit TexturePlatformData(TextureData& texture_data);

		unsigned int texture_id;
	};
}
