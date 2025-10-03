#include "write.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Using: " << argv[0] << " <fileName>, <parentDelay>, <child1Delay>, <child2Delay>" << std::endl;
        return 1;
    }

    const char* fileName = argv[1];
    int parentDelay = atoi(argv[2]);
    int child1Delay = atoi(argv[3]);
    int child2Delay = atoi(argv[4]);

    //Prepare file
    std::ofstream out(fileName, std::ios::trunc);
    if (!out.is_open()) {
        std::cerr << "Error: could not open or create file" << fileName << std::endl;
        return 1;
    }

    out << "Delayed launch: Parent: " << parentDelay << " sec, Child 1: " << child1Delay << " sec, Child 2: " << child2Delay << " sec." << std::endl;
    out << "_________________________________________" << std::endl;
    out.close();

    //Forking first child
    pid_t child1_pid = fork();

    if (child1_pid < 0) {
        perror("Could not fork");
        return 1;
    }

    if (child1_pid == 0) {
        sleep(child1Delay);
        Write(fileName, "Child 1 (forked)");
        exit(0); //kill child 1
    }

    //VForking second child
    pid_t child2_pid = vfork();

    if (child2_pid < 0) {
        perror("Could not vfork");
        return 1;
    }

    if (child2_pid == 0) {
        execl("./child2", "./child2", fileName, argv[4], (char*)NULL);
        perror("Could not execl");
        _exit(1);
    }

    //Parent logic
    sleep(parentDelay);
    Write(fileName, "Parent");

    waitpid(child1_pid, NULL, 0);
    waitpid(child2_pid, NULL, 0);

    return 0;
}
