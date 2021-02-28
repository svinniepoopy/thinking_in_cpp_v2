/*
 * Create an STL-style algorithm transform_if( ) following the first form of
 * transform( ) that performs transformations only on objects that satisfy a
 * unary predicate. Objects that don’t satisfy the predicate are omitted from
 * the result. It needs to return a new “end” iterator.
 */

#include <vector>
#include <iostream>

template<typename InputIt, typename OutputIt, class UnaryOp>
OutputIt transform_if(InputIt first1, InputIt last1, OutputIt d_first,
    UnaryOp op) {
  while (first1 != last1) {
    if (op(*first1)) {
      *d_first++ = op(*first1); 
    }
    ++first1;
  }
  return d_first;
}

bool IsEven(int k) {
  return k%2==1;
}

int main() {
  std::vector<int> E{2,4,6,5,8,9,10};
  std::vector<int> O;
  transform_if(E.begin(), E.end(), std::back_inserter(O), IsEven);
  auto it = O.begin();
  while (it != O.end()) {
    std::cout << *it << ' ';
    ++it;
  }
  return 0;
}
