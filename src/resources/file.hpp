#pragma once

#include <optional>
#include <string>

namespace cardboard::resources {
	class File {
	public:
		static std::optional<std::string> read(const char* path);
	};
}
