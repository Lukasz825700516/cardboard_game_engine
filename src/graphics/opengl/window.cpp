#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>
#include <utility>
#include "../window.hpp"
#include "graphics/opengl/window.hpp"
namespace cardboard::graphics {
	WindowPlatformData::WindowPlatformData() {}
	WindowPlatformData::WindowPlatformData(const char* name, unsigned int width,unsigned int height) {
		this->window = glfwCreateWindow(width, height, name, 0, 0);
		if (!this->window) {
			std::cerr << "Failed to create window!" << std::endl;
		}
	}
	WindowPlatformData::WindowPlatformData(WindowPlatformData&& data):
		window(std::exchange(data.window, nullptr)) {}
	WindowPlatformData::~WindowPlatformData() {
		if (this->window) {
			glfwDestroyWindow(this->window);
		}
	}

    WindowPlatformData& WindowPlatformData::operator=(WindowPlatformData&& data) {
		this->window = std::exchange(data.window, nullptr);
		return *this;
	}

	Window::Window() {}
	Window::Window(Window&& w):
   		data(std::move(w.data)),
		width(std::move(w.width)),
		height(std::move(w.height)) {}
	Window::Window(const char* name, unsigned int width, unsigned int height):
   		width(width),
		height(height),
   		data(name, width, height) {}
	Window::~Window() {}

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

	Window& Window::operator=(Window&& w) {
		this->data = std::move(w.data);
		return *this;
	}
}
