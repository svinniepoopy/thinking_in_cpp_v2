/* Use a stack<int> and populate it with a Fibonacci sequence. The program’s
 * command line should take the number of Fibonacci elements desired, and you 
 * should have a loop that looks at the last two elements on the stack and pushes 
 * a new one for every pass through the loop.
 */

#include <iostream>
#include <stack>
#include <iterator>
#include <vector>
int main() {
  int n=20;
  std::stack<int> stk;
  stk.push(0);
  stk.push(1);
  int b = 0;
  for (int i=2;i<20;++i) {
    int a = stk.top();
    stk.push(a + b);
    b = a;
  }
  std::vector<int> A;
  while (!stk.empty()) {
    A.push_back(stk.top());
    stk.pop();
  }
  std::copy(A.rbegin(), A.rend(), std::ostream_iterator<int>(std::cout, " "));

  return 0;
}
 
