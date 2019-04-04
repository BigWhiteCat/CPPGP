#include <iostream>

using namespace std;

template <typename T, int N, int M>
bool less(const T (&a)[N], const T (&b)[M]) {
    for (int i = 0; i != N && i != M; ++i) {
        if (a[i] < b[i]) {
            return true;
        }
        if (b[i] < a[i]) {
            return false;
        }
    }
    return N < M;
}

int main() {
    const char a[] = "1234";
    const char b[] = "1243";

    cout << ::less(a, b) << std::endl;
    return 0;
}
