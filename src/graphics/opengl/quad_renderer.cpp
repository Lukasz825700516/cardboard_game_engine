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

	void QuadRenderer::create_scene(Camera& camera, Shader& shader) {
		instance->drawn_elements = 0;
		instance->drawn_vertexes = 0;

		instance->last_shader = &shader;
		shader.bind();
		shader.set_uniform(camera.get_transformation(), "camera_transform");
		shader.set_uniform(camera.get_position(), "camera_position");

		glad_glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

		Vertex base;
		{
			Vertex v(base);
				v.pos = position - size / 2.0f;
				v.uv = glm::vec2(0, 0);
			vb[instance->drawn_vertexes + 0] = v;
		}{
			Vertex v(base);
				v.pos = position + glm::vec2(size.x, -size.y) / 2.0f;
				v.uv = glm::vec2(1, 0);
			vb[instance->drawn_vertexes + 1] = v;
		}{
			Vertex v(base);
				v.pos = position + glm::vec2(-size.x, size.y) / 2.0f;
				v.uv = glm::vec2(0, 1);
			vb[instance->drawn_vertexes + 2] = v;
		}{
			Vertex v(base);
				v.pos = position + size / 2.0f;
				v.uv = glm::vec2(1, 1);
			vb[instance->drawn_vertexes + 3] = v;
		}

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

		Vertex base;
		base.texture_id = texture_id;
		{
			Vertex v(base);
				v.pos = position - size / 2.0f;
				v.uv = glm::vec2(0, 0);
			vb[instance->drawn_vertexes + 0] = v;
		}{
			Vertex v(base);
				v.pos = position + glm::vec2(size.x, -size.y) / 2.0f;
				v.uv = glm::vec2(1, 0);
			vb[instance->drawn_vertexes + 1] = v;
		}{
			Vertex v(base);
				v.pos = position + glm::vec2(-size.x, size.y) / 2.0f;
				v.uv = glm::vec2(0, 1);
			vb[instance->drawn_vertexes + 2] = v;
		}{
			Vertex v(base);
				v.pos = position + size / 2.0f;
				v.uv = glm::vec2(1, 1);
			vb[instance->drawn_vertexes + 3] = v;
		}

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

	void QuadRenderer::draw(glm::vec2 position, glm::vec2 size, Texture& texture, glm::vec4 color) {
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

		Vertex base;
		base.texture_id = texture_id;
		base.color = color;
		{
			Vertex v(base);
				v.pos = position - size / 2.0f;
				v.uv = glm::vec2(0, 0);
			vb[instance->drawn_vertexes + 0] = v;
		}{
			Vertex v(base);
				v.pos = position + glm::vec2(size.x, -size.y) / 2.0f;
				v.uv = glm::vec2(1, 0);
			vb[instance->drawn_vertexes + 1] = v;
		}{
			Vertex v(base);
				v.pos = position + glm::vec2(-size.x, size.y) / 2.0f;
				v.uv = glm::vec2(0, 1);
			vb[instance->drawn_vertexes + 2] = v;
		}{
			Vertex v(base);
				v.pos = position + size / 2.0f;
				v.uv = glm::vec2(1, 1);
			vb[instance->drawn_vertexes + 3] = v;
		}

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

	void QuadRenderer::draw_rotated(glm::vec2 position, glm::vec2 size, float angle) {
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

		float to_radians = M_PI / 180.0f;
		glm::mat2 rotation(
			glm::vec2(std::cos(angle * to_radians), -std::sin(angle * to_radians)),
			glm::vec2(std::sin(angle * to_radians), std::cos(angle * to_radians))
		);

		Vertex base;
		{
			Vertex v(base);
				v.pos = position + rotation * -size / 2.0f;
				v.uv = glm::vec2(0, 0);
			vb[instance->drawn_vertexes + 0] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * glm::vec2(size.x, -size.y) / 2.0f;
				v.uv = glm::vec2(1, 0);
			vb[instance->drawn_vertexes + 1] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * glm::vec2(-size.x, size.y) / 2.0f;
				v.uv = glm::vec2(0, 1);
			vb[instance->drawn_vertexes + 2] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * size / 2.0f;
				v.uv = glm::vec2(1, 1);
			vb[instance->drawn_vertexes + 3] = v;
		}

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

	void QuadRenderer::draw_rotated(glm::vec2 position, glm::vec2 size, float angle, Texture& texture) {
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

		float to_radians = M_PI / 180.0f;
		glm::mat2 rotation(
			glm::vec2(std::cos(angle * to_radians), -std::sin(angle * to_radians)),
			glm::vec2(std::sin(angle * to_radians), std::cos(angle * to_radians))
		);

		int texture_id = instance->texture_batch.get(texture);

		Vertex base;
		base.texture_id = texture_id;
		{
			Vertex v(base);
				v.pos = position + rotation * -size / 2.0f;
				v.uv = glm::vec2(0, 0);
			vb[instance->drawn_vertexes + 0] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * glm::vec2(size.x, -size.y) / 2.0f;
				v.uv = glm::vec2(1, 0);
			vb[instance->drawn_vertexes + 1] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * glm::vec2(-size.x, size.y) / 2.0f;
				v.uv = glm::vec2(0, 1);
			vb[instance->drawn_vertexes + 2] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * size / 2.0f;
				v.uv = glm::vec2(1, 1);
			vb[instance->drawn_vertexes + 3] = v;
		}

		eb[instance->drawn_elements + 0] = glm::uvec3(
				instance->drawn_vertexes + 0,
				instance->drawn_vertexes + 1,
				instance->drawn_vertexes + 2);

		eb[instance->drawn_elements + 1] = glm::uvec3(
				instance->drawn_vertexes + 3,
				instance->drawn_vertexes + 2,
				instance->drawn_vertexes + 1);

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

	void QuadRenderer::draw_rotated(glm::vec2 position, glm::vec2 size, float angle, Texture& texture, glm::vec4 color) {
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

		float to_radians = M_PI / 180.0f;
		glm::mat2 rotation(
			glm::vec2(std::cos(angle * to_radians), -std::sin(angle * to_radians)),
			glm::vec2(std::sin(angle * to_radians), std::cos(angle * to_radians))
		);

		int texture_id = instance->texture_batch.get(texture);

		Vertex base;
		base.texture_id = texture_id;
		base.color = color;
		{
			Vertex v(base);
				v.pos = position + rotation * -size / 2.0f;
				v.uv = glm::vec2(0, 0);
			vb[instance->drawn_vertexes + 0] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * glm::vec2(size.x, -size.y) / 2.0f;
				v.uv = glm::vec2(1, 0);
			vb[instance->drawn_vertexes + 1] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * glm::vec2(-size.x, size.y) / 2.0f;
				v.uv = glm::vec2(0, 1);
			vb[instance->drawn_vertexes + 2] = v;
		}{
			Vertex v(base);
				v.pos = position + rotation * size / 2.0f;
				v.uv = glm::vec2(1, 1);
			vb[instance->drawn_vertexes + 3] = v;
		}

		eb[instance->drawn_elements + 0] = glm::uvec3(
				instance->drawn_vertexes + 0,
				instance->drawn_vertexes + 1,
				instance->drawn_vertexes + 2);

		eb[instance->drawn_elements + 1] = glm::uvec3(
				instance->drawn_vertexes + 3,
				instance->drawn_vertexes + 2,
				instance->drawn_vertexes + 1);

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
