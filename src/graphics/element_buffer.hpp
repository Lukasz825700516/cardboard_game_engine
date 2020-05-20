#pragma once

#include "opengl/element_buffer.hpp"

#include <optional>
#include <vector>
#include <glm/glm.hpp>

namespace cardboard::graphics {
	class ElementBuffer {
	private:
		ElementBufferPlatformData data;

		std::optional<std::vector<glm::uvec3>> buffer;
	public:
		void bind();
		void update();
		void flush();

		ElementBuffer(std::vector<glm::uvec3> buffer);
		~ElementBuffer();
	};
}
