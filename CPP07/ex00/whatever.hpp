#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
const T &min(T const &x, T const &y) {
    if (x < y)
        return (x);
    return (y);
}

template <typename T>
const T &max(T const &x, T const &y) {
    if (x > y)
        return (x);
    return (y);
}

#endif