#include "glad/glad.h"
#include "../vertex_buffer.hpp"
#include "graphics/opengl/vertex_buffer.hpp"
#include <utility>

namespace cardboard::graphics {
	VertexBufferPlatformData::VertexBufferPlatformData() {
		glad_glGenBuffers(1, &this->vertex_buffer_object);
	}

	VertexBufferPlatformData::VertexBufferPlatformData(VertexBufferPlatformData&& data):
   		vertex_buffer_object(std::exchange(data.vertex_buffer_object, 0)) {}

	VertexBufferPlatformData::~VertexBufferPlatformData() {
		if (this->vertex_buffer_object) {
			glad_glDeleteBuffers(1, &this->vertex_buffer_object);
		}
	}

	VertexBuffer::VertexBuffer() {}
	VertexBuffer::VertexBuffer(VertexBuffer&& vb):
		data(std::move(vb.data)),
   		buffer(std::move(vb.buffer)) {}
	VertexBuffer::VertexBuffer(std::vector<Vertex> buffer):
		buffer(buffer) {}
	VertexBuffer::~VertexBuffer() {}

	void VertexBuffer::bind() {
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.vertex_buffer_object);
	}

	void VertexBuffer::flush() {
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.vertex_buffer_object);
		glad_glBufferData(GL_ARRAY_BUFFER,
			this->buffer.size() * sizeof(Vertex),
			this->buffer.data(),
			GL_STATIC_DRAW);
	}

	Vertex& VertexBuffer::operator[](unsigned int index) {
		return this->buffer[index];
	}
}
