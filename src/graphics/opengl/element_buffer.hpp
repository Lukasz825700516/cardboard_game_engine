#pragma once

namespace cardboard::graphics {
	class ElementBufferPlatformData {
	public:
		unsigned int element_buffer_object;

		explicit ElementBufferPlatformData();
		explicit ElementBufferPlatformData(const ElementBufferPlatformData&) = delete;
		explicit ElementBufferPlatformData(ElementBufferPlatformData&&);
		~ElementBufferPlatformData();

		ElementBufferPlatformData& operator=(ElementBufferPlatformData&&);
	};
}
