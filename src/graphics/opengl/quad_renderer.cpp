#include "../quad_renderer.hpp"
#include "glad/glad.h"
#include "graphics/element_buffer.hpp"
#include "graphics/vertex.hpp"
#include "graphics/vertex_array.hpp"
#include "graphics/vertex_buffer.hpp"

namespace cardboard::graphics {
	QuadRenderer::QuadRenderer(unsigned int max_vertexes, unsigned int max_elements):
		drawn_vertexes(0),
		drawn_elements(0),
   		max_vertexes(max_vertexes),
		max_elements(max_elements) {

		this->vertex_array.get_vertex_buffer().resize(this->max_vertexes);
		this->vertex_array.get_element_buffer().resize(this->max_elements);
	}

	QuadRenderer::QuadRenderer(QuadRenderer&& renderer):
   		drawn_vertexes(renderer.drawn_vertexes), 
		drawn_elements(renderer.drawn_elements),
		max_vertexes(renderer.max_vertexes),
		max_elements(renderer.max_elements),
   		vertex_array(std::move(renderer.vertex_array)) {}

	QuadRenderer::~QuadRenderer() {}
	
	void QuadRenderer::create_scene(Camera& camera, Shader& shader) {
		this->drawn_elements = 0;
		this->drawn_vertexes = 0;

		shader.bind();
		shader.set_uniform(camera.get_transformation(), "camera_transform");
		shader.set_uniform(camera.get_position(), "camera_position");
	}

	void QuadRenderer::reset_scene() {
		this->drawn_elements = 0;
		this->drawn_vertexes = 0;
	}

	void QuadRenderer::draw(glm::vec2 position, glm::vec2 size) {
		unsigned int vertexes_to_add = 4;
		unsigned int elements_to_add = 2;

		auto& vb = this->vertex_array.get_vertex_buffer();
		auto& eb = this->vertex_array.get_element_buffer();

		unsigned int out_of_memory = 0;
		out_of_memory |= !(this->drawn_vertexes + vertexes_to_add < this->max_vertexes);
		out_of_memory |= !(this->drawn_elements + elements_to_add < this->max_elements);

		if (out_of_memory) {
			this->flush();
			this->reset_scene();
		} 

		vb[this->drawn_vertexes + 0] =
			Vertex(position, glm::vec2(0, 0));

		vb[this->drawn_vertexes + 1] =
			Vertex(position + glm::vec2(size.x, 0), glm::vec2(size.x, 0));

		vb[this->drawn_vertexes + 2] =
			Vertex(position + glm::vec2(0, size.y), glm::vec2(0, size.y));

		vb[this->drawn_vertexes + 3] =
			Vertex(position + size, size);

		eb[this->drawn_elements + 0] = glm::uvec3(
			this->drawn_vertexes + 0,
			this->drawn_vertexes + 1,
			this->drawn_vertexes + 2);

		eb[this->drawn_elements + 1] = glm::uvec3(
			this->drawn_vertexes + 3,
			this->drawn_vertexes + 2,
			this->drawn_vertexes + 1);

		this->drawn_vertexes += vertexes_to_add;
		this->drawn_elements += elements_to_add;
	}

	void QuadRenderer::flush() {
		this->vertex_array.bind();
		this->vertex_array.flush();
		
		glad_glDrawElements(GL_TRIANGLES, this->drawn_elements * 3, GL_UNSIGNED_INT, 0);
	
	}
}
