#pragma once
#include <GLFW/glfw3.h>

namespace cardboard::resources {
	class WindowPlatformData {
		public:
			explicit WindowPlatformData();
			explicit WindowPlatformData(WindowPlatformData& data) = delete;
			explicit WindowPlatformData(WindowPlatformData&& data);
			~WindowPlatformData();

			explicit WindowPlatformData(const char* name, unsigned int width, unsigned int height);

			GLFWwindow *window = nullptr;

			WindowPlatformData& operator=(WindowPlatformData&& data);
	};
}
