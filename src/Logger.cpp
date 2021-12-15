//
// Created by tagir on 15.12.2021.
//

#include "../headers/Logger.h"

FileLogger::FileLogger(const std::string &path) {
    out_logg_.open(path);
    if (!out_logg_.is_open()) {
        throw "Path is not valid";
    }
}

void ConsoleLogger::write(const std::string &log) {
    lock l(mutex_);
    std::cout << log;
}

void FileLogger::write(const std::string &log) {
    lock l(mutex_);
    out_logg_ << log;
}

Logger::~Logger() {

}

ConsoleLogger::~ConsoleLogger() {

}

FileLogger::~FileLogger() {
    if (out_logg_.is_open()) {
        out_logg_.close();
    }
}


