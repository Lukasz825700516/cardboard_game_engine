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
		inline void resize(unsigned int size) { this->buffer.resize(size); }

		explicit VertexBuffer() = default;
		explicit VertexBuffer(const VertexBuffer&) = delete;
		explicit VertexBuffer(VertexBuffer&&) = default;
		~VertexBuffer() = default;

		explicit VertexBuffer(std::vector<Vertex> buffer);

		Vertex& operator[](unsigned int index);
	};
}
