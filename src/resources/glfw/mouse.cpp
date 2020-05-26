#include "mouse.hpp"
#include "../mouse.hpp"
#include "resources/mouse_key.hpp"
#include "resources/mouse_mode.hpp"
#include <GLFW/glfw3.h>

namespace cardboard::resources {
	glm::vec2 MousePlatfromData::position;
	std::map<int, bool> MousePlatfromData::keys;

	MousePlatfromData::MousePlatfromData(GLFWwindow* window_ptr):
   		window_ptr(window_ptr) {
		glfwSetCursorPosCallback(this->window_ptr, MousePlatfromData::position_callback);
		glfwSetMouseButtonCallback(this->window_ptr, MousePlatfromData::key_callback);
	}

	MousePlatfromData::~MousePlatfromData() {}

	void MousePlatfromData::position_callback(GLFWwindow* window_ptr, double x, double y) {
		MousePlatfromData::position.x = -x;
		MousePlatfromData::position.y = y;

		(void)window_ptr;
	}

	void MousePlatfromData::key_callback(GLFWwindow* window_ptr, int key, int action, int mods) {
	
		if (action == GLFW_PRESS) {
			MousePlatfromData::keys[key] = true;

		} else if (action == GLFW_RELEASE) {
			MousePlatfromData::keys[key] = false;
		}

		(void)window_ptr;
		(void)mods;
	}

	Mouse::Mouse(Window& window):
		data(window.get_data().window) {}

	Mouse::~Mouse() {}

	glm::vec2 Mouse::get_position() {
		return this->data.position;
	}

	void Mouse::set_mode(MouseMode mode) {
		switch(mode) {
			case CARDBOARD_MOUSE_NORMAL: glfwSetInputMode(this->data.window_ptr, GLFW_CURSOR, GLFW_CURSOR_NORMAL); return;
			case CARDBOARD_MOUSE_HIDDEN: glfwSetInputMode(this->data.window_ptr, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); return;
			case CARDBOARD_MOUSE_DISABLED: glfwSetInputMode(this->data.window_ptr, GLFW_CURSOR, GLFW_CURSOR_DISABLED); return;
		}
	}

	bool Mouse::is_button_pressed(MouseKey key) {
		switch(key) {
			case CARDBOARD_MOUSE_LEFT: return this->data.keys[GLFW_MOUSE_BUTTON_LEFT];
			case CARDBOARD_MOUSE_MIDDLE: return this->data.keys[GLFW_MOUSE_BUTTON_MIDDLE];
			case CARDBOARD_MOUSE_RIGHT: return this->data.keys[GLFW_MOUSE_BUTTON_RIGHT];

			default: return false;
		}
	}


}
