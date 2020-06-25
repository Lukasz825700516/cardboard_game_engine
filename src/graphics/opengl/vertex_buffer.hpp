#pragma once

namespace cardboard::graphics {
	class VertexBufferPlatformData {
	public:
		explicit VertexBufferPlatformData();
		explicit VertexBufferPlatformData(const VertexBufferPlatformData&) = delete;
		explicit VertexBufferPlatformData(VertexBufferPlatformData&& data);
		~VertexBufferPlatformData();

		VertexBufferPlatformData& operator=(VertexBufferPlatformData&&);

		unsigned int vertex_buffer_object;
	};
}
