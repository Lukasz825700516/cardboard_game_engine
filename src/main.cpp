#include <glm/fwd.hpp>

#include <iostream>
#include <vector>
#include "graphics/context.hpp"
#include "graphics/shader.hpp"
#include "graphics/window.hpp"
#include "resources/file.hpp"
#include "graphics/quad_renderer.hpp"

int main() {
	cardboard::graphics::Context::initialize();
	cardboard::graphics::Window win("hello", 800, 600);
	cardboard::graphics::Context::set_window(win);

	cardboard::graphics::Shader shader_program(
		cardboard::resources::File::read("assets/simple.vertex.glsl")->c_str(),
		cardboard::resources::File::read("assets/simple.fragment.glsl")->c_str());

	cardboard::graphics::QuadRenderer::initialize(1000, 1000);

    while (!win.should_close())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		shader_program.bind();

		cardboard::graphics::QuadRenderer::create_batch();
		for (float x = -1; x < 1; x += 0.01) {
			for (float y = -1; y < 1; y += 0.01) {
				cardboard::graphics::QuadRenderer::draw(glm::vec2(x, y), glm::vec2(0.008, 0.008));
			}
		}
		cardboard::graphics::QuadRenderer::flush();

		win.swap_buffers();
		win.poll_events();
    }

	cardboard::graphics::Context::destroy();
    return 0;
}
