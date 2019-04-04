#ifndef MAXDECLTYPEDECAY_H
#define MAXDECLTYPEDECAY_H

#include <type_traits>

template <typename T1, typename T2>
auto max(T1 a, T2 b) -> typename std::decay<decltype(b < a ? a : b)>::type {
    b < a ? a : b;
}

#endif  // MAXDECLTYPEDECAY_H
