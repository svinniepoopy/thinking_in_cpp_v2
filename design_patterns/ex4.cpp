/*
 * Modify KissingPrincess2.cpp by adding another state to the system, so that
 * each kiss cycles the creature to the next state.
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Creature {
  private:
    class State {
      public:
	virtual std::string response() = 0;
    };

    class Frog : public State {
      public:
	std::string response() {
	  return "toaddd\n";
	}
    };

    class Prince : public State {
      public:
	std::string response() {
	  return "bitch\n";
	}
    };

    class Demon : public State {
      public:
	std::string response() {
	  return "darlin\n";
	}
    };

    int curr_state;
    std::vector<std::unique_ptr<State>> states;

  public:
    Creature():curr_state{0} {
      states.push_back(std::make_unique<Frog>());
      states.push_back(std::make_unique<Prince>());
      states.push_back(std::make_unique<Demon>());
    }

    void greet() {
      std::cout << states[curr_state]->response();
    }

    void kiss() {
      curr_state = (curr_state+1)%3;
    }
};

int main() {
  Creature c;
  for (int i=0;i<4;++i) {
    c.greet();
    c.kiss();
  }
  return 0;
}
