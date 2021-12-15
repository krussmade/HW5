#include "../headers/honeyPot.h"

HoneyPot::HoneyPot(int max_value) {
    this->value_ = 0;
    this->max_value_ = max_value;
}

HoneyPot::HoneyPot(const HoneyPot &other) {
    this->value_.store(other.value_);
    this->max_value_ = other.max_value_;
}

bool HoneyPot::empty() {
//    lock l(mutex_);
    return value_ == 0;
}

bool HoneyPot::full() {
//    lock l(mutex_);
    return value_ == max_value_;
}

void HoneyPot::push() {
//    lock l(mutex_);
    value_++;
}

void HoneyPot::clear() {
//    lock l(mutex_);
    this->value_ = 0;
}

int HoneyPot::value() {
//    lock l(mutex_);
    return this->value_;
}

