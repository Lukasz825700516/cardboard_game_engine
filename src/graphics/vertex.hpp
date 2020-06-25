#pragma once

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
namespace cardboard::graphics {
	class Vertex {
	public:
		explicit Vertex() = default;
		explicit Vertex(const Vertex&) = default;
		explicit Vertex(Vertex&&) = default;
		~Vertex() = default;

		Vertex& operator=(const Vertex&) = default;
		Vertex& operator=(Vertex&&) = default;

		glm::vec2 pos = glm::vec2(0);
		glm::vec2 uv = glm::vec2(0);
		int texture_id = 0;
		glm::vec4 color = glm::vec4(1);
	};
}
