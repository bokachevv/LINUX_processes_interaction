#include "write.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>

void Write(const char* fileName, const std::string& processName) {
    std::ofstream out(fileName, std::ios::app);
    if (!out.is_open()) {
        std::cerr << "Error: could not open file" << fileName << std::endl;
        return;
    }

    pid_t pid = getpid();
    out << processName << ":" << std::endl;
    out << " - Process ID (PID): " << pid << std::endl;
    out << " - Parent ID (PPID): " << getppid() << std::endl;
    out << " - Session ID (SID): " << getsid(pid) << std::endl;
    out << " - Processes group ID (PGID): " << getpgid(pid) << std::endl;
    out << " - User ID (UID): " << getuid() << std::endl;
    out << " - Effective user ID (EUID): " << geteuid() << std::endl;
    out << "_________________________________________" << std::endl;
}
