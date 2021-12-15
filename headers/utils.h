#ifndef HW5_UTILS_H
#define HW5_UTILS_H
template <typename T>
T myMax(T left, T right) {
    if (left > right) {
        return left;
    }
    return right;
}

template <typename T>
T myMin(T left, T right) {
    if (left < right) {
        return left;
    }
    return right;
}
#endif //HW5_UTILS_H
