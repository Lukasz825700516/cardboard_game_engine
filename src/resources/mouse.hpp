#pragma once

#include "window.hpp"
#include "glfw/mouse.hpp"
#include "mouse_key.hpp"
#include "mouse_mode.hpp"

namespace cardboard::resources {
	class Mouse {
	private:
		MousePlatfromData data;

	public:
		Mouse(Window& window);
		~Mouse();

		glm::vec2 get_position();

		void set_mode(MouseMode mode);

		bool is_button_pressed(MouseKey key);
	};
}
