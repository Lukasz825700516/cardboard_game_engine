#pragma once

#include "graphics/vertex_array.hpp"
#include <glm/glm.hpp>
#include <memory>
#include "camera.hpp"
#include "shader.hpp"

namespace cardboard::graphics {
	class QuadRenderer {
	private:
		unsigned int drawn_vertexes;
		unsigned int drawn_elements;

		unsigned int max_vertexes;
		unsigned int max_elements;

		VertexArray vertex_array;

	public:
		QuadRenderer(unsigned int max_vertexes, unsigned int max_elements);
		QuadRenderer(QuadRenderer&& renderer);
		~QuadRenderer();

		void create_scene(Camera& camera, Shader& shader);
		void reset_scene();
		void draw(glm::vec2 position, glm::vec2 size);
		void flush();
	};
}
