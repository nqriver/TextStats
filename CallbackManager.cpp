#include "CallbackManager.h"

CallbackManager::CallbackManager(OperationsHandler &operations) :
        m_operations{ operations }
{
    methods[Flags::file]                = std::bind(&OperationsHandler::tokenizeFile, &operations);
    methods[Flags::newlines]            = std::bind(&OperationsHandler::printLinesCount, &operations);
    methods[Flags::digits]              = std::bind(&OperationsHandler::printDigitsCount, &operations);
    methods[Flags::numbers]             = std::bind(&OperationsHandler::printNumbersCount, &operations);
    methods[Flags::chars]               = std::bind(&OperationsHandler::printCharsCount, &operations);
    methods[Flags::words]               = std::bind(&OperationsHandler::printWordsCount, &operations);
    methods[Flags::sorted]              = std::bind(&OperationsHandler::printSortedWords, &operations);
    methods[Flags::reverse_sorted]      = std::bind(&OperationsHandler::printReverseSortedWords, &operations);
    methods[Flags::by_length]           = std::bind(&OperationsHandler::markByLengthOpt, &operations);
    methods[Flags::anagrams]            = std::bind(&OperationsHandler::printAnagrams, &operations);
    methods[Flags::palindromes]         = std::bind(&OperationsHandler::printPalindromes, &operations);
}

void CallbackManager::callOperations(const std::vector<Flags>& validFlags) {
    for (const auto& flag : validFlags){
        methods[flag]();
    }
    m_operations.printOutput();
}
