#pragma once

#include "vertex_buffer.opengl.hpp"
#include "vertex.hpp"

#include <optional>
#include <vector>

namespace cardboard::graphics {
	class VertexBuffer {
	private:
		VertexBufferPlatformData data;

		std::optional<std::vector<Vertex>> buffer;
	public:
		void load();
		void unload();

		void bind();
		void update();

		VertexBuffer(std::vector<Vertex> buffer);
	};
}
