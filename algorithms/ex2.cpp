/*
 * Using transform( ) and toupper( ) (in <cctype>), write a single function call
 * that will convert a string to all uppercase letters.
 */


#include <algorithm>
#include <string>
#include <iostream>

int main() {
  std::string mixed_case{"aBcDeFgH"};
  std::transform(mixed_case.begin(), mixed_case.end(),
      mixed_case.begin(),
      [](char c) {
      return std::toupper(c);
      });
  std::cout << mixed_case << '\n';
  return 0;
}
