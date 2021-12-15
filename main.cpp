#include <iostream>
#include "headers/context.h"

int main(int argc, char **argv) {
//    if (argc < 2 || argc > 4) {
//        std::cout << "Error!";
//        exit(1);
//    }

    Logger *logger;

//    if (!strcmp("-f", argv[0])) {
//        logger = new FileLogger(argv[1]);
//    } else if (!strcmp("-c", argv[0])) {
//        if (argc != 4) {
//            std::cout << "Error!";
//            exit(1);
//        }
        logger = new ConsoleLogger;
//    } else {
//        std::cout << "Error!";
//        exit(1);
//    }

    Context context(logger, 2, 10, 10);
    context.start();
    return 0;
}
