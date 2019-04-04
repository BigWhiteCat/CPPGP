#ifndef MAXDECLTYPE_H
#define MAXDECLTYPE_H

template <typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b < a ? a : b) {
    return b < a ? a : b;
}

#endif  // MAXDECLTYPE_H
