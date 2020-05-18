#include <glad/glad.h>
#include "context.hpp"

#include <iostream>


namespace cardboard::graphics {
	void Context::initialize() {
		if (!glfwInit()) {
			std::cerr << "Failed to initialize glfw!" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	}

	void Context::set_window(Window window) {
		glfwMakeContextCurrent(window.get_data().window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
			std::cerr << "Failed to initialize glad!" << std::endl;
		}

		glad_glViewport(0, 0, window.get_width(), window.get_height());
	
	}

	void Context::destroy() {
		glfwTerminate();
	}
}
