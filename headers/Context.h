#ifndef HW5_CONTEXT_H
#define HW5_CONTEXT_H

#include <thread>
#include "Array.h"
#include "HonyPot.h"
#include "Logger.h"
#include <string>

class Bear {
    int id_;
    std::thread thread_;
    Logger *logger_;
    HoneyPot *honey_pot_;

public:
    void init(HoneyPot *honey_pot, Logger *logger, int id) {
        honey_pot_ = honey_pot;
        logger_ = logger;
        id_ = id;
    }

    void work() {
        join();
        thread_ = std::thread(&Bear::process, this);
    }

    void join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

private:
    void process() const {
        honey_pot_->clear();
        logger_->write("I am a bear and I love honey; value: " +
                       std::to_string(honey_pot_->value()) +
                       "; id: " +
                       std::to_string(id_) +
                       "\n");
    }
};

class Bee {
    int id_;
    std::thread thread_;
    Logger *logger_;
    HoneyPot *honey_pot_;

public:
    void init(HoneyPot *honey_pot, Logger *logger, int id) {
        honey_pot_ = honey_pot;
        logger_ = logger;
        id_ = id;
    }

    void work() {
        join();
        thread_ = std::thread(&Bee::process, this);
    }

    void join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

private:
    void process() const {
        honey_pot_->push();
        logger_->write("Bzzz.. ; value: " +
                       std::to_string(honey_pot_->value()) +
                       "; id: " +
                       std::to_string(id_) +
                       "\n");
    }
};

class Context {
    int iter_count_;
    HoneyPot honey_pot_;
    Bear bear_;
    Array<Bee> bees_;
    Logger *logger_;
public:
    Context(Logger *logger, int bee_count, int iter_count) :
            bees_(bee_count),
            honey_pot_(bee_count),
            iter_count_(iter_count),
            logger_(logger) {
        for (int i = 0; i < bees_.size(); ++i) {
            bees_[i].init(&honey_pot_, logger_, i);
        }
        bear_.init(&honey_pot_, logger_, 0);
    }

    ~Context() {
        for (int j = 0; j < bees_.size(); ++j) {
            bees_[j].join();
        }
        bear_.join();
    }

    void start() {
        for (int i = 0; i < iter_count_; ++i) {
            for (int j = 0; j < bees_.size(); ++j) {
                bees_[j].work();
            }
            for (int j = 0; j < bees_.size(); ++j) {
                bees_[j].join();
            }
            bear_.work();
        }
    }
};

#endif //HW5_CONTEXT_H
