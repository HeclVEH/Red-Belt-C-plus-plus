#include "profile.h"
#include <deque>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;;

int main1() {
	{
		LOG_DURATION("vector");
		vector<int> v;
		for (int i = 0; i < 100000; i++) {
			v.insert(begin(v), i);
		}
	}
	{
		LOG_DURATION("deque");
		deque<int> v;
		for (int i = 0; i < 100000; i++) {
			v.insert(begin(v), i);
		}
	}
	return 0;
}


int main2() {
	set<int> numbers;
	for (int i = 0; i < 3'000'000; i++) {
		numbers.insert(i);
	}
	const int x = 1'000'000;
	{
		LOG_DURATION("global lower_bound");
		cout << *lower_bound(begin(numbers), end(numbers), x);
	}
	{
		LOG_DURATION("lower_bound method");
		cout << *numbers.lower_bound(x);
	}
	return 0;
}

const int NUMBER_COUNT = 1000000;
const int NUMBER = 7654321;
const int QUERY_COUNT = 10;

int main() {
	vector<int> v;
	for (int i = 0; i < NUMBER_COUNT; i++) {
		v.push_back(i * 10);
	}
	{
		LOG_DURATION("lower_bound");
		for (int i = 0; i < QUERY_COUNT; i++) {
			lower_bound(begin(v), end(v), NUMBER);
		}
	}
	{
		LOG_DURATION("find_if");
		for (int i = 0; i < QUERY_COUNT; i++) {
			find_if(begin(v), end(v),
				[](int y) { return y >= NUMBER; });
		}
	}
	return 0;
}