#ifndef HW5_HONEYPOT_H
#define HW5_HONEYPOT_H

#include <thread>
#include <mutex>

class HoneyPot {
    int value_;
    int max_value_;
    std::mutex mutex_;
    std::condition_variable var_;

    typedef std::lock_guard<std::mutex> lock;
public:
    explicit HoneyPot(int max_value);

    HoneyPot(const HoneyPot &other);

    void push();

    void clear();

    bool empty();

    bool full();

    int value();
};


#endif //HW5_HONEYPOT_H
