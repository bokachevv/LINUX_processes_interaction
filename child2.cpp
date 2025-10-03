#include "write.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Child 2: false arguments count" << std::endl;
        return 1;
    }

    const char* fileName = argv[1];
    int delay = atoi(argv[2]);

    sleep(delay);

    Write(fileName, "Child 2 (vforked)");

    return 0;
}