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

		QuadRendererInstance(unsigned int, unsigned int);
		QuadRendererInstance(QuadRendererInstance&&);
		~QuadRendererInstance();
	};

	class QuadRenderer {
	public:
		static QuadRendererInstance* instance;

		static void create_scene(Camera&, Shader&);
		static void reset_scene();
		static void draw(glm::vec2, glm::vec2);
		static void draw(glm::vec2, glm::vec2, Texture&);
		static void flush();
	};
}
