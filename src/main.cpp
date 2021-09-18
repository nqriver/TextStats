#include <iostream>
#include "CommandLineArgsParser.h"
#include "OperationsHandler.h"
#include "CallbackManager.h"
#include "InvalidCmdArgumentsException.h"

int main(int argc, char **argv) {
    try {
        CommandLineArgsParser parser(argc, argv);
        std::vector<Flags> flags;
        parser.validateFlags(flags);
        OperationsHandler handler{parser};
        CallbackManager manager{handler};
        manager.callOperations(flags);
    }
    catch (const InvalidCmdArgumentsException& exc){
        std::cerr << exc.what();
    }
    return 0;
}
