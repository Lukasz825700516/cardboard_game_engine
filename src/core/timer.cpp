#include "timer.hpp"
#include <iostream>

namespace cardboard::core {
	Timer::Timer(const char* function, const char* label):
		function(function),
   		label(label) {

		this->start = std::chrono::high_resolution_clock::now();
	}

	Timer::~Timer() {
		auto duration = std::chrono::high_resolution_clock::now() - this->start;
		auto nanoseconds = std::chrono::nanoseconds(duration);

		std::cout << "Timer " << this->function << " " << this->label << " " << nanoseconds.count() << " ns" << std::endl;
	}
}
