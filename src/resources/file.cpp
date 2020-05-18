#include "file.hpp"
#include <istream>
#include <iterator>
#include <optional>
#include <fstream>
#include <streambuf>
#include <iostream>

namespace cardboard::resources {
	std::optional<std::string> File::load_file_content(const char* path) {
		std::ifstream file(path, std::fstream::in);

		if (!file.good()) {
			std::cerr << "Failed to open a file! " << path << std::endl;
			return std::nullopt;
		}

		return std::string(
			(std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
	}
}
