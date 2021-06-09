#ifndef TEXTSTATSAPP_FUNCTIONS_H
#define TEXTSTATSAPP_FUNCTIONS_H
#include <fstream>
#include <vector>
#include <functional>

namespace TextOperations{
    void resetStream(std::ifstream& infile);
    int countLines(std::ifstream& infile);
    int countDigits(std::ifstream& infile);
    int countNumbers(std::ifstream& infile);
    int countChars(std::ifstream& infile);
    int countWords(std::ifstream& infile);
    void sortWords(std::vector<std::string>& words,
                   std::function<bool(const std::string&, const std::string&)> sortRule);
    bool isAnagram(std::string strA, std::string strB);
    bool isPalindrome(const std::string_view &str);


}

#endif //TEXTSTATSAPP_FUNCTIONS_H
