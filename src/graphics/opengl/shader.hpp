#pragma once

#include <string>
#include <map>

namespace cardboard::graphics {
	class ShaderPlatformData {
	public:
		int shader_program;
		std::map<std::string, unsigned int> uniforms;

		explicit ShaderPlatformData();
		explicit ShaderPlatformData(const ShaderPlatformData&) = delete;
		explicit ShaderPlatformData(ShaderPlatformData&&);
		~ShaderPlatformData();

		ShaderPlatformData& operator=(ShaderPlatformData&&);
	};
}
