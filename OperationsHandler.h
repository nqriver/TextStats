#ifndef TEXTSTATSAPP_OPERATIONSHANDLER_H
#define TEXTSTATSAPP_OPERATIONSHANDLER_H


#include "CommandLineArgsParser.h"
#include <fstream>
#include <sstream>

enum class Out{
    console,
    file
};


class OperationsHandler {
    CommandLineArgsParser m_parser;
    std::ifstream sourceFile;
    std::stringstream ss_output{};
    std::vector<std::string> words{};
    bool byLength;
    void printOnScreen();
    void printToFile();
    Out specifyStdoutType();
public:
    explicit OperationsHandler(CommandLineArgsParser&);
    void tokenizeFile();
    void setByLength();
    void printLinesCount();
    void printDigitsCount();
    void printNumbersCount();
    void printCharsCount();
    void printWordsCount();
    void printSortedWords();
    void printReverseSortedWords();
    void printAnagrams();
    void printPalindromes();
    void printOutput();
};


#endif //TEXTSTATSAPP_OPERATIONSHANDLER_H
