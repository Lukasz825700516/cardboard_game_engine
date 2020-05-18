#include "glad/glad.h"
#include "vertex_buffer.hpp"
#include <GL/glext.h>

namespace cardboard::graphics {
	void VertexBuffer::load() {
		glad_glCreateBuffers(1, &this->data.vertex_buffer_object);
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.vertex_buffer_object);
		glad_glBufferData(GL_ARRAY_BUFFER,
			this->buffer.value().size() * sizeof(Vertex),
			this->buffer.value().data(),
			GL_STATIC_DRAW);

		glad_glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
			sizeof(Vertex),
			(void *)offsetof(Vertex, pos));
		glad_glEnableVertexAttribArray(0);

		glad_glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
			sizeof(Vertex),
			(void *)offsetof(Vertex, uv));
		glad_glEnableVertexAttribArray(1);
	}

	void VertexBuffer::bind() {
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.vertex_buffer_object);
	}

	void VertexBuffer::unload() {
		glad_glDeleteBuffers(1, &this->data.vertex_buffer_object);
	}
}
