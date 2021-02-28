/*
 * Create a kind of “hangman” game. Create a class that contains a char and a
 * bool to indicate whether that char has been guessed yet. Randomly select a
 * word from a file, and read it into a vector of your new type. Repeatedly ask
 * the user for a character guess, and after each guess, display the characters
 * in the word that have been guessed, and display underscores for the
 * characters that haven’t. Allow a way for the user to guess the whole word.
 * Decrement a value for each guess, and if the user can get the whole word
 * before the value goes to zero, they win.
 */

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <list>
#include <unordered_map>

class WordGuess {
  public:
    WordGuess(){}

    void init() {
      ifs.open("./words");
      try {
	if (!ifs.is_open()) {
	  throw std::runtime_error{"Error opening file\n"};
	}
      } catch(std::runtime_error& err) {
	std::cout << err.what();
      }
      std::vector<std::string> words;
      for (std::string line; std::getline(ifs, line);) {
	words.push_back(line);
      }
      srand(time(nullptr));
      word = words[rand()%words.size()];
      CreateMap();
      guess = std::string(word.size(), '_');
      std::cout << "current word: " << word << '\n';    
    }

    char ParseInput() {
      char input_val=0;
      do {
	std::cout << "Make a guess [-1 to quit]: ";
	if (!(std::cin>>input_val)) {
	  if (std::cin.eof()) {
	    exit(EXIT_FAILURE);
	  }
	  std::cout << "Input should be a character\n";
	  std::cin.clear();
	  std::cin.ignore(1000, '\n');
	} else if (std::isalpha(input_val)) {
	  break;
	}
      } while (!std::cin.eof());
      return input_val;
    }

    bool IsCorrectGuess() {
      return word.compare(guess) == 0;
    }

    void AddGuess(const char c) {
      auto it = M.find(c);
      if (it != M.end()) {
	int pos = it->second.front();
	it->second.pop_front();
	guess[pos] = c;
      }
    }

    const std::string& CurrentWord() const {
      return guess;
    }

    const std::string& Word() const {
      return word;
    }

    int Chances() const {
      return nguesses;
    }

    void Decr() {
      --nguesses;
    }

  private:

    void CreateMap() {
      for (int i=0;i<word.size();++i) {
	M[word[i]].push_back(i);
      }
    }

    int nguesses = 20;
    std::string guess;
    std::string word;
    std::ifstream ifs;
    std::unordered_map<char, std::list<int>> M;
};


void HangMan() {
  WordGuess guesser;
  guesser.init();
  while (guesser.Chances()>=1) {
    char c = guesser.ParseInput();
    guesser.AddGuess(c);
    if (guesser.IsCorrectGuess()) {
      std::cout << "You guessed correctly: " << guesser.Word() << '\n';
    } else {
      std::cout << "Make another guess: " << guesser.CurrentWord() << '\n';
    }
    guesser.Decr();
  }
  if (guesser.Chances()==0 && (guesser.Word() != guesser.CurrentWord())) {
    std::cout << "You exhausted all guesses\n";
    std::cout << "Word: " << guesser.Word() << '\n';
  }
}

int main(int argc, char** argv) {
  HangMan();
  return 0;
}
