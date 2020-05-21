#pragma once

#include "opengl/vertex_buffer.hpp"
#include "vertex.hpp"

#include <optional>
#include <vector>

namespace cardboard::graphics {
	class VertexBuffer {
	private:
		VertexBufferPlatformData data;

		std::vector<Vertex> buffer;
	public:
		void bind();
		void flush();

		VertexBuffer();
		VertexBuffer(VertexBuffer&& vb);
		VertexBuffer(std::vector<Vertex> buffer);
		~VertexBuffer();

		Vertex& operator[](unsigned int index);
	};
}
