/*
 * Open a file and read it into a single string. Turn the string into a
 * stringstream. Read tokens from the stringstream into a list<string> using a
 * TokenIterator.
 */

#include <algorithm>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include <sstream>
#include <iostream>

int main() {
  std::ifstream ifs{"ex15.cpp"};
  std::string s;
  std::copy(
      std::istream_iterator<char>{ifs},
      std::istream_iterator<char>{},
      std::back_inserter(s));
  std::stringstream stream{s};
  std::list<std::string> lst;
  std::copy(std::istream_iterator<std::string>{stream},
      std::istream_iterator<std::string>{},
      std::back_inserter(lst));

  std::copy(lst.begin(), lst.end(),
      std::ostream_iterator<std::string>(std::cout, " "));

  return 0;
}
