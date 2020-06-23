#include <algorithm>
#include <glm/detail/qualifier.hpp>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include "glad/glad.h"
#include "../shader.hpp"

#include "../context.hpp"

namespace cardboard::graphics {
	Shader::Shader(const char* vertex_code, const char* fragment_code) {
		const size_t BUFF_SIZE = 512;

		int vertex_shader = glad_glCreateShader(GL_VERTEX_SHADER);
		glad_glShaderSource(vertex_shader, 1, &vertex_code, 0);
		glad_glCompileShader(vertex_shader);

		unsigned int success;
		glad_glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, (int *)&success);
		if (!success) {
			char buff[BUFF_SIZE];
			std::fill(buff, buff + sizeof(buff), 0);

			glad_glGetShaderInfoLog(vertex_shader, BUFF_SIZE, 0, buff);
			std::cerr << "Failed to compile vertex shader\n" << buff << std::endl;
		}

		int fragment_shader = glad_glCreateShader(GL_FRAGMENT_SHADER);
		glad_glShaderSource(fragment_shader, 1, &fragment_code, 0);
		glad_glCompileShader(fragment_shader);

		glad_glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, (int *)&success);
		if (!success) {
			char buff[BUFF_SIZE];
			std::fill(buff, buff + sizeof(buff), 0);

			glad_glGetShaderInfoLog(fragment_shader, BUFF_SIZE, 0, buff);
			std::cerr << "Failed to compile fragment shader\n" << buff << std::endl;
		}

		this->data.shader_program = glad_glCreateProgram();
		glad_glAttachShader(this->data.shader_program, vertex_shader);
		glad_glAttachShader(this->data.shader_program, fragment_shader);
		glad_glLinkProgram(this->data.shader_program);

		glad_glGetProgramiv(this->data.shader_program, GL_LINK_STATUS, (int *)&success);
		if (!success) {
			char buff[BUFF_SIZE];
			std::fill(buff, buff + sizeof(buff), 0);

			glGetProgramInfoLog(this->data.shader_program, BUFF_SIZE, 0, buff);
			std::cerr << "Failed to link shaders\n" << buff << std::endl;
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

	unsigned int Shader::get_uniform_id(const char* name) {
		unsigned int uniform = 0;
		auto search = this->data.uniforms.find(name);
		
		if (search != this->data.uniforms.end()) {
			uniform = search->second;
		} else {
			uniform = 
				glad_glGetUniformLocation(this->data.shader_program, name);
			this->data.uniforms[name] =
				uniform;
		}

		return uniform;
	}

	void Shader::set_uniform(glm::mat4& value, const char* name) {
		unsigned int uniform = this->get_uniform_id(name);
		glad_glUniformMatrix4fv(uniform, 1, false, glm::value_ptr(value));
	}

	void Shader::set_uniform(glm::vec2 value, const char* name) {
		unsigned int uniform = this->get_uniform_id(name);
		glad_glUniform2f(uniform, value.x, value.y);
	}

	void Shader::set_uniform(glm::vec3 value, const char* name) {
		unsigned int uniform = this->get_uniform_id(name);
		glad_glUniform3f(uniform, value.x, value.y, value.z);
	}

	void Shader::set_uniform(int value, const char* name) {
		unsigned int uniform = this->get_uniform_id(name);
		glad_glUniform1i(uniform, value);
	}

	void Shader::set_uniform(const char* name, size_t size, int* value) {
		unsigned int uniform = this->get_uniform_id(name);
		glad_glUniform1iv(uniform, size, value);
	}
}
