#include "glad/glad.h"
#include "../element_buffer.hpp"
#include <glm/glm.hpp>

namespace cardboard::graphics {
	ElementBuffer::ElementBuffer(std::vector<glm::uvec3> buffer):
		buffer(buffer) {

		glad_glGenBuffers(1, &this->data.element_buffer_object);
	}

	ElementBuffer::~ElementBuffer() {
		glad_glDeleteBuffers(1, &this->data.element_buffer_object);
	}

	void ElementBuffer::bind() {
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.element_buffer_object);
	}

	void ElementBuffer::flush() {
		glad_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->data.element_buffer_object);
		glad_glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			this->buffer->size() * sizeof(glm::uvec3),
			this->buffer->data(),
			GL_STATIC_DRAW);
	}
}
