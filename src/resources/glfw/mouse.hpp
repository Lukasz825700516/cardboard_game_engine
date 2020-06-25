#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <map>

namespace cardboard::resources {
	class MousePlatfromData {
	private:
		static void position_callback(GLFWwindow* window_ptr, double x, double y);
		static void key_callback(GLFWwindow* window_ptr, int key, int action, int mods);

	public:
		explicit MousePlatfromData() = delete;
		explicit MousePlatfromData(MousePlatfromData&);
		explicit MousePlatfromData(MousePlatfromData&&) = default;
		~MousePlatfromData();

		explicit MousePlatfromData(GLFWwindow* window_ptr);

		GLFWwindow* window_ptr;
		static glm::vec2 position;
		static std::map<int, bool> keys;
	};
}
