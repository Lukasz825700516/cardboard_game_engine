#pragma once

#include "window.hpp"
#include "glfw/mouse.hpp"
#include "mouse_key.hpp"
#include "mouse_mode.hpp"

namespace cardboard::resources {
	class MouseInstance {
	public:
		MousePlatfromData data;

		MouseInstance(Window& window);
		~MouseInstance();
	};

	class Mouse {
	public:
		static MouseInstance* instance;

		static glm::vec2 get_position();
		static void set_mode(MouseMode mode);
		static bool is_button_pressed(MouseKey key);
	};
}
