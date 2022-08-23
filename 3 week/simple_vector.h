#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
	SimpleVector() {
		data = nullptr;
		size_ = 0;
		capacity_ = 0;
	}

	explicit SimpleVector(size_t size) : size_(size), capacity_(size) {
		data = new T[size];			
	}

	~SimpleVector() {
		delete[] data;
	}

	T& operator[](size_t index) {
		return data[index];
	}

	T* begin() { return data; }
	T* end() { return data + size_; }

	size_t Size() const { return size_; }
	size_t Capacity() const { return capacity_; }

	void PushBack(const T& value) {		
		if (size_ == capacity_) {			
			capacity_ *= 2;
			if (size_ == 0) {
				++capacity_;
			}
			T* result = new T[capacity_];
			for (decltype(size_) i = 0; i < size_; ++i) {
				result[i] = data[i];
			}
			delete[] data;
			data = result;
		}
		data[size_++] = value;
	}

private:
	T* data;	
	size_t size_;
	size_t capacity_;	
	// Добавьте поля для хранения данных вектора
};
