#include "glad/glad.h"
#include "graphics/context.hpp"
#include "graphics/element_buffer.opengl.hpp"
#include "graphics/shader.hpp"
#include "graphics/vertex.hpp"
#include "graphics/vertex_buffer.hpp"
#include "graphics/element_buffer.hpp"
#include "graphics/window.hpp"
#include "resources/file.hpp"
#include <array>
#include <iostream>
#include <utility>
#include <vector>

using cardboard::graphics::Context;
using cardboard::graphics::Window;
using cardboard::graphics::Shader;
using cardboard::resources::File;
using cardboard::graphics::Vertex;
using cardboard::graphics::VertexBuffer;
using cardboard::graphics::ElementBuffer;

int main() {
	std::cout << "Hello world!" << std::endl;

	Context::initialize();
	Window game_window("Hello", 800, 600);
	Context::set_window(game_window);

	Shader simple_shader(
		File::load_file_content("assets/simple.vertex.glsl").value().c_str(),
		File::load_file_content("assets/simple.fragment.glsl").value().c_str());

	std::vector<Vertex> buffer;
	buffer.push_back(Vertex(0, 0, 0, 0));
	buffer.push_back(Vertex(0, 1, 0, 1));
	buffer.push_back(Vertex(1, 0, 1, 0));
	buffer.push_back(Vertex(1, 1, 1, 1));

	std::vector<glm::uvec3> elements;
	elements.push_back(glm::uvec3(0, 1, 2));
	elements.push_back(glm::uvec3(1, 3, 2));

	unsigned int vao;
	glad_glGenVertexArrays(1, &vao);
	glad_glBindVertexArray(vao);

	VertexBuffer vb(std::move(buffer));
	ElementBuffer eb(std::move(elements));
	
	vb.load();
	eb.load();



	while (!game_window.should_close()) {
		simple_shader.bind();
		vb.bind();
		eb.bind();

		glad_glClearColor(0.5, 0.3, 0.8, 1);
		glad_glClear(GL_COLOR_BUFFER_BIT);

		glad_glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		game_window.swap_buffers();
		Window::poll_events();
	}

	vb.unload();
	simple_shader.destroy();
	game_window.destroy();
	Context::destroy();
	return 0;
}
