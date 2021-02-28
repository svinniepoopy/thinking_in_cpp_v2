/*Create a class hierarchy with a base class B and a derived class D. Put a
 * virtual member function void f( ) in B such that it will print a message
 * indicating that B’s f( ) was called, and redefine this function for D to
 * print a different message. Create a vector<B*>, and fill it with B and D
 * objects. Use for_each( ) to call f( ) for each of the objects in your
 * vector.
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

class B {
  public:
    B()=default;
    virtual void foo() {
      std::cout << "B::foo()\n";
    }
    virtual ~B() {}
};

class D :public B {
  public:
    D()=default;
    void foo() {
      std::cout << "D:foo()\n";
    }
};

struct Op {
  void operator()(B* b) {
    b->foo();
  }
};

int main() {
  std::vector<B*> v;
  for (int i=0;i<10;++i) {
    v.push_back(new B{});
  }
  for (int i=0;i<10;++i) {
    v.emplace_back(new D{});
  }

  std::for_each(v.begin(), v.end(), Op()); 
  return 0;
}
