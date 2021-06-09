#include <iostream>
#include "CommandLineArgsParser.h"

int main(int argc, char **argv) {
    CommandLineArgsParser X(argc, argv);
    std::vector<Flags> flags;
    X.validateFlags(flags);
    return 0;
}
