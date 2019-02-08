#ifndef MAX1_HPP
#define MAX1_HPP

template <typename T>
T max(T a, T b) {
    return b < a ? a : b;
}

#endif  // MAX1_HPP
