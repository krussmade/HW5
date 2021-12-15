#include <iostream>
#include "headers/Context.h"

int main() {
    Context context(new ConsoleLogger, 5, 5);
    context.start();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
