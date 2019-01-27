#include <iostream>

int main() {
    int initialValue = 10;
    int endValue = 0;

    while (initialValue >= endValue) {
        std::cout << initialValue << std::endl;
        --initialValue;
    }
    return 0;
}
