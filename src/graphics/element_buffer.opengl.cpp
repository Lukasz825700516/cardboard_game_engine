#include "glad/glad.h"
#include "element_buffer.hpp"
#include <GL/glext.h>

namespace cardboard::graphics {
	void ElementBuffer::load() {
		glad_glCreateBuffers(1, &this->data.element_buffer_object);
		glad_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->data.element_buffer_object);
		glad_glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			this->buffer.value().size() * sizeof(glm::uvec3),
			this->buffer.value().data(),
			GL_STATIC_DRAW);
	}

	void ElementBuffer::bind() {
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.element_buffer_object);
	}

	void ElementBuffer::unload() {
		glad_glDeleteBuffers(1, &this->data.element_buffer_object);
	}
}
