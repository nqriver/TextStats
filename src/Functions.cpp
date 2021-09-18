#include "Functions.h"
#include <sstream>
#include <algorithm>

void TextOperations::resetStream(std::ifstream &infile){
    infile.clear();
    infile.seekg(0);
}

int TextOperations::countLines(std::ifstream &infile) {
    resetStream(infile);
    std::string line{};
    int counter{0};
    while (std::getline(infile, line)) {
        ++counter;
    }
    return counter;
}

int TextOperations::countDigits(std::ifstream &infile) {
    resetStream(infile);
    char ch;
    int counter{0};
    while (infile >> ch) {
        if (std::isdigit(ch)) ++counter;
    }
    return counter;
}

int TextOperations::countNumbers(std::ifstream &infile) {
    resetStream(infile);
    std::string token{};
    int counter{0};
    while (infile >> token) {
        std::stringstream ss(token);
        if (double val; ss >> val) ++counter;
    }
    return counter;
}

int TextOperations::countChars(std::ifstream &infile) {
    resetStream(infile);
    char ch{};
    int counter{0};
    while (infile >> std::noskipws >> ch) {
        ++counter;
    }
    return counter;
}

int TextOperations::countWords(std::ifstream &infile) {
    resetStream(infile);
    std::string word{};
    int counter{};
    while (infile >> word) {
        ++counter;
    }
    return counter;
}

void TextOperations::sortWords(std::vector<std::string> &words,
                               std::function<bool(const std::string &, const std::string &)> sortRule) {
    std::sort(words.begin(), words.end(), sortRule);
}

bool TextOperations::isAnagram(std::string strA, std::string strB) {
    if (strA.length() != strB.length()) {
        return false;
    }
    std::sort(strA.begin(), strA.end());
    std::sort(strB.begin(), strB.end());
    return strA == strB;
}

bool TextOperations::isPalindrome(const std::string_view &str) {
    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}
