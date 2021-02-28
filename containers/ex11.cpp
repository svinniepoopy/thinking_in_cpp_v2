/*
 * Create a class that has an operator< and an ostream& operator<<. The class
 * should contain a priority number. Create a generator for your class that
 * makes a random priority number. Fill a priority_queue using your generator,
 * and then pull the elements out to show they are in the proper order.
 */

#include <queue>
#include <vector>
#include <iostream>

class PQGen {
  public:
    PQGen()=default;
    void operator()() {
      pq.push(rand());
    }
    friend std::ostream& operator<<(std::ostream& o, const PQGen& gen) {
      auto pq{gen.pq};
      while (!pq.empty()) {
	o << pq.top() << " ";
	pq.pop();
      }
      return o;
    }
  private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
};

int main() {
  PQGen gen;
  for (int i=0;i<100;++i) {
    gen();
  }
  std::cout << gen << '\n';
  return 0;
}
