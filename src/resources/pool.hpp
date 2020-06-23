#include <algorithm>

template<typename T>
class Pool {
	T* data;
	T* used_data_end;
	T* data_end;

	Pool() :
		data(new T[20]),
		used_data_end(data),
		data_end(data + 20) {}

	Pool(const Pool& pool) :
		data(new T[pool.size()]),
		used_data_end(pool.used_data_end),
		data_end(pool.data_end)	{

		std::copy(pool.begin(), pool.end(), data);
	}

	Pool(const Pool&& pool) :
		data(std::exchange(pool.data, nullptr)),
		used_data_end(std::exchange(pool.used_data_end, nullptr)),
		data_end(std::exchange(pool.data_end, nullptr)) {}


	void push_back(T v) {
		*used_data_end = v;
		used_data_end++;

		if (used_data_end == data_end) {
			T* new_data = new T[20];
			std::move(data, used_data_end - 1, new_data);
			delete[] data;
			data = new_data;
		}
	}

	void push_back(T&& v) {
		*used_data_end = std::move(v);
		used_data_end++;

		if (used_data_end == data_end) {
			T* new_data = new T[max_size() * 2];
			std::move(data, used_data_end - 1, new_data);
			delete[] data;
			data = new_data;
		}
	}

	void remove(size_t index) {
		std::move(data[index], *(used_data_end - 1));
		used_data_end--;
	}

	T* begin() { return data; }
	T* end() { return used_data_end; }
	const T* begin() const { return data; }
	const T* end() const { return used_data_end; }

	T& operator[](size_t index) {
		return data[index];
	}

	size_t size() const {
		return used_data_end - data;
	}

	size_t max_size() const {
		return data_end - data;
	}
};
