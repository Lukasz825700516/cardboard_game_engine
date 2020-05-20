#include "glad/glad.h"
#include "../vertex_buffer.hpp"

namespace cardboard::graphics {
	VertexBuffer::VertexBuffer(std::vector<Vertex> buffer):
		buffer(buffer) {

		glad_glGenBuffers(1, &this->data.vertex_buffer_object);
	}

	VertexBuffer::~VertexBuffer() {
		glad_glDeleteBuffers(1, &this->data.vertex_buffer_object);
	}

	void VertexBuffer::bind() {
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.vertex_buffer_object);
	}

	void VertexBuffer::flush() {
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.vertex_buffer_object);
		glad_glBufferData(GL_ARRAY_BUFFER,
			this->buffer->size() * sizeof(Vertex),
			this->buffer->data(),
			GL_STATIC_DRAW);
	}
}
