#pragma once

#include "opengl/vertex_buffer.hpp"
#include "vertex.hpp"

#include <optional>
#include <vector>

namespace cardboard::graphics {
	class VertexBuffer {
	private:
		VertexBufferPlatformData data;

		std::optional<std::vector<Vertex>> buffer;
	public:
		void bind();
		void update();
		void flush();

		VertexBuffer(std::vector<Vertex> buffer);
		~VertexBuffer();
	};
}
