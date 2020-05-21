#include "glad/glad.h"
#include "../vertex_array.hpp"
#include "../context.hpp"
#include <utility>

namespace cardboard::graphics {
	VertexArrayPlatformData::VertexArrayPlatformData() {
		glad_glGenVertexArrays(1, &this->vertex_buffer_array);
	}

	VertexArrayPlatformData::VertexArrayPlatformData(VertexArrayPlatformData&& data):
   		vertex_buffer_array(std::exchange(data.vertex_buffer_array, 0)) {}
	VertexArrayPlatformData::~VertexArrayPlatformData() {
		if (this->vertex_buffer_array) {
			glad_glDeleteVertexArrays(1, &this->vertex_buffer_array);
		}
	}

	VertexArray::VertexArray() {
		this->bind();
		this->vb.flush();
		this->eb.flush();

		glad_glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
			sizeof(Vertex),
			(void *)offsetof(Vertex, pos));
		glad_glEnableVertexAttribArray(0);

		glad_glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
			sizeof(Vertex),
			(void *)offsetof(Vertex, uv));
		glad_glEnableVertexAttribArray(1);
	}

	VertexArray::VertexArray(VertexArray&& va):
		vb(std::move(va.vb)), 
		eb(std::move(va.eb)),
   		data(std::move(va.data)) {
	}

	VertexArray::VertexArray(VertexBuffer&& vb, ElementBuffer&& eb):
   		vb(std::move(vb)), eb(std::move(eb)) {

		vb.flush();
		eb.flush();

		glad_glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
			sizeof(Vertex),
			(void *)offsetof(Vertex, pos));
		glad_glEnableVertexAttribArray(0);

		glad_glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
			sizeof(Vertex),
			(void *)offsetof(Vertex, uv));
		glad_glEnableVertexAttribArray(1);
	}

	VertexArray::~VertexArray() {}

	void VertexArray::bind() {
		glad_glBindVertexArray(this->data.vertex_buffer_array);
	}

	void VertexArray::flush() {
		this->vb.flush();
		this->eb.flush();
	}
}
