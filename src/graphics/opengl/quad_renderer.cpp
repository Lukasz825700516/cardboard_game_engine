#include "../quad_renderer.hpp"
#include "glad/glad.h"
#include "graphics/element_buffer.hpp"
#include "graphics/vertex.hpp"
#include "graphics/vertex_array.hpp"
#include "graphics/vertex_buffer.hpp"
#include <iostream>

namespace cardboard::graphics {
	QuadRendererInstance* QuadRenderer::instance = nullptr;

	QuadRendererInstance::QuadRendererInstance(unsigned int max_vertexes, unsigned int max_elements):
		drawn_vertexes(0),
		drawn_elements(0),
   		max_vertexes(max_vertexes),
		max_elements(max_elements) {

		this->vertex_array.get_vertex_buffer().resize(this->max_vertexes);
		this->vertex_array.get_element_buffer().resize(this->max_elements);

		QuadRenderer::instance = this;
	}

	QuadRendererInstance::QuadRendererInstance(QuadRendererInstance&& renderer):
   		drawn_vertexes(renderer.drawn_vertexes), 
		drawn_elements(renderer.drawn_elements),
		max_vertexes(renderer.max_vertexes),
		max_elements(renderer.max_elements),
   		vertex_array(std::move(renderer.vertex_array)) {}

	QuadRendererInstance::~QuadRendererInstance() {}
	
	void QuadRenderer::create_scene(Camera& camera, Shader& shader) {
		instance->drawn_elements = 0;
		instance->drawn_vertexes = 0;

		instance->last_shader = &shader;
		shader.bind();
		shader.set_uniform(camera.get_transformation(), "camera_transform");
		shader.set_uniform(camera.get_position(), "camera_position");
	}

	void QuadRenderer::reset_scene() {
		instance->drawn_elements = 0;
		instance->drawn_vertexes = 0;
	}

	void QuadRenderer::draw(glm::vec2 position, glm::vec2 size) {
		unsigned int vertexes_to_add = 4;
		unsigned int elements_to_add = 2;

		auto& vb = instance->vertex_array.get_vertex_buffer();
		auto& eb = instance->vertex_array.get_element_buffer();

		bool out_of_memory = 0;
		out_of_memory |= !(instance->drawn_vertexes + vertexes_to_add < instance->max_vertexes);
		out_of_memory |= !(instance->drawn_elements + elements_to_add < instance->max_elements);

		if (out_of_memory) {
			flush();
			reset_scene();
		} 


		vb[instance->drawn_vertexes + 0] =
			Vertex(position, glm::vec2(0, 0));

		vb[instance->drawn_vertexes + 1] =
			Vertex(position + glm::vec2(size.x, 0), glm::vec2(1, 0));

		vb[instance->drawn_vertexes + 2] =
			Vertex(position + glm::vec2(0, size.y), glm::vec2(0, 1));

		vb[instance->drawn_vertexes + 3] =
			Vertex(position + size, glm::vec2(1));

		eb[instance->drawn_elements + 0] = glm::uvec3(
			instance->drawn_vertexes + 0,
			instance->drawn_vertexes + 1,
			instance->drawn_vertexes + 2);

		eb[instance->drawn_elements + 1] = glm::uvec3(
			instance->drawn_vertexes + 3,
			instance->drawn_vertexes + 2,
			instance->drawn_vertexes + 1);

		instance->drawn_vertexes += vertexes_to_add;
		instance->drawn_elements += elements_to_add;
	}

	void QuadRenderer::draw(glm::vec2 position, glm::vec2 size, Texture& texture) {
		unsigned int vertexes_to_add = 4;
		unsigned int elements_to_add = 2;

		auto& vb = instance->vertex_array.get_vertex_buffer();
		auto& eb = instance->vertex_array.get_element_buffer();

		bool out_of_memory = 0;
		out_of_memory |= !(instance->drawn_vertexes + vertexes_to_add < instance->max_vertexes);
		out_of_memory |= !(instance->drawn_elements + elements_to_add < instance->max_elements);
		out_of_memory |= !instance->texture_batch.push(texture);

		if (out_of_memory) {
			flush();
			reset_scene();
		} 

		int texture_id = instance->texture_batch.get(texture);

		vb[instance->drawn_vertexes + 0] =
			Vertex(position, glm::vec2(0, 0), texture_id);

		vb[instance->drawn_vertexes + 1] =
			Vertex(position + glm::vec2(size.x, 0), glm::vec2(1, 0), texture_id);

		vb[instance->drawn_vertexes + 2] =
			Vertex(position + glm::vec2(0, size.y), glm::vec2(0, 1), texture_id);

		vb[instance->drawn_vertexes + 3] =
			Vertex(position + size, glm::vec2(1), texture_id);

		eb[instance->drawn_elements + 0] = glm::uvec3(
			instance->drawn_vertexes + 0,
			instance->drawn_vertexes + 1,
			instance->drawn_vertexes + 2);

		eb[instance->drawn_elements + 1] = glm::uvec3(
			instance->drawn_vertexes + 3,
			instance->drawn_vertexes + 2,
			instance->drawn_vertexes + 1);

		instance->drawn_vertexes += vertexes_to_add;
		instance->drawn_elements += elements_to_add;
	}

	void QuadRenderer::flush() {
		instance->vertex_array.flush();
		instance->texture_batch.flush(*instance->last_shader);
		
		glad_glDrawElements(GL_TRIANGLES, instance->drawn_elements * 3, GL_UNSIGNED_INT, 0);
	}
}
