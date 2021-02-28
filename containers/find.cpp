#include <string>
#include <iostream>

int main() {
  std::string w{"abcdef"};
  auto pos = w.find('a');
  if (pos != std::string::npos) { 
    w[pos] = '_';
  }
  std::cout << w << '\n';
}
