#pragma once 

#include "opengl/mesh.hpp"

#include "vertex_buffer.hpp"
#include "element_buffer.hpp"

namespace cardboard::graphics {
	class Mesh {
	private:
		MeshPlatformData data;
		VertexBuffer& vb;
		ElementBuffer& eb;

	public:
		Mesh(VertexBuffer& vb, ElementBuffer& eb);
		~Mesh();

		void bind();
	};
}
