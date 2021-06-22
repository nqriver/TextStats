#include <iostream>
#include "OperationsHandler.h"
#include "Functions.h"


OperationsHandler::OperationsHandler(CommandLineArgsParser &parser) :
        m_parser{ parser },
        sourceFile{ parser.getSourcePath() },
        byLength{ false }
{

}

///splits file content into tokens - words
void OperationsHandler::tokenizeFile() {
    std::string token{};
    while(sourceFile >> token) {
        words.push_back(std::move(token));
    }
}

void OperationsHandler::markByLengthOpt() {
    byLength = true;
}

void OperationsHandler::unmarkByLengthOpt(){
    byLength = false;
}

Out OperationsHandler::specifyStdoutType() const {
   return (m_parser.isOutputFlagSpecified() ? Out::file : Out::console );
}

void OperationsHandler::printOutput() const {
    Out destination = specifyStdoutType();
    switch (destination){
        case Out::console:
            printOnScreen();
            break;
        case Out::file:
            printToFile();
            break;
    }
}

void OperationsHandler::printOnScreen() const {
    std::cout << ss_output.str();
}

void OperationsHandler::printToFile() const {
    std::string name { m_parser.getOutputPath() };
    std::ofstream outFile{ name };
    outFile << ss_output.rdbuf();
}

void OperationsHandler::printLinesCount() {
    ss_output << "[Number of lines] " << TextOperations::countLines(sourceFile) << '\n';
}

void OperationsHandler::printDigitsCount() {
    ss_output << "[Number of digits] " << TextOperations::countDigits(sourceFile) << '\n';
}

void OperationsHandler::printNumbersCount() {
    ss_output << "[Number of numbers] " << TextOperations::countNumbers(sourceFile) << '\n';
}

void OperationsHandler::printCharsCount() {
    ss_output << "[Number of characters] " << TextOperations::countChars(sourceFile) << '\n';
}

void OperationsHandler::printWordsCount() {
    ss_output << "[Number of words] " << TextOperations::countWords(sourceFile) << '\n';
}

void OperationsHandler::printSortedWords() {
    if (byLength) {
        unmarkByLengthOpt();
        TextOperations::sortWords(words, [](const auto& strA, const auto& strB) {
            return strA.size() > strB.size();
        });
        ss_output << "[Words sorted by length]\n";
    } else {
        TextOperations::sortWords(words, std::less<>());
        ss_output << "[Words sorted alphabetically]\n";

    }
    for_each(words.begin(), words.end(), [&](const auto& word){ ss_output << word << '\n'; });
}

void OperationsHandler::printReverseSortedWords() {
    if (byLength) {
        unmarkByLengthOpt();
        TextOperations::sortWords(words, [](const auto& strA, const auto& strB) {
            return strA.size() < strB.size();
        });
        ss_output << "[Words reverse - sorted by length]\n";
    } else {
        TextOperations::sortWords(words, std::greater<>());
        ss_output << "[Words reverse - sorted alphabetically]\n";
    }

    for_each(words.begin(), words.end(), [&](const auto& word){ ss_output << word << '\n'; });
}

void OperationsHandler::printPalindromes() {
    std::vector<std::string> palindromes;
    m_parser.getPalindromesInput(palindromes);
    if (palindromes.empty()) return;

    ss_output << "[Palindromes]\n";
    for (const auto& palindrome : palindromes){
        for (const auto& word : words){
            if (palindrome == word){
                ss_output << word << '\n';
                break;
            }
        }
    }
}

void OperationsHandler::printAnagrams() {
    std::vector<std::string> inputWords{};
    m_parser.getAnagramsInput(inputWords);

    if (inputWords.empty()) return;
    ss_output << "[Anagrams]\n";
    for (const auto& inputWord : inputWords){
        for (const auto& fileWord : words){
            if (TextOperations::isAnagram(inputWord, fileWord)){
                ss_output << fileWord << '\n';
            }
        }
    }
}
