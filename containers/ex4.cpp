#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <set>
#include <iostream>
#include <iterator>
/*
 * Create a generator that produces random int values between 0 and 20 inclusive, 
 * and use it to fill a multiset<int>. Count the occurrences of each value, 
 * following the example given in MultiSetWordCount.cpp.
 */

struct IntGen {
  int operator()() {
    return rand()%9;
  }
};

int main() {
  // use default integer ordering
  std::multiset<int> M;
  IntGen gen;
  std::generate_n(std::inserter(M, M.begin()), 200, IntGen());
  // std::copy(M.begin(), M.end(), std::ostream_iterator<int>(std::cout, " "));
  auto it = M.begin();
  while (it != M.end()) {
    auto range = M.equal_range(*it);
    std::cout << *it << '\n';
    int count = std::distance(range.first, range.second); 
    std::cout << *it << " occurs " << count << " times.\n";
    it = range.second;
  }
  // std::copy(M.begin(), M.end(), std::ostream_iterator(std::cout, " "));
  return 0;
}
