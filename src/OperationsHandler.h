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
    CommandLineArgsParser& m_parser;
    std::ifstream sourceFile;
    std::stringstream ss_output{};
    std::vector<std::string> words{};
    bool byLength;
    void printOnScreen() const;
    void printToFile() const;
    Out specifyStdoutType() const;
    void unmarkByLengthOpt();
public:
    explicit OperationsHandler(CommandLineArgsParser&);
    void tokenizeFile();
    void markByLengthOpt();
    void printLinesCount();
    void printDigitsCount();
    void printNumbersCount();
    void printCharsCount();
    void printWordsCount();
    void printSortedWords();
    void printReverseSortedWords();
    void printAnagrams();
    void printPalindromes();
    void printOutput() const;
};


#endif //TEXTSTATSAPP_OPERATIONSHANDLER_H
