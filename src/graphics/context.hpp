#pragma once
#include "resources/window.hpp"

using cardboard::resources::Window;

namespace cardboard::graphics {
	class ContextInstance {
	public:
		Window window;

		ContextInstance();
		~ContextInstance();
	};

	class Context {
	public:
		static ContextInstance* instance;


		static void set_window(Window&& window);
		static inline Window& get_window() { return instance->window; }
	};
}
