
/*
 * Create three sequences of Noisy objects, a vector, deque, and list. 
 * Sort them. Now write a function template to receive the vector and deque 
 * sequences as a parameter to sort them and record the sorting time. 
 * Write a specialized template function to do the same for list 
 * (ensure to call its member sort( ) instead of the generic algorithm). 
 * Compare the performance of the different sequence types
 */

#include "noisy.h"

#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <list>

long Noisy::create = 0, Noisy::assign = 0,
     Noisy::copycons = 0, Noisy::destroy = 0;
NoisyReport NoisyReport::nr;

template<typename Cont>
void sort(Cont& c) {
  std::sort(c.begin(), c.end());
}

template<>
void sort(std::list<Noisy>& lst) {
  lst.sort();
}

int main() {
  //std::vector<Noisy> v(1000);
 //std::deque<Noisy> d(1000);
  //std::list<Noisy> l(1000);
  clock_t ticks = clock();
  sort(v);
  std::cout << clock()-ticks << '\n';
  /*
  ticks = clock();
  sort(d);
  std::cout << clock()-ticks << '\n';
  ticks = clock();
  sort(l);
  std::cout << clock()-ticks << '\n';
  */
  return 0;
}
