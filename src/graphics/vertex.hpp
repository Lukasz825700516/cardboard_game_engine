#pragma once

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
namespace cardboard::graphics {
	class Vertex {
		public:
		glm::vec2 pos;
		glm::vec2 uv;

		Vertex();
		Vertex(glm::vec2 pos, glm::vec2 uv);
		Vertex(float pos_x, float pos_y, float ux_x, float uv_y);
		Vertex(glm::vec4 posuv);
	};
}
