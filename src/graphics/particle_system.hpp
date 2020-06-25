#pragma once

#include "graphics/quad_renderer.hpp"
#include <glm/glm.hpp>
#include <vector>

namespace cardboard::graphics {
	class Particle {
	public:
		explicit Particle() = default;
		explicit Particle(const Particle&) = default;
		explicit Particle(Particle&&) = default;

		Particle& operator=(const Particle&) = default;
		Particle& operator=(Particle&&) = default;

		glm::vec2 position = glm::vec2(0);
		glm::vec2 velocity = glm::vec2(0);
		glm::vec2 accelereration = glm::vec2(0);
		glm::vec2 size = glm::vec2(0);
		glm::vec2 size_delta = glm::vec2(0);
		float rotation = 0;
		float rotation_delta = 0;
		glm::vec4 color = glm::vec4(1);
		glm::vec4 color_delta = glm::vec4(1);
		float age = 0;
		float life_time = 0;

		inline Particle& set_position(glm::vec2 position) { this->position = position; return *this; }
		inline Particle& set_velocity(glm::vec2 velocity) { this->velocity = velocity; return *this; }
		inline Particle& set_acceleration(glm::vec2 accelereration) { this->accelereration = accelereration; return *this; }
		inline Particle& set_life_time(float life_time) { this->life_time = life_time; return *this; }
		inline Particle& set_rotation(float initial, float finale) {
			this->rotation = initial;
			this->rotation_delta = (finale - initial) / this->life_time;
			return *this;
		}
		inline Particle& set_color(glm::vec4 initial, glm::vec4 finale) {
			this->color = initial;
			this->color_delta = (finale - initial) / this->life_time;
			return *this;
		}
		inline Particle& set_size(glm::vec2 initial, glm::vec2 finale) {
			this->size = initial;
			this->size_delta = (finale - initial) / this->life_time;
			return *this;
		}
	};

	void swap(Particle&, Particle&);

	class ParticleSystemInstance {
	public:
		std::vector<Particle> particles;

		ParticleSystemInstance();
		ParticleSystemInstance(const ParticleSystemInstance&) = delete;
		ParticleSystemInstance(const ParticleSystemInstance&&);
		~ParticleSystemInstance();
	};

	class ParticleSystem {
	public:
		static ParticleSystemInstance* instance;
		static void update(float time_delta);
		static void summon(const Particle&);
		template<typename renderer>
		static void draw(Texture&);
	};
}
