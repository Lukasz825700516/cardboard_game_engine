#include "graphics/camera.hpp"
#include <cardboard_imgui.hpp>
#include "graphics/context.hpp"
#include "graphics/shader.hpp"
#include "imgui.h"
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
#include "core/layer.hpp"
#include "core/timer.hpp"

extern "C" {
#include <stb_image.h>
}

namespace cb_g = cardboard::graphics;
namespace cb_r = cardboard::resources;
namespace cb_c = cardboard::core;


class SetupRenderingLayer : public cb_c::Layer {
	cb_g::QuadRendererInstance quad_renderer_instance;
	cb_g::ParticleSystemInstance particle_system_instance;
	double time;
public:

	SetupRenderingLayer():
   		quad_renderer_instance(2000, 2000),
   		particle_system_instance() { }

	void update(float) {
		double current_time = glfwGetTime();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Layer::update(current_time - time);

		cb_g::Context::get_window().swap_buffers();
		cb_g::Context::get_window().poll_events();
		time = current_time;
	}
};

class SetupInputsLayer : public cb_c::Layer {
	cb_r::KeyboardInstance keyboard_instance;
	cb_r::MouseInstance mouse_instance;
public:

	SetupInputsLayer():
   		keyboard_instance(cb_g::Context::get_window()),
   		mouse_instance(cb_g::Context::get_window()) { }

	void update(float) {}
};

class ImGuiLayer : public cb_c::Layer {
public:

	ImGuiLayer() {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(cb_g::Context::get_window().get_data().window, true);
		ImGui_ImplOpenGL3_Init("#version 330 core");
	}

	~ImGuiLayer() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
	}

	void update(float time_delta) {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		Layer::update(time_delta);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
};

class SetupContextLayer : public cb_c::Layer {
	cb_g::ContextInstance context_instance;
public:

	SetupContextLayer() {
		cb_g::Context::set_window(Window("hello world", 800, 600));
	}
};

class DemoLayer : public cb_c::Layer {
	cb_g::Camera camera = cb_g::Camera(glm::vec2(800, 600));
	cb_g::Shader shader_program = cb_g::Shader(
			cb_r::File::read("assets/simple.vertex.glsl")->c_str(),
			cb_r::File::read("assets/simple.fragment.glsl")->c_str());
	cb_g::Texture texture_0 = cb_g::Texture(cb_r::TextureLoader::load_texture("assets/sample.png").value());
	cb_g::Texture texture_1 = cb_g::Texture(cb_r::TextureLoader::load_texture("assets/soup.png").value());
	cb_g::Particle simple_particle_template;
public:
	DemoLayer() {
		simple_particle_template
			.set_life_time(10)
			.set_size(glm::vec2(10), glm::vec2(20))
			.set_color(glm::vec4(1, 0, 0, 1), glm::vec4(0.75, 0.25, 0, 0));

	}

	void update(float time_delta) {
		CARDBOARD_TIMER("update");
		cb_g::ParticleSystem::update(time_delta);

		cb_g::QuadRenderer::create_scene(camera, shader_program);

		cb_g::QuadRenderer::draw({0,0}, {10, 10});

		cb_g::QuadRenderer::flush();

		ImGui::Begin("TEST");
		ImGui::Text("hello world!");
		ImGui::End();
	}
};


int main() {
	std::unique_ptr<cb_c::Layer> root_layer = std::make_unique<SetupContextLayer>();
	root_layer
		->add_layer<SetupRenderingLayer>()
		->add_layer<ImGuiLayer>()
		->add_layer<DemoLayer>();

	while (!cb_g::Context::get_window().should_close()) {
		root_layer->update(0);
	}

	return 0;
}
