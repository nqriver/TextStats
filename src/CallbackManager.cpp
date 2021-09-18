#include "CallbackManager.h"

CallbackManager::CallbackManager(OperationsHandler& handler) :
        m_handler{ handler }
{
    operations_caller[Flags::file]                = std::bind(&OperationsHandler::tokenizeFile, &m_handler);
    operations_caller[Flags::newlines]            = std::bind(&OperationsHandler::printLinesCount, &m_handler);
    operations_caller[Flags::digits]              = std::bind(&OperationsHandler::printDigitsCount, &m_handler);
    operations_caller[Flags::numbers]             = std::bind(&OperationsHandler::printNumbersCount, &m_handler);
    operations_caller[Flags::chars]               = std::bind(&OperationsHandler::printCharsCount, &m_handler);
    operations_caller[Flags::words]               = std::bind(&OperationsHandler::printWordsCount, &m_handler);
    operations_caller[Flags::sorted]              = std::bind(&OperationsHandler::printSortedWords, &m_handler);
    operations_caller[Flags::reverse_sorted]      = std::bind(&OperationsHandler::printReverseSortedWords, &m_handler);
    operations_caller[Flags::by_length]           = std::bind(&OperationsHandler::markByLengthOpt, &m_handler);
    operations_caller[Flags::anagrams]            = std::bind(&OperationsHandler::printAnagrams, &m_handler);
    operations_caller[Flags::palindromes]         = std::bind(&OperationsHandler::printPalindromes, &m_handler);
}

void CallbackManager::callOperations(const std::vector<Flags>& validFlags) {
    for (const auto& flag : validFlags){
        operations_caller[flag]();
    }
    m_handler.printOutput();
}
