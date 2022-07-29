#include <cstdint>
#include <queue>

using namespace std;

class EventManager {
public:
	void Add(uint64_t time) { //O(Q)
		Adjust(time);
		events.push(time); //O(1)
	}
	int Count(uint64_t time) { //O(Q)
		Adjust(time);
		return events.size();//O(1)S
	}
private:
	queue<uint64_t> events;
	
	void Adjust(uint64_t time) { //O(Q)
		while (!events.empty() && events.front() <= time - 300) { //O(Q)
			events.pop(); //O(1)
		}
	}
};

int main() {
	return 0;
}