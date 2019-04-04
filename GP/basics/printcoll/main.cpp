#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
void printcoll(const T &coll) {
    typename T::const_iterator pos;
    typename T::const_iterator end(coll.end());

    for (pos = coll.begin(); pos != end; ++pos) {
        std::cout << *pos << "  ";
    }
}

int main() {
    vector<int> intVec{1, 2, 3};
    deque<int> intDeq{1, 2, 3};

    printcoll(intVec);
    std::cout << endl;
    printcoll(intDeq);
    return 0;
}
