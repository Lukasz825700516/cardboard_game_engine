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
		glm::vec2 initial_size;
		glm::vec2 finale_size;
		float initial_rotation;
		float finale_rotation;
		glm::vec4 initial_color;
		glm::vec4 finale_color;
		float max_lifetime;
		float life_time;

		Particle();
		Particle(glm::vec2, glm::vec2, glm::vec2, glm::vec2, glm::vec2, float, float, glm::vec4, glm::vec4, float);
		Particle(Particle&);
		Particle(Particle&&);

		Particle& operator=(Particle&);
		Particle& operator=(Particle&&);
	};

	class ParticleSystemInstance {
	public:
		std::vector<Particle> particles;

		ParticleSystemInstance();
	};

	class ParticleSystem {
	public:
		static ParticleSystemInstance* instance;
		static void update(float time_delta);
		static void summon(glm::vec2 position, glm::vec2 initial_velocity, glm::vec2 accelereration, float life_time);
		template<typename renderer>
		static void draw();
	};
}
