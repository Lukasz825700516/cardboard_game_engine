#pragma once


#include <glm/glm.hpp>
#include <vector>
namespace cardboard::graphics {
	class Particle {
	public:
		glm::vec2 position;
		glm::vec2 initial_velocity;
		glm::vec2 accelereration;
		float life_time;
		float max_lifetime;
	};


	class ParticleSystem {
	private:
		std::vector<Particle> particles;

	public:
		void update();
		void summon(glm::vec2 position, glm::vec2 initial_velocity, glm::vec2 accelereration, float life_time);
		void flush();
	};
}
