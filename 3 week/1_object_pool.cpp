#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>

using namespace std;

template <class T>
class ObjectPool {
public:
	T* Allocate() {
		if (!d_obj.empty()) {
			auto ro_ptr = d_obj.front();
			a_obj.insert(ro_ptr);
			d_obj.pop_front();
			return ro_ptr;
		}
		T* t_ptr = new T;
		a_obj.insert(t_ptr);
		return t_ptr;
	}

	T* TryAllocate() {
		if (d_obj.empty()) {
			return nullptr;
		}
		return Allocate();
	}

	void Deallocate(T* object) {
		if (a_obj.find(object) == a_obj.end()) {
			throw invalid_argument("");
		}
		d_obj.push_back(*a_obj.find(object));
		a_obj.erase(object);
	}

	~ObjectPool() {
		for_each(a_obj.begin(), a_obj.end(), default_delete<T>());
		for_each(d_obj.begin(), d_obj.end(), default_delete<T>());
	}

private:
	set<T*> a_obj;
	deque<T*> d_obj;
	// Добавьте сюда поля
};

void TestObjectPool() {
	ObjectPool<string> pool;

	auto p1 = pool.Allocate();
	auto p2 = pool.Allocate();
	auto p3 = pool.Allocate();

	*p1 = "first";
	*p2 = "second";
	*p3 = "third";

	pool.Deallocate(p2);
	ASSERT_EQUAL(*pool.Allocate(), "second");

	pool.Deallocate(p3);
	pool.Deallocate(p1);
	ASSERT_EQUAL(*pool.Allocate(), "third");
	ASSERT_EQUAL(*pool.Allocate(), "first");

	pool.Deallocate(p1);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestObjectPool);
	return 0;
}
