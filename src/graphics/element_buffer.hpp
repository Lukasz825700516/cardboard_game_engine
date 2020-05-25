#pragma once

#include "opengl/element_buffer.hpp"

#include <vector>
#include <glm/glm.hpp>

namespace cardboard::graphics {
	class ElementBuffer {
	private:
		ElementBufferPlatformData data;

		std::vector<glm::uvec3> buffer;
	public:
		void bind();
		void flush();
		inline void resize(unsigned int size) { this->buffer.resize(size); }

		ElementBuffer();
		ElementBuffer(ElementBuffer&& eb);
		ElementBuffer(std::vector<glm::uvec3> buffer);
		~ElementBuffer();

		glm::uvec3& operator[](unsigned int index);
	};
}
