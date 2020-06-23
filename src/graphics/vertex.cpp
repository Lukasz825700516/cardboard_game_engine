#include "vertex.hpp"


namespace cardboard::graphics {
	Vertex::Vertex():
   		pos(0.0, 0.0),
		uv(0.0, 0.0),
   		texture_id(0) {
	}

	Vertex::Vertex(glm::vec2 pos, glm::vec2 uv):
   		pos(pos),
		uv(uv),
		texture_id(0) {
	}

	Vertex::Vertex(glm::vec2 pos, glm::vec2 uv, int texture_id):
   		pos(pos),
		uv(uv),
		texture_id(texture_id) {
	}

	Vertex::Vertex(float pos_x, float pos_y, float uv_x, float uv_y):
   		pos(pos_x,pos_y),
		uv(uv_x, uv_y),
	    texture_id(0) {
	}

	Vertex::Vertex(float pos_x, float pos_y, float uv_x, float uv_y, int texture_id):
   		pos(pos_x,pos_y),
		uv(uv_x, uv_y),
		texture_id(texture_id) {
	}

	Vertex::Vertex(glm::vec4 posuv):
   		pos(posuv.x, posuv.y),
		uv(posuv.z, posuv.w),
   		texture_id(0) {
	}

	Vertex::Vertex(glm::vec4 posuv, int texture_id):
   		pos(posuv.x, posuv.y),
		uv(posuv.z, posuv.w),
   		texture_id(texture_id) {
	}
}
