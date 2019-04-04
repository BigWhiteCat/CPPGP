#include <iostream>

using namespace std;

template <int N, int M>
bool less(const char (&a)[N], const char (&b)[M]) {
    for (int i = 0; i != M && i != N; ++i) {
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
    char a[] = "1234";
    char b[] = "1243";

    std::cout << ::less(a, b) << std::endl;
    return 0;
}
