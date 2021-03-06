#include "glad/glad.h"
#include "../element_buffer.hpp"
#include "graphics/opengl/element_buffer.hpp"
#include <glm/glm.hpp>
#include <utility>

namespace cardboard::graphics {
	ElementBufferPlatformData::ElementBufferPlatformData() {
		glad_glGenBuffers(1, &this->element_buffer_object);
	}
	
	ElementBufferPlatformData::ElementBufferPlatformData(ElementBufferPlatformData&& other):
   		element_buffer_object(std::exchange(other.element_buffer_object, 0)) {}

	ElementBufferPlatformData::~ElementBufferPlatformData() {
		if (element_buffer_object) {
			glad_glDeleteBuffers(1, &this->element_buffer_object);
		}
	}

	ElementBufferPlatformData& ElementBufferPlatformData::operator=(ElementBufferPlatformData&& other) {
		this->element_buffer_object = std::exchange(other.element_buffer_object, 0);
		return *this;
	}

	ElementBuffer::ElementBuffer(std::vector<glm::uvec3> buffer):
		buffer(buffer) {}

	void ElementBuffer::bind() {
		glad_glBindBuffer(GL_ARRAY_BUFFER, this->data.element_buffer_object);
	}

	void ElementBuffer::flush() {
		glad_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->data.element_buffer_object);
		glad_glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			this->buffer.size() * sizeof(glm::uvec3),
			this->buffer.data(),
			GL_STATIC_DRAW);
	}

	glm::uvec3& ElementBuffer::operator[](unsigned int index) {
		return this->buffer[index];
	}
}
