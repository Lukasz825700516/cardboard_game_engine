#pragma once
#include "window.hpp"

namespace cardboard::graphics {
	class Context {
		private: 
		Window window;

		public:
		Context();
		~Context();

		void set_window(Window&& window);
		inline Window& get_window() { return this->window; }
	};
}
