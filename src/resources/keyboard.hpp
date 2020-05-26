#pragma once
#include "window.hpp"
#include "glfw/keyboard.hpp"
#include "keyboard_key.hpp"

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
