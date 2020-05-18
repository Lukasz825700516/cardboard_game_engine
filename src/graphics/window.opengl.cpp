#include <GLFW/glfw3.h>
#include <iostream>
#include "window.hpp"

namespace cardboard::graphics {
	Window::Window(const char* name, unsigned int width, unsigned int height) {
		data.window = glfwCreateWindow(width, height, name, 0, 0);
		if (!data.window) {
			std::cerr << "Failed to create window!" << std::endl;
		}
	}

	Window::~Window() {
	}

	void Window::destroy() {
		glfwDestroyWindow(data.window);
	}

	void Window::set_name(const char* name) {
	
	}

	void Window::set_size(unsigned int width, unsigned int height) {
	
	}

	int Window::should_close() {
		return glfwWindowShouldClose(this->data.window);
	}
	void Window::poll_events() {
		glfwPollEvents();
	}

	void Window::swap_buffers() {
		glfwSwapBuffers(this->data.window);
	}
}
