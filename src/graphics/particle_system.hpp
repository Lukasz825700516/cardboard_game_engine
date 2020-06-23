#pragma once


#include "graphics/quad_renderer.hpp"
#include <glm/glm.hpp>
#include <vector>
namespace cardboard::graphics {
	class Particle {
	public:
		glm::vec2 position;
		glm::vec2 velocity;
		glm::vec2 accelereration;
		float max_lifetime;
		float life_time;

		Particle();
		Particle(glm::vec2, glm::vec2, glm::vec2, float);
		Particle(Particle&);
		Particle(Particle&&);

		Particle& operator=(Particle&);
		Particle& operator=(Particle&&);
	};


	class ParticleSystem {
	private:
		std::vector<Particle> particles;

	public:
		void update(float time_delta);
		void summon(glm::vec2 position, glm::vec2 initial_velocity, glm::vec2 accelereration, float life_time);
		void flush(QuadRenderer& renderer);
	};
}
