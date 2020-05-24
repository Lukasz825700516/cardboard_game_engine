#include <glm/fwd.hpp>

#include <iostream>
#include <vector>
#include "graphics/camera.hpp"
#include "graphics/context.hpp"
#include "graphics/shader.hpp"
#include "graphics/window.hpp"
#include "resources/file.hpp"
#include "graphics/quad_renderer.hpp"
#include <cmath>

using cardboard::graphics::Context;
using cardboard::graphics::Window;
using cardboard::graphics::Shader;
using cardboard::graphics::QuadRenderer;
using cardboard::resources::File;
using cardboard::graphics::Camera;

int main() {
	Context ctx;
	ctx.set_window(Window("hello world", 800, 600));

	Shader shader_program(
		File::read("assets/simple.vertex.glsl")->c_str(),
		File::read("assets/simple.fragment.glsl")->c_str());

	QuadRenderer::initialize(1000, 1000);
	Camera camera(glm::vec2(800, 600));
	
	float time = 0;

    while (!ctx.get_window().should_close()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		QuadRenderer::create_scene(camera, shader_program);
		for (float x = 0; x < 800; x += 100) {
			for (float y = 0; y < 600; y += 100) {
				QuadRenderer::draw(glm::vec2(x + std::cos(time / 10) * 300, y), glm::vec2(80));
			}
		}
		QuadRenderer::flush();

		ctx.get_window().swap_buffers();
		ctx.get_window().poll_events();

		time += 1;
    }
    return 0;
}
