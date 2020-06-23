#include "particle_system.hpp"
#include <algorithm>
#include <utility>

namespace cardboard::graphics {
	Particle::Particle():
		position(glm::vec2(0)),
   		velocity(glm::vec2(0)),
		accelereration(glm::vec2(0)),
		max_lifetime(0),
		life_time(0) {}

	Particle::Particle(glm::vec2 position, glm::vec2 velocity, glm::vec2 accelereration, float max_lifetime):
		position(position),
		velocity(velocity),
		accelereration(accelereration),
		max_lifetime(max_lifetime),
		life_time(0) {}

	Particle::Particle(Particle& particle):
		position(particle.position),
   		velocity(particle.velocity),
		accelereration(particle.accelereration),
		max_lifetime(particle.max_lifetime),
		life_time(particle.life_time) {}

	Particle::Particle(Particle&& particle):
		position(std::move(particle.position)),
   		velocity(std::move(particle.velocity)),
		accelereration(std::move(particle.accelereration)),
		max_lifetime(std::exchange(particle.max_lifetime, 0)),
		life_time(std::exchange(particle.life_time, 0)) {}

	Particle& Particle::operator=(Particle& particle) {
		this->position = particle.position;
   		this->velocity = particle.velocity;
		this->accelereration = particle.accelereration;
		this->life_time = particle.life_time;
		this->max_lifetime = particle.max_lifetime;

		return *this;
	}

	Particle& Particle::operator=(Particle&& particle) {
		this->position = std::move(particle.position);
   		this->velocity = std::move(particle.velocity);
		this->accelereration = std::move(particle.accelereration);
		this->life_time = std::exchange(particle.life_time, 0);
		this->max_lifetime = std::exchange(particle.max_lifetime, 0);

		return *this;
	}

	void ParticleSystem::summon(glm::vec2 position, glm::vec2 initial_velocity, glm::vec2 accelereration, float max_lifetime) {
		this->particles.emplace_back(position, initial_velocity, accelereration, max_lifetime);
	}

	void ParticleSystem::update(float time_delta) {
		for (auto it = this->particles.begin(); it < this->particles.end(); it++) {
			it->velocity += it->accelereration * time_delta;
			it->position += it->velocity * time_delta;
			it->life_time += time_delta;

			if (it->life_time > it->max_lifetime) {
				std::iter_swap(it, this->particles.end() - 1);
				this->particles.resize(this->particles.size() - 1);
			}
		}
	}

	void ParticleSystem::flush(QuadRenderer& renderer) {
		for (Particle& particle : this->particles) {
			renderer.draw(particle.position, glm::vec2(10));
		}
	}
}
