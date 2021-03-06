#include "particle_system.hpp"
#include <iostream>
#include <algorithm>
#include <utility>

namespace cardboard::graphics {
	ParticleSystemInstance* ParticleSystem::instance = nullptr;

	ParticleSystemInstance::ParticleSystemInstance() {
		ParticleSystem::instance = this;
	}

	ParticleSystemInstance::~ParticleSystemInstance() {
		ParticleSystem::instance = nullptr;
	}

	void ParticleSystem::summon(const Particle& particle) {
		instance->particles.emplace_back(particle);
	}

	void ParticleSystem::update(float time_delta) {
		for (auto it = instance->particles.begin(); it < instance->particles.end(); it++) {
			it->age += time_delta;
			if (it->age > it->life_time) {
				std::iter_swap(it, instance->particles.end() - 1);
				instance->particles.resize(instance->particles.size() - 1);
			} else {
				it->velocity += it->accelereration * time_delta;
				it->position += it->velocity * time_delta;
				it->size += it->size_delta * time_delta;
				it->rotation += it->rotation_delta * time_delta;
				it->color += it->color_delta * time_delta;
			}
		}
	}

	template<>
	void ParticleSystem::draw<QuadRenderer>(Texture& texture) {
		for (Particle& particle : instance->particles) {
			QuadRenderer::draw_rotated(
					particle.position,
					particle.size,
					particle.rotation,
					texture,
					particle.color
			);
		} 
	}

	void swap(cardboard::graphics::Particle& lhs, cardboard::graphics::Particle& rhs) {
		std::swap(lhs.position, rhs.position);
		std::swap(lhs.velocity, rhs.velocity);
		std::swap(lhs.accelereration, rhs.accelereration);
		std::swap(lhs.size, rhs.size);
		std::swap(lhs.size_delta, rhs.size_delta);
		std::swap(lhs.rotation, rhs.rotation);
		std::swap(lhs.rotation_delta, rhs.rotation_delta);
		std::swap(lhs.color, rhs.color);
		std::swap(lhs.color_delta, rhs.color_delta);
		std::swap(lhs.age, rhs.age);
		std::swap(lhs.life_time, rhs.life_time);
	}
}
