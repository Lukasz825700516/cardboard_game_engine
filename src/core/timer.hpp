#pragma once

#include <chrono>
#include <boost/current_function.hpp>

#define CARDBOARD_TIMER(LABEL) cardboard::core::Timer timer_##__line__(BOOST_CURRENT_FUNCTION, LABEL);

namespace cardboard::core {
	class Timer {
	public:
		explicit Timer(const char* function, const char* label);
		explicit Timer(const Timer&) = delete;
		explicit Timer(Timer&&) = delete;
		~Timer();

		std::chrono::high_resolution_clock::time_point start;
		const char* function;
		const char* label;
	};
}
