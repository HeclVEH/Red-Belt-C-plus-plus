#pragma once

#include <stdexcept>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:	
	explicit StackVector(size_t a_size = 0);

	T& operator[](size_t index)					{ return data[index]; }
	const T& operator[](size_t index) const		{ return data[index]; }

	auto begin()		{ return data.begin(); }
	auto end()			{ return data.end(); };
	auto begin() const	{ return data.begin(); };
	auto end() const	{ return data.end(); };

	size_t Size() const { return N; }
	size_t Capacity() const { return data.capacity(); }

	void PushBack(const T& value);
	T PopBack();

private:
	array<T, N> data;
};

