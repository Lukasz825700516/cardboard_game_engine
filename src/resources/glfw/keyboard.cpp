#include "../keyboard.hpp"
#include <GLFW/glfw3.h>


namespace cardboard::resources {
	std::map<int, bool> KeyboardPlatformData::keys;

	KeyboardPlatformData::KeyboardPlatformData(GLFWwindow* window_ptr) {
		glfwSetKeyCallback(window_ptr, KeyboardPlatformData::key_callback);
	}

	KeyboardPlatformData::~KeyboardPlatformData() {}

	void KeyboardPlatformData::key_callback(
		GLFWwindow* window_ptr,
		int key,
		int scancode,
		int action,
		int mods) {

		if (action == GLFW_PRESS) {
			KeyboardPlatformData::keys[key] = true;

		} else if (action == GLFW_RELEASE) {
			KeyboardPlatformData::keys[key] = false;

		}

		(void)window_ptr;
		(void)scancode;
		(void)mods;	
	}

	Keyboard::Keyboard(Window& window):
   		data(window.get_data().window) {}

	Keyboard::~Keyboard() {}


	bool Keyboard::is_key_pressed(Key key) {
		switch (key) {
			case CARDBOARD_KEYBOARD_KEY_A: return KeyboardPlatformData::keys[GLFW_KEY_A];
			case CARDBOARD_KEYBOARD_KEY_B: return KeyboardPlatformData::keys[GLFW_KEY_B];
			case CARDBOARD_KEYBOARD_KEY_C: return KeyboardPlatformData::keys[GLFW_KEY_C];
			case CARDBOARD_KEYBOARD_KEY_D: return KeyboardPlatformData::keys[GLFW_KEY_D];
			case CARDBOARD_KEYBOARD_KEY_E: return KeyboardPlatformData::keys[GLFW_KEY_E];
			case CARDBOARD_KEYBOARD_KEY_F: return KeyboardPlatformData::keys[GLFW_KEY_F];
			case CARDBOARD_KEYBOARD_KEY_G: return KeyboardPlatformData::keys[GLFW_KEY_G];
			case CARDBOARD_KEYBOARD_KEY_H: return KeyboardPlatformData::keys[GLFW_KEY_H];
			case CARDBOARD_KEYBOARD_KEY_I: return KeyboardPlatformData::keys[GLFW_KEY_I];
			case CARDBOARD_KEYBOARD_KEY_J: return KeyboardPlatformData::keys[GLFW_KEY_J];
			case CARDBOARD_KEYBOARD_KEY_K: return KeyboardPlatformData::keys[GLFW_KEY_K];
			case CARDBOARD_KEYBOARD_KEY_L: return KeyboardPlatformData::keys[GLFW_KEY_L];
			case CARDBOARD_KEYBOARD_KEY_M: return KeyboardPlatformData::keys[GLFW_KEY_M];
			case CARDBOARD_KEYBOARD_KEY_N: return KeyboardPlatformData::keys[GLFW_KEY_N];
			case CARDBOARD_KEYBOARD_KEY_O: return KeyboardPlatformData::keys[GLFW_KEY_O];
			case CARDBOARD_KEYBOARD_KEY_P: return KeyboardPlatformData::keys[GLFW_KEY_P];
			case CARDBOARD_KEYBOARD_KEY_Q: return KeyboardPlatformData::keys[GLFW_KEY_Q];
			case CARDBOARD_KEYBOARD_KEY_R: return KeyboardPlatformData::keys[GLFW_KEY_R];
			case CARDBOARD_KEYBOARD_KEY_S: return KeyboardPlatformData::keys[GLFW_KEY_S];
			case CARDBOARD_KEYBOARD_KEY_T: return KeyboardPlatformData::keys[GLFW_KEY_T];
			case CARDBOARD_KEYBOARD_KEY_U: return KeyboardPlatformData::keys[GLFW_KEY_U];
			case CARDBOARD_KEYBOARD_KEY_V: return KeyboardPlatformData::keys[GLFW_KEY_V];
			case CARDBOARD_KEYBOARD_KEY_W: return KeyboardPlatformData::keys[GLFW_KEY_W];
			case CARDBOARD_KEYBOARD_KEY_X: return KeyboardPlatformData::keys[GLFW_KEY_X];
			case CARDBOARD_KEYBOARD_KEY_Y: return KeyboardPlatformData::keys[GLFW_KEY_Y];
			case CARDBOARD_KEYBOARD_KEY_Z: return KeyboardPlatformData::keys[GLFW_KEY_Z];
			case CARDBOARD_KEYBOARD_KEY_0: return KeyboardPlatformData::keys[GLFW_KEY_0];
			case CARDBOARD_KEYBOARD_KEY_1: return KeyboardPlatformData::keys[GLFW_KEY_1];
			case CARDBOARD_KEYBOARD_KEY_2: return KeyboardPlatformData::keys[GLFW_KEY_2];
			case CARDBOARD_KEYBOARD_KEY_3: return KeyboardPlatformData::keys[GLFW_KEY_3];
			case CARDBOARD_KEYBOARD_KEY_4: return KeyboardPlatformData::keys[GLFW_KEY_4];
			case CARDBOARD_KEYBOARD_KEY_5: return KeyboardPlatformData::keys[GLFW_KEY_5];
			case CARDBOARD_KEYBOARD_KEY_6: return KeyboardPlatformData::keys[GLFW_KEY_6];
			case CARDBOARD_KEYBOARD_KEY_7: return KeyboardPlatformData::keys[GLFW_KEY_7];
			case CARDBOARD_KEYBOARD_KEY_8: return KeyboardPlatformData::keys[GLFW_KEY_8];
			case CARDBOARD_KEYBOARD_KEY_9: return KeyboardPlatformData::keys[GLFW_KEY_9];
			case CARDBOARD_KEYBOARD_KEY_UP: return KeyboardPlatformData::keys[GLFW_KEY_UP];
			case CARDBOARD_KEYBOARD_KEY_RIGHT: return KeyboardPlatformData::keys[GLFW_KEY_RIGHT];
			case CARDBOARD_KEYBOARD_KEY_DOWN: return KeyboardPlatformData::keys[GLFW_KEY_DOWN];
			case CARDBOARD_KEYBOARD_KEY_LEFT: return KeyboardPlatformData::keys[GLFW_KEY_LEFT];

			default: return false;
		}
	}
}
