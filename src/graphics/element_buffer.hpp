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
		explicit ElementBuffer() = default;
		explicit ElementBuffer(const ElementBuffer&) = delete;
		explicit ElementBuffer(ElementBuffer&&) = default;
		~ElementBuffer() = default;

		explicit ElementBuffer(std::vector<glm::uvec3> buffer);

		void bind();
		void flush();
		inline void resize(unsigned int size) { this->buffer.resize(size); }


		glm::uvec3& operator[](unsigned int index);
	};
}
