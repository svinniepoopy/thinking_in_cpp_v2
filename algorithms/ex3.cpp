
#include <algorithm>
#include <cassert>
#include <vector>

struct Sum {
  void operator()(int i) {
    s+=i;
  }
  int s;
};

int main() {
  std::vector<int> V(100, 1);
  Sum sum;
  sum = std::for_each(V.begin(), V.end(), sum);
  assert(sum.s == 100);
  return 0;
}
