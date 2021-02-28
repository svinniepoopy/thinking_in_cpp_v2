#include <ctime>
#include <list>
#include <algorithm>
#include <cstdio>
#include <iostream>

void fill(std::list<int>& l) {
  srand(time(nullptr));
  for (int i=0;i<1000;++i) {
    l.push_front(rand());
  }
}

int main() {
  std::list<int> l;
  fill(l);
  std::list<int> l2{l};
  clock_t ticks = clock();
  l.sort();
  clock_t d = clock()-ticks;
  std::cout << "list sort: " << d << '\n';
  ticks = clock();
  std::stable_sort(l.begin(), l.end());
  d = clock()-ticks;
  std::cout << "std sort: " << d << '\n';
  return 0;
}
