#pragma once

#include <utility>
namespace cardboard::graphics {
	class VertexArrayPlatformData {
	public:
		unsigned int vertex_buffer_array;

		VertexArrayPlatformData();
		VertexArrayPlatformData(VertexArrayPlatformData&& data);
		~VertexArrayPlatformData();
	};
}
