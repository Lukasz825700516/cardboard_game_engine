#include <glm/fwd.hpp>

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

using cardboard::graphics::Context;
using cardboard::resources::Window;
using cardboard::graphics::Shader;
using cardboard::graphics::QuadRenderer;
using cardboard::graphics::QuadRendererInstance;
using cardboard::graphics::Texture;
using cardboard::resources::File;
using cardboard::graphics::Camera;
using cardboard::resources::Keyboard;
using cardboard::resources::KeyboardKey;
using cardboard::resources::Mouse;
using cardboard::resources::MouseKey;
using cardboard::resources::TextureLoader;
using cardboard::graphics::ParticleSystem;
using cardboard::graphics::ParticleSystemInstance;

int main() {
	Context ctx;
	ctx.set_window(Window("hello world", 800, 600));

	Shader shader_program(
			File::read("assets/simple.vertex.glsl")->c_str(),
			File::read("assets/simple.fragment.glsl")->c_str());

	QuadRendererInstance quad_renderer_instance(1000, 1000);
	Camera camera(glm::vec2(800, 600));
	Keyboard keyboard(ctx.get_window());
	Mouse mouse(ctx.get_window());

	float time = 0;
	glm::vec2 position = glm::vec2(400, 300);
	glm::vec2 last_mouse_position = glm::vec2(0.0);

	Texture texture_0(TextureLoader::load_texture("assets/sample.png").value());
	Texture texture_1(TextureLoader::load_texture("assets/soup.png").value());
	ParticleSystemInstance particle_system_instance;


	while (!ctx.get_window().should_close()) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Keyboard camera movement
		if (keyboard.is_key_pressed(KeyboardKey::CARDBOARD_KEYBOARD_LEFT))
			position.x -= 10;
		if (keyboard.is_key_pressed(KeyboardKey::CARDBOARD_KEYBOARD_RIGHT))
			position.x += 10;
		if (keyboard.is_key_pressed(KeyboardKey::CARDBOARD_KEYBOARD_UP)) 
			position.y += 10;
		if (keyboard.is_key_pressed(KeyboardKey::CARDBOARD_KEYBOARD_DOWN)) 
			position.y -= 10;

		// Mouse camera movement
		glm::vec2 mouse_position = mouse.get_position();
		if (mouse.is_button_pressed(MouseKey::CARDBOARD_MOUSE_LEFT)) {
			position += mouse_position - last_mouse_position;
		}
		last_mouse_position = mouse_position;

		// Update something
		ParticleSystem::summon(glm::vec2(std::sin(time), std::cos(time)) * 10.0f, glm::vec2(std::sin(time) * 2.0f, 10), glm::vec2(0, std::cos(time) + 1) / 2.0f, 10);
		ParticleSystem::summon(glm::vec2(std::sin(time), std::cos(time)) * 10.0f + glm::vec2(80, 0), glm::vec2(std::sin(time) * 2.0f, 10), glm::vec2(0, std::cos(time) + 1) / 2.0f, 10);
		ParticleSystem::update(0.1);

		// Render something
		camera.set_position(position);
		QuadRenderer::create_scene(camera, shader_program);

		QuadRenderer::draw(glm::vec2(10, 10), glm::vec2(80, 220), texture_0);
		QuadRenderer::draw(glm::vec2(800 - (80 + 10), 600 - (220 + 10)), glm::vec2(80, 220), texture_0);
		QuadRenderer::draw(glm::vec2(400, 300), glm::vec2(200, 200), texture_1);

		ParticleSystem::draw<QuadRenderer>();

		// Flush everything to gpu
		QuadRenderer::flush();

		ctx.get_window().swap_buffers();
		ctx.get_window().poll_events();

		time += 1;
	}
	return 0;
}
