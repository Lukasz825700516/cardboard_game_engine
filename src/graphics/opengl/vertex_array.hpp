#pragma once

#include <utility>
namespace cardboard::graphics {
	class VertexArrayPlatformData {
	public:
		explicit VertexArrayPlatformData();
		explicit VertexArrayPlatformData(const VertexArrayPlatformData&) = delete;
		explicit VertexArrayPlatformData(VertexArrayPlatformData&&);
		~VertexArrayPlatformData();

		VertexArrayPlatformData& operator=(VertexArrayPlatformData&&);

		unsigned int vertex_buffer_array;
	};
}
