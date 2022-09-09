#include "profile.h"

#include <iostream>
#include <algorithm>

#include <list>
#include <vector>
#include <deque>

using namespace std;

size_t RAND(size_t a, size_t b) {
	return a + rand() % (b - a + 1);
}

template<typename Cont>
void Operations(Cont& numbers, size_t& size) {
	size_t n = size;

	if (n > 100000) {
		throw invalid_argument("");
	}
	//vector<numbers::iterator> pos(100'000 + 1, numbers.end());
	
	while (n != 0) {
		size_t current = RAND(0, 20), after = RAND(0, 20);

		/*auto it = numbers.end();

		for (auto it_1 = numbers.begin(); it_1 != numbers.end(); ++it_1) {
			if (*it_1 == after) {
				it = it_1;
				break;
			}
		}*/

		auto it = find(numbers.begin(), numbers.end(), after);

		if (it != end(numbers)) {
			numbers.insert(it, current);
		}
		else {
			numbers.push_back(current);
		}
		--n;
	}	
	for (auto item : numbers) {
		//cout << item << "\n";
	}
}


void all_variants() {
	{
		LOG_DURATION("list");

		size_t n = 100000;

		list<size_t> numbers;

		Operations(numbers, n);
	}	
	{
		LOG_DURATION("deque");

		size_t n = 100000;

		deque<size_t> numbers;

		Operations(numbers, n);
	}
	{
		LOG_DURATION("vector");

		size_t n = 100000;

		vector<size_t> numbers;

		Operations(numbers, n);
	}
}

int main1() {
	all_variants();
	return 0;
}


int main() {	
	size_t n;
	cin >> n;
	if (n > 100000) {
		throw invalid_argument("");
	}

	list<size_t> numbers;
	vector<list<size_t>::iterator> pos(100'000 +1, numbers.end());

	while (n != 0) {
		size_t current, after;
		cin >> current >> after;			
		pos[current] = numbers.insert(pos[after], current);		
		--n;
	}	
	for (auto item : numbers) {
		cout << item << "\n";
	}
	return 0;
}