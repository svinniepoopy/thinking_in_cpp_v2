#include <cassert>
#include <iostream>
#include <thread>
#include <vector>

int ncopies = 0;

class Singleton {
  public:
    static Singleton& Instance() {
      static Singleton s{42};
      return s;
    }

    int get() { return i; }
    void set(int x) { i = x; }
  private:
    int i;
    Singleton(int x):i{x} {++ncopies;}
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton)=delete;
};

struct runner {
  void operator()() {
    Singleton& s = Singleton::Instance();
    //std::cout << s.get() << '\n';
    s.set(2);
    //std::cout << s.get() << '\n';
    auto& s2 = Singleton::Instance();
    s.set(22);
    std::cout << std::this_thread::get_id() << ' ';
    assert(ncopies == 1);
  }
};

int main() {
  std::vector<std::thread> threads;
  for (int i=0;i<100;++i) {
    threads.emplace_back(runner());
  }
  for (auto& t:threads) {
    t.join();
  }
  return 0;
}
