#pragma once
#include "window.hpp"

namespace cardboard::graphics {
	class Context {
		private: 
		static Window window;

		public:

		static void initialize();
		static void destroy();

		static void set_window(Window& window);

	};
}
