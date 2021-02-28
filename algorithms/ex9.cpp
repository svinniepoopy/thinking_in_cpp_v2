
/*
 * Write a program that takes an integer as a command line argument and finds
 * all of its factors.
 */

#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

std::vector<int> Factorize(int n) {
  std::vector<int> factors;
  for (int i=2;i<=n/2;++i) {
    if (n%i==0) {
      factors.push_back(i);
    }
  }
  if (factors.empty()) {
    factors.push_back(n);
  }
  return factors;
}

int main(int argc, char** argv) {
  if (argc<2) {
    return 1;
  }
  std::stringstream istr{std::string{argv[1]}};
  int n=0;
  istr>>n;
  auto factors = Factorize(n);
  std::cout << "Factors of " << n << ": ";
  std::copy(factors.begin(), factors.end(),
      std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
  return 0;
}
