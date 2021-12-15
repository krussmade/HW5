#ifndef HW5_LOGGER_H
#define HW5_LOGGER_H

#include <iostream>
#include <fstream>
#include <mutex>

class Logger {
protected:
    std::mutex mutex_;
    typedef std::lock_guard<std::mutex> lock;
public:
    virtual void write(const std::string &log) = 0;

    virtual ~Logger() = 0;
};

class ConsoleLogger : public Logger {
public:
    void write(const std::string &log) override;

    ~ConsoleLogger() override;
};

class FileLogger : public Logger {
    std::ofstream out_logg_;
public:
    explicit FileLogger(const std::string &path);

    ~FileLogger() override;

    void write(const std::string &log) override;
};

#endif //HW5_LOGGER_H
