#pragma once

#include <vector>
#include <memory>

namespace cardboard::core {
	class Layer {
	public:
		explicit Layer() = default;
		explicit Layer(const Layer&) = delete;
		explicit Layer(Layer&&) = delete;
		~Layer() = default;

		std::vector<std::unique_ptr<Layer>> layers;

		virtual void update(float time_delta);
		template<typename T>
		Layer* add_layer() {
			this->layers.push_back(std::make_unique<T>());
			return this->layers.back().get();
		}
	};
}
