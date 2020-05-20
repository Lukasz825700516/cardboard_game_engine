#include "glad/glad.h"
#include "../mesh.hpp"
#include "../context.hpp"

namespace cardboard::graphics {
	Mesh::Mesh(VertexBuffer& vb, ElementBuffer& eb):
   		vb(vb), eb(eb) {

		glad_glGenVertexArrays(1, &this->data.vertex_buffer_array);
		glad_glBindVertexArray(this->data.vertex_buffer_array);

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

	Mesh::~Mesh() {
		glad_glDeleteVertexArrays(1, &this->data.vertex_buffer_array);
	}

	void Mesh::bind() {
		glad_glBindVertexArray(this->data.vertex_buffer_array);
	}
}
