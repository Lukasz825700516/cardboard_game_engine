#include "vertex.hpp"


namespace cardboard::graphics {
	Vertex::Vertex():
   		pos(0.0, 0.0), uv(0.0, 0.0) {
	}

	Vertex::Vertex(glm::vec2 pos, glm::vec2 uv):
   		pos(pos), uv(uv) {
	}

	Vertex::Vertex(float pos_x, float pos_y, float uv_x, float uv_y):
   		pos(pos_x,pos_y), uv(uv_x, uv_y) {
	}

	Vertex::Vertex(glm::vec4 posuv):
   		pos(posuv.x, posuv.y), uv(posuv.z, posuv.w) {
	}
}
