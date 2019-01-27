#include <iostream>

int main() {
    int sum = 0;
    int initialValue = 50;
    int endValue = 100;

    while (initialValue <= endValue) {
        sum += initialValue;
        ++initialValue;
    }

    std::cout << "The sum from 50 to 100 is " << sum << std::endl;
    return 0;
}
