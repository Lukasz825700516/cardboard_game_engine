#pragma once
#include "window.hpp"
#include "glfw/keyboard.hpp"
#include "keyboard_key.hpp"

namespace cardboard::resources {
	class KeyboardInstance {
	public:
		KeyboardPlatformData data;

		KeyboardInstance(Window& window);
		~KeyboardInstance();
	};

	class Keyboard {
	public:
		static KeyboardInstance* instance;

		static bool is_key_pressed(KeyboardKey key);
	};
}
