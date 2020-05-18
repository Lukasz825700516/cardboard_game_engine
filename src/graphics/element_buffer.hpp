#pragma once

#include "element_buffer.opengl.hpp"

#include <optional>
#include <vector>
#include <glm/glm.hpp>

namespace cardboard::graphics {
	class ElementBuffer {
	private:
		ElementBufferPlatformData data;

		std::optional<std::vector<glm::uvec3>> buffer;
	public:
		void load();
		void unload();

		void bind();
		void update();

		ElementBuffer(std::vector<glm::uvec3> buffer);
	};
}
