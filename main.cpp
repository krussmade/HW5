#include <iostream>
#include "headers/context.h"

int main() {
    Context context(new ConsoleLogger, 5, 5);
    context.start();
    return 0;
}
