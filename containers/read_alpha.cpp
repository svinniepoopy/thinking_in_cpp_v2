#include <iostream>

char ParseInput() {
  char input_val=0;
  do {
    std::cout << "Make a guess [-1 to quit]: ";
    if (!(std::cin>>input_val) || 
	!std::isalpha(input_val)) {
      std::cout << "you entered: " << input_val << '\n';
      if (std::cin.eof()) {
	exit(EXIT_FAILURE);
      }
      std::cout << "!!! Input should be a character !!!\n";
      std::cin.clear();
      std::cin.ignore(2, '\n');
    } else if (std::isalpha(input_val)) {
      break;
    }
  } while (!std::cin.eof());

  return input_val;
}

int main() {
  char c  = ParseInput();
  std::cout << "got: " << c << '\n';
  return 0;
}
