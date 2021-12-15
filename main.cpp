#include <iostream>
#include "headers/context.h"

int main(int argc, char **argv) {
    if (argc < 5 || argc > 6) {
        std::cout << "Error!";
        exit(1);
    }

    Logger *logger;
    int bee_count;
    int volume_pot_honey;
    int iter_count;

    if (!strcmp("-f", argv[1])) {
        if (argc != 6) {
            std::cout << "Error!";
            exit(1);
        }
        logger = new FileLogger(argv[2]);
        bee_count = atoi(argv[3]);
        volume_pot_honey = atoi(argv[4]);
        iter_count = atoi(argv[5]);
    } else if (!strcmp("-c", argv[1])) {
        if (argc != 5) {
            std::cout << "Error!";
            exit(1);
        }
        logger = new ConsoleLogger;
        bee_count = atoi(argv[2]);
        volume_pot_honey = atoi(argv[3]);
        iter_count = atoi(argv[4]);
    } else {
        std::cout << "Error!";
        exit(1);
    }

    Context context(logger, bee_count, volume_pot_honey, iter_count);
    context.start();

    delete logger;
    return 0;
}
