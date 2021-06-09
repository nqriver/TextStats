#ifndef TEXTSTATSAPP_COMMANDLINEARGSPARSER_H
#define TEXTSTATSAPP_COMMANDLINEARGSPARSER_H


#include <vector>
#include <string>
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
    output,
    input
};

class CommandLineArgsParser {
    static const std::array<std::pair<std::string, std::string>, 13> allFlagsData;
    bool fileFlagSpecified;
    bool inputFlagSpecified;
    bool outputFlagSpecified;
    std::vector<std::string> arguments;

    const std::string& getPath(const std::string&& flag, const std::string&& alias);
    bool isLastFlag(std::string&& flag, std::string&& alias);
    void validateInputFlag();
    void getArgumentsFromFile();
    void getMultipleParameters(std::string&& flag, std::string&& alias, std::vector<std::string>& parameters);
public:
    CommandLineArgsParser(int &argc, char **argv);
    void validateFlags(std::vector<Flags>& validFlags);
    void getPalindromesInput(std::vector<std::string>& palindromes);
    void getAnagramsInput(std::vector<std::string>& anagrams);
    const std::string& getSourcePath();
    const std::string& getOutputPath();
    const std::string& getInputPath();
    bool isOutputFlagSpecified() const;
};


#endif //TEXTSTATSAPP_COMMANDLINEARGSPARSER_H
