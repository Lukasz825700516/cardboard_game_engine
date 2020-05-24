#pragma once

#include "graphics/vertex_array.hpp"
#include <glm/glm.hpp>
#include <memory>
#include "camera.hpp"
#include "shader.hpp"

namespace cardboard::graphics {
	class QuadRenderer {
	private:
		static unsigned int drawn_vertexes;
		static unsigned int drawn_elements;

		static unsigned int max_vertexes;
		static unsigned int max_elements;

		static std::unique_ptr<VertexArray> vertex_array;

	public:
		static void initialize(unsigned int max_vertexes, unsigned int max_elements);
		static void create_scene(Camera& camera, Shader& shader);
		static void reset_scene();
		static void draw(glm::vec2 position, glm::vec2 size);
		static void flush();
	};
}
