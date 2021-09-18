#ifndef TEXTSTATSAPP_CALLBACKMANAGER_H
#define TEXTSTATSAPP_CALLBACKMANAGER_H

#include "OperationsHandler.h"
#include "CommandLineArgsParser.h"
#include <map>
#include <functional>

class CallbackManager {

    std::map<Flags, std::function<void()>> operations_caller;
    OperationsHandler& m_handler;
public:
    explicit CallbackManager(OperationsHandler& handler);
    void callOperations(const std::vector<Flags>& validFlags);


};


#endif //TEXTSTATSAPP_CALLBACKMANAGER_H
