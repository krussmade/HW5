#ifndef HW5_CONTEXT_H
#define HW5_CONTEXT_H

#include <thread>
#include "array.h"
#include "honeyPot.h"
#include "logger.h"
#include <string>

class Bear {
    int id_;
    std::thread thread_;
    Logger *logger_;
    HoneyPot *honey_pot_;

public:
    Bear(HoneyPot *honey_pot, Logger *logger, int id) {
        honey_pot_ = honey_pot;
        logger_ = logger;
        id_ = id;
    }

    void work() {
        join();
        thread_ = std::thread([](HoneyPot *honey_pot, Logger *logger, int id) {
            if (!honey_pot->full()) {
                return;
            }
            honey_pot->clear();
            logger->write("I am a bear and I love honey; value: " +
                          std::to_string(honey_pot->value()) +
                          "; id: " +
                          std::to_string(id) +
                          "\n");
        }, honey_pot_, logger_, id_);
    }

    void join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }
};

class Bee {
    int id_;
    std::thread thread_;
    Logger *logger_;
    HoneyPot *honey_pot_;

public:
    Bee(HoneyPot *honey_pot, Logger *logger, int id) {
        honey_pot_ = honey_pot;
        logger_ = logger;
        id_ = id;
    }

    void work() {
        join();
        thread_ = std::thread([](HoneyPot *honey_pot, Logger *logger, int id) {
            if (honey_pot->full()) {
                return;
            }
            honey_pot->push();
            logger->write("Bzzz.. ; value: " +
                          std::to_string(honey_pot->value()) +
                          "; id: " +
                          std::to_string(id) +
                          "\n");
        }, honey_pot_, logger_, id_);
    }

    void join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }
};

class Bees {
    Array<Bee *> bees_;
    HoneyPot *honey_pot_;
    Logger *logger_;
public:
    Bees(HoneyPot *honey_pot, Logger *logger, int bee_count) :
            bees_(bee_count),
            honey_pot_(honey_pot),
            logger_(logger) {
        for (int i = 0; i < bees_.size(); ++i) {
            bees_[i] = new Bee(honey_pot_, logger_, i);
        }
    }

    void work() {
        while (!honey_pot_->full()) {
            for (int j = 0; j < bees_.size(); ++j) {
                bees_[j]->work();
            }
        }
    }

    void join() {
        for (int j = 0; j < bees_.size(); ++j) {
            bees_[j]->join();
        }
    }

    ~Bees() {
        for (int i = 0; i < bees_.size(); ++i) {
            delete bees_[i];
        }
    }
};

class Context {
    int iter_count_;
    HoneyPot honey_pot_;
    Bear bear_;
    Bees bees_;
public:
    Context(Logger *logger, int bee_count, int honey_pot_volume, int iter_count) :
            honey_pot_(honey_pot_volume),
            iter_count_(iter_count),
            bees_(&honey_pot_, logger, bee_count),
            bear_(&honey_pot_, logger, 0) {
    }

    ~Context() {
        bees_.join();
        bear_.join();
    }

    void start() {
        for (int i = 0; i < iter_count_; ++i) {
            bees_.work();
            bees_.join();
            bear_.work();
            bear_.join();
        }
    }
};

#endif //HW5_CONTEXT_H
