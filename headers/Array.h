//
// Created by tagir on 14.12.2021.
//

#ifndef HW5_ARRAY_H
#define HW5_ARRAY_H
template <typename T>
class Array {
    T *data_;
    size_t capacity_;

public:
    explicit Array(size_t capacity) {
        data_ = new T[capacity];
        capacity_ = capacity;
    }

    Array(const Array &other) {
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < capacity_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    ~Array() {
        delete[] data_;
        capacity_ = 0;
    }

    void resize(size_t new_capacity) {
        auto new_data = new T[new_capacity];
        for (size_t i = 0; i < myMin(capacity_, new_capacity); ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    T &operator[](size_t idx) {
        return data_[idx];
    }

    T &operator[](size_t idx) const {
        return data_[idx];
    }

    size_t size() const {
        return capacity_;
    }
};
#endif //HW5_ARRAY_H
