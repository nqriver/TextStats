#ifndef TEXTSTATSAPP_COMMANDLINEARGSPARSER_H
#define TEXTSTATSAPP_COMMANDLINEARGSPARSER_H


#include <vector>
#include <string>
#include <string_view>
#include <array>

enum class Flags{
    file,
    newlines,
    digits,
    numbers,
    chars,
    words,
    sorted,
    reverse_sorted,
    by_length,
    anagrams,
    palindromes,
};

class CommandLineArgsParser {
    static const std::array<std::pair<std::string, std::string>, 13> allFlagsData;
    bool fileFlagSpecified;
    bool inputFlagSpecified;
    bool outputFlagSpecified;
    std::vector<std::string> arguments;

    const std::string& getPath(std::string_view flag, std::string_view alias) const;
    bool isLastFlag(std::string_view flag, std::string_view alias) const;
    void validateInputFlag();
    void getArgumentsFromFile();
    void getMultipleParameters(std::string_view flag, std::string_view alias, std::vector<std::string>& parameters);
public:
    CommandLineArgsParser(int &argc, char **argv);
    void validateFlags(std::vector<Flags>& validFlags);
    void getPalindromesInput(std::vector<std::string>& palindromes);
    void getAnagramsInput(std::vector<std::string>& anagrams);
    const std::string& getSourcePath() const;
    const std::string& getOutputPath() const;
    const std::string& getInputPath() const;
    bool isOutputFlagSpecified() const;
};


#endif //TEXTSTATSAPP_COMMANDLINEARGSPARSER_H
