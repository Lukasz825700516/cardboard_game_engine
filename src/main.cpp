#include "graphics/camera.hpp"
#include "graphics/context.hpp"
#include "graphics/shader.hpp"
#include "resources/file.hpp"
#include "resources/keyboard.hpp"
#include "resources/mouse.hpp"
#include "graphics/quad_renderer.hpp"
#include "graphics/texture.hpp"
#include "graphics/particle_system.hpp"
#include <cmath>
#include <vector>
#include <iostream>
#include "resources/texture_loader.hpp"

extern "C" {
#include <stb_image.h>
}

namespace cb_g = cardboard::graphics;
namespace cb_r = cardboard::resources;

int main() {
	cb_g::ContextInstance context_instance;
	cb_g::Context::set_window(Window("hello world", 800, 600));

	cb_r::KeyboardInstance keyboard_instance(cb_g::Context::get_window());
	cb_r::MouseInstance mouse_instance(cb_g::Context::get_window());
	cb_g::QuadRendererInstance quad_renderer_instance(1000, 1000);
	cb_g::ParticleSystemInstance particle_system_instance;

	cb_g::Camera camera(glm::vec2(800, 600));
	cb_g::Shader shader_program(
			cb_r::File::read("assets/simple.vertex.glsl")->c_str(),
			cb_r::File::read("assets/simple.fragment.glsl")->c_str());
	cb_g::Texture texture_0(cb_r::TextureLoader::load_texture("assets/sample.png").value());
	cb_g::Texture texture_1(cb_r::TextureLoader::load_texture("assets/soup.png").value());
	float time = 0;
	glm::vec2 position = glm::vec2(400, 300);
	glm::vec2 last_mouse_position = glm::vec2(0.0);


	while (!cb_g::Context::get_window().should_close()) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Keyboard camera movement
		if (cb_r::Keyboard::is_key_pressed(cb_r::KeyboardKey::CARDBOARD_KEYBOARD_LEFT))
			position.x -= 10;
		if (cb_r::Keyboard::is_key_pressed(cb_r::KeyboardKey::CARDBOARD_KEYBOARD_RIGHT))
			position.x += 10;
		if (cb_r::Keyboard::is_key_pressed(cb_r::KeyboardKey::CARDBOARD_KEYBOARD_UP)) 
			position.y += 10;
		if (cb_r::Keyboard::is_key_pressed(cb_r::KeyboardKey::CARDBOARD_KEYBOARD_DOWN)) 
			position.y -= 10;

		// Mouse camera movement
		glm::vec2 mouse_position = cb_r::Mouse::get_position();
		if (cb_r::Mouse::is_button_pressed(cb_r::MouseKey::CARDBOARD_MOUSE_LEFT)) {
			position += mouse_position - last_mouse_position;
		}
		last_mouse_position = mouse_position;

		// Update something
		cb_g::ParticleSystem::summon(glm::vec2(std::sin(time), std::cos(time)) * 10.0f, glm::vec2(std::sin(time) * 2.0f, 10), glm::vec2(0, std::cos(time) + 1) / 2.0f, 10);
		cb_g::ParticleSystem::summon(glm::vec2(std::sin(time), std::cos(time)) * 10.0f + glm::vec2(80, 0), glm::vec2(std::sin(time) * 2.0f, 10), glm::vec2(0, std::cos(time) + 1) / 2.0f, 10);
		cb_g::ParticleSystem::update(0.1);

		// Render something
		camera.set_position(position);
		cb_g::QuadRenderer::create_scene(camera, shader_program);

		cb_g::QuadRenderer::draw(glm::vec2(10, 10), glm::vec2(80, 220), texture_0);
		cb_g::QuadRenderer::draw(glm::vec2(800 - (80 + 10), 600 - (220 + 10)), glm::vec2(80, 220), texture_0);
		cb_g::QuadRenderer::draw(glm::vec2(400, 300), glm::vec2(200, 200), texture_1);

		cb_g::ParticleSystem::draw<cb_g::QuadRenderer>();

		// Flush everything to gpu
		cb_g::QuadRenderer::flush();

		cb_g::Context::get_window().swap_buffers();
		cb_g::Context::get_window().poll_events();

		time += 1;
	}
	return 0;
}
