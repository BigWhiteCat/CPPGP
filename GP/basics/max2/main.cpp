#include <iostream>

using namespace std;

int max(int a, int b) {
    return b < a ? a : b;
}

template <typename T>
T max(T a, T b) {
    return b < a ? a : b;
}

int main() {
    cout << ::max(7, 42) << endl;
    cout << ::max(7.0, 42.0) << endl;
    cout << ::max('a', 'b');
    cout << ::max<>(7, 42) << endl;
    cout << ::max<double>(7, 42) << endl;
    cout << ::max('a', 42.7) << endl;
    return 0;
}
