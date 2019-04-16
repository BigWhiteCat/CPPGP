#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Person {
  public:
    explicit Person(const std::string &n) : name(n) {
        std::cout << "copying string constructor for '" << name << "'\n";
    }

    Person(const std::string &&n) : name(std::move(n)) {
        std::cout << "moving string constructor for '" << name << "'\n";
    }

    Person(const Person &p) : name(p.name) {
        std::cout << "COPY-CONSTR person '" << name << "'\n";
    }

    Person(Person &&p) : name(std::move(p.name)) {
        std::cout << "MOVE-CONSTR Person '" << name << "'\n";
    }

  private:
    std::string name;
};

int main() {
    std::string s = "sname";
    Person p1(s);              // copying constructor
    Person p2("tmp");          // moving constructor
    Person p3(p1);             // copy person;
    Person p4(std::move(p1));  // move person

    return 0;
}
