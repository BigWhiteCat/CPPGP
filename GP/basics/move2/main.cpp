#include <iostream>
#include <utility>

using namespace std;

class X {
  public:
    X() {
    }
};

void g(X &) {
    std::cout << "g() for variable \n";
}

void g(const X &) {
    std::cout << "g() for constant \n";
}

void g(X &&) {
    std::cout << "g() for movable object \n";
}

template <typename T>
void f(T &&val) {
    g(std::forward<T>(val));
}

int main() {
    return 0;
}
