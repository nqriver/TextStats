#ifndef TEXTSTATSAPP_CALLBACKMANAGER_H
#define TEXTSTATSAPP_CALLBACKMANAGER_H

#include "OperationsHandler.h"
#include "CommandLineArgsParser.h"
#include <map>
#include <functional>

class CallbackManager {

    std::map<Flags, std::function<void()>> methods;
    OperationsHandler& m_operations;
public:
    CallbackManager(OperationsHandler& operations);
    void callOperations(const std::vector<Flags>& validFlags);


};


#endif //TEXTSTATSAPP_CALLBACKMANAGER_H
