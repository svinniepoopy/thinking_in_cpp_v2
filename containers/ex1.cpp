
/*
 * Create a set<char>, open a file (whose name is provided on the command line)
 * and read that file in a char at a time, placing each char in the set. 
 * Print the results, and observe the organization. Are there any letters in 
 * the alphabet that are not used in that particular file?
 */

#include <set>
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  if (argc<2) {
    return -1;
  }
  std::string filename{argv[1]};
  {
    std::ifstream ifs{filename};
    std::set<char> char_set;
    std::istream_iterator<char> it{ifs};
    std::copy(it, std::istream_iterator<char>{}, std::inserter(char_set, char_set.end()));

    for (char c:char_set) {
      std::cout << c << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
