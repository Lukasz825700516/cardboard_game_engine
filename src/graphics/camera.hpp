#pragma once

#include <glm/glm.hpp>

namespace cardboard::graphics {
	class Camera {
	private:
		glm::mat4 transfomation;
		glm::vec2 dimensions;
		glm::vec2 position;

	public:
		Camera();
		Camera(glm::vec2 dimensions);
		Camera(Camera& camera);
		Camera(Camera&& camera);
		~Camera();

		Camera& operator=(Camera& camera);
		Camera& operator=(Camera&& camera);

		static Camera get_2d(glm::vec2 dimensions);

		void set_dimensions(glm::vec2 dimensions);
		void set_position(glm::vec2 position);

		inline glm::mat4& get_transformation() { return this->transfomation; }
		inline glm::vec2& get_position() { return this->position; }

		glm::mat4& calculate();
	};
}
