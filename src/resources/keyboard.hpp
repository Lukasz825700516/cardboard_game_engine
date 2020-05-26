#pragma once
#include "../graphics/window.hpp"
#include "glfw/keyboard.hpp"
#include "keyboard_key.hpp"

using cardboard::graphics::Window;

namespace cardboard::resources {
	class Keyboard {
	private:
		KeyboardPlatformData data;

	public:
		Keyboard(Window& window);
		~Keyboard();

		bool is_key_pressed(KeyboardKey key);
	};
}
