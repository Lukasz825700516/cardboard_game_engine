#pragma once

#include "opengl/window.hpp"

namespace cardboard::graphics {
	class Window {
		private:
		WindowPlatformData data;

		unsigned int width;
		unsigned int height;

		public:

		Window();
		Window(Window&& w);
		Window(const char* name, unsigned int width, unsigned int height);
		~Window();

		void set_name(const char* name);
		void set_size(unsigned int width, unsigned int height);

		inline unsigned int get_width() { return this->width; }
		inline unsigned int get_height() { return this->height; }

		inline WindowPlatformData& get_data() { return this->data; }
		void swap_buffers();

		int should_close();
		static void poll_events();

		Window& operator=(Window&& w);
	};
}
