#pragma once

namespace cardboard::graphics {
	class ElementBufferPlatformData {
	public:
		unsigned int element_buffer_object;

		ElementBufferPlatformData();
		ElementBufferPlatformData(ElementBufferPlatformData&& data);
		~ElementBufferPlatformData();
	};
}
