#include <iostream>
#include "glad/glad.h"
#include "../shader.hpp"

#include "../context.hpp"

namespace cardboard::graphics {
	Shader::Shader(const char* vertex_code, const char* fragment_code) {
		int vertex_shader = glad_glCreateShader(GL_VERTEX_SHADER);
		glad_glShaderSource(vertex_shader, 1, &vertex_code, 0);
		glad_glCompileShader(vertex_shader);

		unsigned int success;
		glad_glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, (int *)&success);
		if (!success) {
			char buff[512];
			glGetProgramInfoLog(this->data.shader_program, 512, 0, buff);

			std::cerr << "Failed to compile shaders\n" << buff << std::endl;
		}

		int fragment_shader = glad_glCreateShader(GL_FRAGMENT_SHADER);
		glad_glShaderSource(fragment_shader, 1, &fragment_code, 0);
		glad_glCompileShader(fragment_shader);

		glad_glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, (int *)&success);
		if (!success) {
			char buff[512];
			glGetProgramInfoLog(this->data.shader_program, 512, 0, buff);

			std::cerr << "Failed to compile shaders\n" << buff << std::endl;
		}

		this->data.shader_program = glad_glCreateProgram();
		glad_glAttachShader(this->data.shader_program, vertex_shader);
		glad_glAttachShader(this->data.shader_program, fragment_shader);
		glad_glLinkProgram(this->data.shader_program);

		glad_glGetProgramiv(this->data.shader_program, GL_LINK_STATUS, (int *)&success);
		if (!success) {
			char buff[512];
			glGetProgramInfoLog(this->data.shader_program, 512, 0, buff);

			std::cerr << "Failed to compile shaders\n" << buff << std::endl;
		}

		glad_glDeleteShader(vertex_shader);
		glad_glDeleteShader(fragment_shader);
	}

	Shader::~Shader() {
		glDeleteProgram(this->data.shader_program);
	}

	void Shader::bind() {
		glad_glUseProgram(this->data.shader_program);
	}
}
