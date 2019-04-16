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

void f(X &value) {
    g(value);
}

void f(const X &value) {
    g(value);
}

void f(X &&value) {
    g(std::move(value));
}

int main() {
    X v;       /*!< create variable */
    X const c; /*!< create constant */

    f(v);            /*!< for nonconstant object f(X &) */
    f(c);            /*!< for constant object f(const X &)*/
    f(X());          /*!< for temprary object f(X &&value)*/
    f(std::move(v)); /*!< for movable object f(X &&value) */

    return 0;
}
