#include <iostream>
#include <vector>
#include "graphics/context.hpp"
#include "graphics/element_buffer.hpp"
#include "graphics/mesh.hpp"
#include "graphics/shader.hpp"
#include "graphics/vertex.hpp"
#include "graphics/vertex_buffer.hpp"
#include "graphics/window.hpp"
#include "resources/file.hpp"

int main()
{
	cardboard::graphics::Context::initialize();
	cardboard::graphics::Window win("hello", 800, 600);
	cardboard::graphics::Context::set_window(win);

	cardboard::graphics::Shader shader_program(
		cardboard::resources::File::load_file_content("assets/simple.vertex.glsl")->c_str(),
		cardboard::resources::File::load_file_content("assets/simple.fragment.glsl")->c_str()
		);

	std::vector<cardboard::graphics::Vertex> vertexes = {
		cardboard::graphics::Vertex(0, 0, 0, 0),
		cardboard::graphics::Vertex(0, 1, 0, 1),
		cardboard::graphics::Vertex(1, 0, 1, 0),
		cardboard::graphics::Vertex(1, 1, 1, 1),
	};

	std::vector<glm::uvec3> elements = {
		glm::uvec3(0, 1, 2),
		glm::uvec3(3, 2, 1),
	};

	cardboard::graphics::VertexBuffer vb(vertexes);
	cardboard::graphics::ElementBuffer eb(elements);
	cardboard::graphics::Mesh mesh(vb, eb);

    while (!win.should_close())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		shader_program.bind();
		mesh.bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		win.swap_buffers();
		win.poll_events();
    }

	cardboard::graphics::Context::destroy();
    return 0;
}
