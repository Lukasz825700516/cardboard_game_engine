#pragma once

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include "opengl/texture.hpp"
#include "texture_data.hpp"

namespace cardboard::graphics {

	class Texture {
	private:
		TexturePlatformData platform_data;
		TextureData texture_data;

	public:
		Texture(TextureData&& texture_data);
		Texture(Texture&& texture);
		~Texture();

		void bind(unsigned int index);
		inline TexturePlatformData& data() { return this->platform_data; }
	};
}
