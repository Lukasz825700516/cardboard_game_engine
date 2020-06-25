#pragma once

#include "glm/fwd.hpp"
#include "graphics/vertex_array.hpp"
#include <glm/glm.hpp>
#include <memory>
#include "camera.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "texture_batch.hpp"

namespace cardboard::graphics {
	class QuadRendererInstance {
	public:
		unsigned int drawn_vertexes;
		unsigned int drawn_elements;

		unsigned int max_vertexes;
		unsigned int max_elements;

		VertexArray vertex_array;
		TextureBatch texture_batch;

		Shader* last_shader;

		explicit QuadRendererInstance() = delete;
		explicit QuadRendererInstance(QuadRendererInstance&) = delete;
		explicit QuadRendererInstance(QuadRendererInstance&&) = default;
		~QuadRendererInstance() = default;

		explicit QuadRendererInstance(unsigned int, unsigned int);
	};

	class QuadRenderer {
	public:
		static QuadRendererInstance* instance;

		static void create_scene(Camera&, Shader&);
		static void reset_scene();
		static void draw(glm::vec2, glm::vec2);
		static void draw(glm::vec2, glm::vec2, Texture&);
		static void draw(glm::vec2, glm::vec2, Texture&, glm::vec4);
		static void draw_rotated(glm::vec2, glm::vec2, float);
		static void draw_rotated(glm::vec2, glm::vec2, float, Texture&);
		static void draw_rotated(glm::vec2, glm::vec2, float, Texture&, glm::vec4);
		static void flush();
	};
}
