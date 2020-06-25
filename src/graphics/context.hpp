#pragma once
#include "resources/window.hpp"

using cardboard::resources::Window;

namespace cardboard::graphics {
	class ContextInstance {
	public:
		explicit ContextInstance();
		explicit ContextInstance(const ContextInstance&) = delete;
		explicit ContextInstance(ContextInstance&&) = default;
		~ContextInstance();

		Window window;
	};

	class Context {
	public:
		static ContextInstance* instance;

		static void set_window(Window&& window);
		static inline Window& get_window() { return instance->window; }
	};
}
