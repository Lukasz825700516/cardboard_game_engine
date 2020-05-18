#pragma once

#include <optional>
#include <string>

namespace cardboard::resources {
	class File {
	public:
		static std::optional<std::string> load_file_content(const char* path);
	};
}
