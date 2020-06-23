#pragma once

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
namespace cardboard::graphics {
	class Vertex {
		public:
		glm::vec2 pos;
		glm::vec2 uv;
		int texture_id;

		Vertex();
		Vertex(glm::vec2 pos, glm::vec2 uv);
		Vertex(glm::vec2 pos, glm::vec2 uv, int texture_id);
		Vertex(float pos_x, float pos_y, float ux_x, float uv_y);
		Vertex(float pos_x, float pos_y, float ux_x, float uv_y, int texture_id);
		Vertex(glm::vec4 posuv);
		Vertex(glm::vec4 posuv, int texture_id);
	};
}
