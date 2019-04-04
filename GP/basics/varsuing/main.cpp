#include <iostream>
#include <string>
#include <unordered_set>

class Customer {
  public:
    Customer(std::string const &n) : name(n) {
    }
    std::string getName() const {
        return name;
    }

  private:
    std::string name;
};

struct CustomerEq {
    bool operator()(const Customer &lh, const Customer &rh) const {
        return lh.getName() == rh.getName();
    }
};

struct CustomerHash {
    std::size_t operator()(Customer const &c) const {
        return std::hash<std::string>()(c.getName());
    }
};

template <typename... Bases>
struct OverLoader : Bases... {
    using Bases::operatro()...;
};

int main() {
    using CustomerOP = OverLoader<CustomerHash, CustomerEq>;
    std::unordered_set<Customer, CustomerHash, CustomerEq> coll1;
    std::unordered_set<Customer, CustomerOP, CustomerOP> coll2;

    return 0;
}
