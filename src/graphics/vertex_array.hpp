#pragma once 

#include "opengl/vertex_array.hpp"

#include "vertex_buffer.hpp"
#include "element_buffer.hpp"

namespace cardboard::graphics {
	class VertexArray {
	private:
		VertexArrayPlatformData data;
		VertexBuffer vb;
		ElementBuffer eb;

	public:
		explicit VertexArray();
		explicit VertexArray(const VertexArray&) = delete;
		explicit VertexArray(VertexArray&&) = default;
		~VertexArray() = default;

		explicit VertexArray(VertexBuffer&& vb, ElementBuffer&& eb);

		void bind();
		void flush();
		
		inline VertexBuffer& get_vertex_buffer() { return this->vb; }
		inline ElementBuffer& get_element_buffer() { return this->eb; }
	};
}
