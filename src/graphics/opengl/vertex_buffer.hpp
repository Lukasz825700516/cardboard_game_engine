#pragma once

namespace cardboard::graphics {
	class VertexBufferPlatformData {
	public:
		unsigned int vertex_buffer_object;

		VertexBufferPlatformData();
		VertexBufferPlatformData(VertexBufferPlatformData&& data);
		~VertexBufferPlatformData();
	};
}
