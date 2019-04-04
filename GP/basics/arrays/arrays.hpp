#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>

/*!
 * \brief primary template
 */
template <typename T>
class MyClass;

/*!
 * \brief partial specialization for arrays of known bounds
 */
template <typename T, std::size_t SZ>
class MyClass<T[SZ]> {
    static void print() {
        std::cout << "print() for T[" << SZ << "]\n";
    }
};

/*!
 * \brief partial specialization for reference to arrays of known bounds
 */
template <typename T, std::size_t SZ>
class MyClass<T (&)[SZ]> {
    static void print() {
        std::cout << "print() for T(&)[" << SZ << "]\n";
    }
};

#endif  // ARRAYS_HPP
