#pragma once

#include <glm/glm.hpp>
#include "opengl/texture.hpp"
#include "texture_data.hpp"

namespace cardboard::graphics {

	class Texture {
	private:
		TexturePlatformData platform_data;
		TextureData texture_data;

	public:
		explicit Texture() = delete;
		explicit Texture(const Texture&) = delete;
		explicit Texture(Texture&&) = default;
		~Texture() = default;

		Texture(TextureData&& texture_data);

		void bind(unsigned int index);
		inline TexturePlatformData& data() { return this->platform_data; }
	};
}
