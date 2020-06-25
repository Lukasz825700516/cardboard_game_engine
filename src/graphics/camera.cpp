#include "camera.hpp"


#include <glm/gtc/matrix_transform.hpp>

namespace cardboard::graphics {
	Camera::Camera(glm::vec2 dimensions):
		dimensions(dimensions / 2.0f) {
	
		this->calculate();
	}

	void Camera::set_dimensions(glm::vec2 dimensions) {
		this->dimensions = dimensions;
	}

	void Camera::set_position(glm::vec2 position) {
		this->position = position;
	}

	glm::mat4& Camera::calculate() {
		this->transfomation = glm::scale(
			glm::mat4(1.0f),
			1.0f / glm::vec3(
				this->dimensions.x,
				this->dimensions.y,
				1));

		return this->transfomation;
	}
}
