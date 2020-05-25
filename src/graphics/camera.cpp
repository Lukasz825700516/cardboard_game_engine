#include "camera.hpp"


#include <glm/gtc/matrix_transform.hpp>

namespace cardboard::graphics {
	Camera::Camera() {}

	Camera::Camera(Camera& camera):
   		transfomation(camera.transfomation),
		dimensions(camera.dimensions),
		position(camera.position) {}

	Camera::Camera(glm::vec2 dimensions):
		dimensions(dimensions) {
	
		this->calculate();
	}

	Camera::Camera(Camera&& camera):
   		transfomation(std::move(camera.transfomation)),
		dimensions(std::move(camera.dimensions)),
		position(std::move(camera.position)) {}

	Camera::~Camera() {}

	Camera& Camera::operator=(Camera& camera) {
		this->transfomation = camera.transfomation;
		this->dimensions = camera.dimensions;
		this->position = camera.position;

		return *this;
	}

	Camera& Camera::operator=(Camera&& camera) {
		this->transfomation = std::move(camera.transfomation);
		this->dimensions = std::move(camera.dimensions);
		this->position = std::move(camera.position);

		return *this;
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
