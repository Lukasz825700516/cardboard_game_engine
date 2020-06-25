#pragma once

#include "glfw/window.hpp"

namespace cardboard::resources {
	class Window {
	private:
		WindowPlatformData data;

		unsigned int width = 0;
		unsigned int height = 0;

	public:

		explicit Window();
		explicit Window(Window&) = delete;
		explicit Window(Window&&) = default;
		~Window() = default;

		explicit Window(const char* name, unsigned int width, unsigned int height);

		void set_name(const char* name);
		void set_size(unsigned int width, unsigned int height);

		inline unsigned int get_width() { return this->width; }
		inline unsigned int get_height() { return this->height; }

		inline WindowPlatformData& get_data() { return this->data; }
		void swap_buffers();

		int should_close();
		static void poll_events();

		Window& operator=(Window&&) = default;
	};
}
