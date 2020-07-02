#include "layer.hpp"
#include <iostream>

namespace cardboard::core {
	void Layer::update(float time_delta) {
		for (auto& child_layer : this->layers) {
			child_layer->update(time_delta);
		}
	}

}
