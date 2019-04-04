#include <iostream>
#include <type_traits>

using namespace std;

template <typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
RT max(T1 a, T2 b) {
    return b < a ? a : b;
}

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
