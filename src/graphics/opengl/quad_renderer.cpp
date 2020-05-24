#include "../quad_renderer.hpp"
#include "glad/glad.h"
#include "graphics/element_buffer.hpp"
#include "graphics/vertex.hpp"
#include "graphics/vertex_array.hpp"
#include "graphics/vertex_buffer.hpp"
#include <GL/gl.h>
#include <glm/fwd.hpp>
#include <memory>
#include <vector>

namespace cardboard::graphics {
	unsigned int QuadRenderer::drawn_vertexes = 0;
	unsigned int QuadRenderer::drawn_elements = 0;
	unsigned int QuadRenderer::max_vertexes = 0;
	unsigned int QuadRenderer::max_elements = 0;
	std::unique_ptr<VertexArray> QuadRenderer::vertex_array;

	void QuadRenderer::initialize(unsigned int max_vertexes, unsigned int max_elements) {
		QuadRenderer::drawn_vertexes = 0;
		QuadRenderer::drawn_elements = 0;
		QuadRenderer::max_vertexes = max_vertexes;
		QuadRenderer::max_elements = max_elements;

		QuadRenderer::vertex_array = std::make_unique<VertexArray>();

		QuadRenderer::vertex_array->get_vertex_buffer().resize(QuadRenderer::max_vertexes);
		QuadRenderer::vertex_array->get_element_buffer().resize(QuadRenderer::max_elements);
	}

	void QuadRenderer::create_scene(Camera& camera, Shader& shader) {
		QuadRenderer::drawn_elements = 0;
		QuadRenderer::drawn_vertexes = 0;

		shader.bind();
		shader.set_uniform(camera.get_transformation(), "camera_transform");
		shader.set_uniform(camera.get_position(), "camera_position");
	}

	void QuadRenderer::reset_scene() {
		QuadRenderer::drawn_elements = 0;
		QuadRenderer::drawn_vertexes = 0;
	}

	void QuadRenderer::draw(glm::vec2 position, glm::vec2 size) {
		unsigned int vertexes_to_add = 4;
		unsigned int elements_to_add = 2;

		auto& vb = QuadRenderer::vertex_array->get_vertex_buffer();
		auto& eb = QuadRenderer::vertex_array->get_element_buffer();

		unsigned int out_of_memory = 0;
		out_of_memory |= !(QuadRenderer::drawn_vertexes + vertexes_to_add < QuadRenderer::max_vertexes);
		out_of_memory |= !(QuadRenderer::drawn_elements + elements_to_add < QuadRenderer::max_elements);

		if (out_of_memory) {
			QuadRenderer::flush();
			QuadRenderer::reset_scene();
		} 

		vb[QuadRenderer::drawn_vertexes + 0] =
			Vertex(position, glm::vec2(0, 0));

		vb[QuadRenderer::drawn_vertexes + 1] =
			Vertex(position + glm::vec2(size.x, 0), glm::vec2(size.x, 0));

		vb[QuadRenderer::drawn_vertexes + 2] =
			Vertex(position + glm::vec2(0, size.y), glm::vec2(0, size.y));

		vb[QuadRenderer::drawn_vertexes + 3] =
			Vertex(position + size, size);

		eb[QuadRenderer::drawn_elements + 0] = glm::uvec3(
			QuadRenderer::drawn_vertexes + 0,
			QuadRenderer::drawn_vertexes + 1,
			QuadRenderer::drawn_vertexes + 2);

		eb[QuadRenderer::drawn_elements + 1] = glm::uvec3(
			QuadRenderer::drawn_vertexes + 3,
			QuadRenderer::drawn_vertexes + 2,
			QuadRenderer::drawn_vertexes + 1);

		QuadRenderer::drawn_vertexes += vertexes_to_add;
		QuadRenderer::drawn_elements += elements_to_add;
	}

	void QuadRenderer::flush() {
		QuadRenderer::vertex_array->bind();
		QuadRenderer::vertex_array->flush();
		
		glad_glDrawElements(GL_TRIANGLES, QuadRenderer::drawn_elements * 3, GL_UNSIGNED_INT, 0);
	
	}
}
