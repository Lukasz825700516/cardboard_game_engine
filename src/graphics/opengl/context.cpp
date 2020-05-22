#include <glad/glad.h>
#include "../context.hpp"

#include <iostream>


namespace cardboard::graphics {
	Context::Context() {
		if (!glfwInit()) {
			std::cerr << "Failed to initialize glfw!" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	}

	Context::~Context() {
		glfwTerminate();
	}

	void Context::set_window(Window&& window) {
		this->window = std::move(window);

		glfwMakeContextCurrent(this->window.get_data().window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
			std::cerr << "Failed to initialize glad!" << std::endl;
		}

		glad_glViewport(0, 0, this->window.get_width(), this->window.get_height());
	
	}

}
