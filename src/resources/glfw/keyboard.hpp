#pragma once

#include <GLFW/glfw3.h>
#include <map>

namespace cardboard::resources {
	class KeyboardPlatformData {
	public:
		KeyboardPlatformData(GLFWwindow* window_ptr);
		~KeyboardPlatformData();

		static void key_callback(
			GLFWwindow* window_ptr,
			int key,
			int scancode,
			int action,
			int mods);
		
		static std::map<int, bool> keys;
	};
}
