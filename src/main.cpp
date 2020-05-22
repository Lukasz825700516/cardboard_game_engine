#include <glm/fwd.hpp>

#include <iostream>
#include <vector>
#include "graphics/context.hpp"
#include "graphics/shader.hpp"
#include "graphics/window.hpp"
#include "resources/file.hpp"
#include "graphics/quad_renderer.hpp"

using cardboard::graphics::Context;
using cardboard::graphics::Window;
using cardboard::graphics::Shader;
using cardboard::graphics::QuadRenderer;
using cardboard::resources::File;

int main() {
	Context ctx;
	ctx.set_window(Window("hello world", 800, 600));

	Shader shader_program(
		File::read("assets/simple.vertex.glsl")->c_str(),
		File::read("assets/simple.fragment.glsl")->c_str());

	QuadRenderer::initialize(1000, 1000);

    while (!ctx.get_window().should_close()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		shader_program.bind();

		QuadRenderer::create_batch();
		for (float x = -1; x < 1; x += 0.1) {
			for (float y = -1; y < 1; y += 0.1) {
				QuadRenderer::draw(glm::vec2(x, y), glm::vec2(0.08, 0.08));
			}
		}
		QuadRenderer::flush();

		ctx.get_window().swap_buffers();
		ctx.get_window().poll_events();
    }
    return 0;
}
