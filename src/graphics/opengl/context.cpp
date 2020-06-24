#include <glad/glad.h>
#include "../context.hpp"

#include <iostream>


namespace cardboard::graphics {
	ContextInstance* Context::instance = nullptr;

	ContextInstance::ContextInstance() {
		if (!glfwInit()) {
			std::cerr << "Failed to initialize glfw!" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		Context::instance = this;
	}

	ContextInstance::~ContextInstance() {
		glfwTerminate();
	}

	void Context::set_window(Window&& window) {
		instance->window = std::move(window);

		glfwMakeContextCurrent(instance->window.get_data().window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
			std::cerr << "Failed to initialize glad!" << std::endl;
		}

		glad_glViewport(0, 0, instance->window.get_width(), instance->window.get_height());
	
	}

}
