#include <iostream>
#include "CommandLineArgsParser.h"
#include "OperationsHandler.h"
#include "CallbackManager.h"

int main(int argc, char **argv) {
    CommandLineArgsParser parser(argc, argv);
    std::vector<Flags> flags;
    parser.validateFlags(flags);
    OperationsHandler handler{ parser };
    CallbackManager manager{ handler };
    manager.callOperations(flags);

    return 0;
}
