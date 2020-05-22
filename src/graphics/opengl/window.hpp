#pragma once
#include <GLFW/glfw3.h>

namespace cardboard::graphics {
	class WindowPlatformData {
		public:
			GLFWwindow *window;

			WindowPlatformData();
			WindowPlatformData(const char* name, unsigned int width, unsigned int height);
			WindowPlatformData(WindowPlatformData&& data);
			~WindowPlatformData();

			WindowPlatformData& operator=(WindowPlatformData&& data);
	};
}
