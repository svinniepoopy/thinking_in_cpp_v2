/*
 *  Create a generator that returns the current value of clock( ) (in <ctime>).
 *  Create a list<clock_t>, and fill it with your generator using generate_n( ).
 *  Remove any duplicates in the list and print it to cout using copy( ).
 */

#include <algorithm>
#include <ctime>
#include <list>
#include <iterator>
#include <iostream>

class ClockGen {
  public:
    clock_t operator()() {
      return clock();
    }
};

int main() {
  std::list<clock_t> lst;
  std::generate_n(std::inserter(lst, lst.end()),
      100,
      ClockGen()); 
  std::unique(lst.begin(), lst.end());
  std::copy(lst.begin(), lst.end(),
      std::ostream_iterator<clock_t>(std::cout, " "));
  return 0;
}
