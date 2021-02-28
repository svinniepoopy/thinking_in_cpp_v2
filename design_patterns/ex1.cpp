/*
 *  Create a variation of SingletonPattern.cpp where all functions are static.
 *  Is the instance( ) function still necessary in this case?
 */

#include <iostream>

class Singleton {
  public:
    /*
    static Singleton& instance() {
      return s;
    }*/

    static int get() {
      return s.i;
    }

    static void set(int x) {
      s.i = x;
    }
  private:
    int i;
    static Singleton s;
    Singleton(int x):i{x}{}
    Singleton& operator=(const Singleton&)=delete;
    Singleton(const Singleton&)=delete;

};

Singleton Singleton::s{42};

int main() {
  std::cout << Singleton::get() << '\n';
  Singleton::set(10);
  std::cout << Singleton::get() << '\n';

  return 9;
}
