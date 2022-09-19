#include <vector>
#include <tuple>
#include <array>
#include <iostream>
#include "profile.h"

using namespace std;

vector<int> BuildVector(int i) {
	return { i, i + 1, i + 2, i + 3, i + 4 };		
}

array<int, 5> BuildArray(int i) {
	return { i, i + 1, i + 2, i + 3, i + 4 };
}

tuple<int,int,int,int,int> BuildTuple(int i) {
	return make_tuple(i, i + 1, i + 2, i + 3, i + 4);
}

const int COUNT = 1'000'000;

void array_test() {
	LOG_DURATION("array");
	for (int i = 0; i < COUNT; ++i) {
		auto numbers = BuildArray(i);
	}
}

void vector_test() {
	LOG_DURATION("vector");
	for (int i = 0; i < COUNT; ++i) {
		auto numbers = BuildVector(i);
	}
}

void tuple_test() {
	LOG_DURATION("tuple");
	for (int i = 0; i < COUNT; ++i) {
		auto numbers = BuildTuple(i);
	}
}

void test_int() {
	int x = 111111;
	array<int, 10> numbers;
	numbers.fill(8);
	int y = 222222;

	for (int* p = &y; p <= &x; ++p) {
		cout << *p << " ";
	}
	cout << "\n";
}

int main() {
	int x = 111111;
	array<int, 10> numbers;
	numbers.fill(8);
	int y = 222222;

	for (int* p = &y; p <= &x; ++p) {
		cout << *p << " ";
	}
	cout << "\n";
	/*vector_test();
	tuple_test();
	array_test();*/
	//test_int();
	return 0;
}