#include "particle_system.hpp"
#include <algorithm>
#include <utility>

namespace cardboard::graphics {
	ParticleSystemInstance* ParticleSystem::instance = nullptr;

	Particle::Particle():
		position(glm::vec2(0)),
   		velocity(glm::vec2(0)),
		accelereration(glm::vec2(0)),
		max_lifetime(0),
		life_time(0) {}

	Particle::Particle(glm::vec2 position, glm::vec2 velocity, glm::vec2 accelereration, glm::vec2 size, glm::vec2 finale_size, float rotation, float finale_rotation, glm::vec4 color, glm::vec4 finale_color, float max_lifetime):
		position(position),
		velocity(velocity),
		accelereration(accelereration),
		initial_size(size),
		finale_size(finale_size),
		initial_rotation(rotation),
		finale_rotation(finale_rotation),
		initial_color(color),
		finale_color(finale_color),
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

	ParticleSystemInstance::ParticleSystemInstance() {
		ParticleSystem::instance = this;
	}

	void ParticleSystem::summon(glm::vec2 position, glm::vec2 initial_velocity, glm::vec2 accelereration, float max_lifetime) {
		instance->particles.emplace_back(position, initial_velocity, accelereration, glm::vec2(10), glm::vec2(20), 0, 0, glm::vec4(1), glm::vec4(1), max_lifetime);
	}

	void ParticleSystem::update(float time_delta) {
		for (auto it = instance->particles.begin(); it < instance->particles.end(); it++) {
			it->life_time += time_delta;
			if (it->life_time > it->max_lifetime) {
				std::iter_swap(it, instance->particles.end() - 1);
				instance->particles.resize(instance->particles.size() - 1);
			} else {
				it->velocity += it->accelereration * time_delta;
				it->position += it->velocity * time_delta;
			}
		}
	}

	template<>
	void ParticleSystem::draw<QuadRenderer>() {
		for (Particle& particle : instance->particles) {
			QuadRenderer::draw(particle.position, particle.initial_size + (particle.finale_size - particle.initial_size) / particle.max_lifetime * particle.life_time);
		} 
	}
}
