#include "profile.h"
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main() {
	const int SIZE = 5000000;

	vector<int> v;
	{
		LOG_DURATION("vector");
		for (int i = 0; i < SIZE; ++i) {
			v.push_back(i);
		}
	}
	deque<int> d;
	{
		LOG_DURATION("deque");
		for (int i = 0; i < SIZE; ++i) {
			d.push_back(i);
		}
	}

	return 0;
}