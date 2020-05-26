#include <glm/fwd.hpp>

#include "graphics/camera.hpp"
#include "graphics/context.hpp"
#include "graphics/shader.hpp"
#include "graphics/window.hpp"
#include "resources/file.hpp"
#include "resources/keyboard.hpp"
#include "resources/mouse.hpp"
#include "graphics/quad_renderer.hpp"
#include <cmath>

using cardboard::graphics::Context;
using cardboard::graphics::Window;
using cardboard::graphics::Shader;
using cardboard::graphics::QuadRenderer;
using cardboard::resources::File;
using cardboard::graphics::Camera;
using cardboard::resources::Keyboard;
using cardboard::resources::KeyboardKey;
using cardboard::resources::Mouse;
using cardboard::resources::MouseKey;

int main() {
	Context ctx;
	ctx.set_window(Window("hello world", 800, 600));

	Shader shader_program(
		File::read("assets/simple.vertex.glsl")->c_str(),
		File::read("assets/simple.fragment.glsl")->c_str());

	QuadRenderer renderer(1000, 1000);
	Camera camera(glm::vec2(800, 600));
	Keyboard keyboard(ctx.get_window());
	Mouse mouse(ctx.get_window());
	
	float time = 0;
	glm::vec2 position = glm::vec2(0.0);
	glm::vec2 last_mouse_position = glm::vec2(0.0);

    while (!ctx.get_window().should_close()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		glm::vec2 mouse_position = mouse.get_position();

		if (keyboard.is_key_pressed(KeyboardKey::CARDBOARD_KEYBOARD_LEFT))
			position.x -= 10;
		if (keyboard.is_key_pressed(KeyboardKey::CARDBOARD_KEYBOARD_RIGHT))
			position.x += 10;
		if (keyboard.is_key_pressed(KeyboardKey::CARDBOARD_KEYBOARD_UP)) 
			position.y += 10;
		if (keyboard.is_key_pressed(KeyboardKey::CARDBOARD_KEYBOARD_DOWN)) 
			position.y -= 10;

		if (mouse.is_button_pressed(MouseKey::CARDBOARD_MOUSE_LEFT)) {
			position += (mouse_position - last_mouse_position) * 2.0f;
		}

		last_mouse_position = mouse_position;


		camera.set_position(position);
		renderer.create_scene(camera, shader_program);
		for (float x = -800; x < 800; x += 100) {
			for (float y = -600; y < 600; y += 100) {
				renderer.draw(glm::vec2(x, y), glm::vec2(80));
			}
		}
		renderer.flush();

		ctx.get_window().swap_buffers();
		ctx.get_window().poll_events();

		time += 1;
    }
    return 0;
}
