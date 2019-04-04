#ifndef MAXCOMMON_HPP
#define MAXCOMMON_HPP

#include <type_traits>

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type max(T1 a, T2 b) {
    b < a ? a : b;
}

#endif  // MAXCOMMON_HPP
