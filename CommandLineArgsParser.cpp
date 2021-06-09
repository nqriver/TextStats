#include <algorithm>
#include <stdexcept>
#include "CommandLineArgsParser.h"
#include "InvalidCmdArgumentsException.h"
#include "Functions.h"

const std::array<std::pair<std::string, std::string>, 13> CommandLineArgsParser::allFlagsData{
    std::make_pair("-f", "--file"),
    std::make_pair("-n", "--newlines"),
    std::make_pair("-d", "--digits"),
    std::make_pair("-dd", "--numbers"),
    std::make_pair("-c", "--chars"),
    std::make_pair("-w", "--words"),
    std::make_pair("-s", "--sorted"),
    std::make_pair("-rs", "--reverse-sorted"),
    std::make_pair("-l", "--by-length"),
    std::make_pair("-a", "--anagrams"),
    std::make_pair("-o", "--output"),
    std::make_pair("-p", "--palindromes"),
    std::make_pair("-i", "--input"),
};

CommandLineArgsParser::CommandLineArgsParser(int &argc, char **argv) {
    for (auto i { 1 }; i < argc; ++i) {
        arguments.push_back( std::string(argv[i]) );
    }
    fileFlagSpecified = *arguments.begin() == "-f" || *arguments.begin() == "--file";
    inputFlagSpecified = *arguments.begin() == "-i" || *arguments.begin() == "--input";
}

void CommandLineArgsParser::validateFlags(std::vector<Flags>& validFlags) {
    if (inputFlagSpecified) {
        validateInputFlag();
        getArgumentsFromFile();
    }
    if (!fileFlagSpecified) {
        throw InvalidCmdArgumentsException(Errors::no_file_flag + Errors::usage);
    }
    validFlags.push_back(Flags::file);
    for (auto it = arguments.begin() + 2; it != arguments.end(); ++it){
        if (*it == "-f" || *it == "--file"){
            throw InvalidCmdArgumentsException(Errors::duplicate_file + Errors::usage);
        }
        else if (*it == "-n" || *it == "--newlines"){
            validFlags.push_back(Flags::newlines);
        }
        else if (*it == "-d" || *it == "--digits"){
            validFlags.push_back(Flags::digits);
        }
        else if (*it == "-dd" || *it == "--numbers"){
            validFlags.push_back(Flags::numbers);
        }
        else if (*it == "-c" || *it == "--chars"){
            validFlags.push_back(Flags::chars);
        }
        else if (*it == "-w" || *it == "--words"){
            validFlags.push_back(Flags::words);
        }
        else if (*it == "-s" || *it == "--sorted"){
            validFlags.push_back(Flags::sorted);
        }
        else if (*it == "-rs" || *it == "--reverse-sorted"){
            validFlags.push_back(Flags::reverse_sorted);
        }
        else if (*it == "-l" || *it == "--by-length"){
            validFlags.push_back(Flags::by_length);
        }
        else if (*it == "-a" || *it == "--anagrams"){
            if (!isLastFlag("-a", "--anagrams"))
                throw InvalidCmdArgumentsException(Errors::invalid_order + Errors::usage);
            validFlags.push_back(Flags::anagrams);
            return;
        }
        else if (*it == "-o" || *it == "--output"){
//            validFlags.push_back(Flags::output);
            outputFlagSpecified = true;
            ++it;
        }
        else if (*it == "-p" || *it == "--palindromes"){
            if (!isLastFlag("-p", "--palindromes"))
                throw InvalidCmdArgumentsException(Errors::invalid_order + Errors::usage);
            validFlags.push_back(Flags::palindromes);
            return;
        }
        else {
            throw InvalidCmdArgumentsException(Errors::invalid_option + Errors::usage);
        }
    }
}

const std::string& CommandLineArgsParser::getSourcePath() {
    return getPath("-f", "--file");
}

const std::string &CommandLineArgsParser::getPath(const std::string&& flag, const std::string&& alias) {
    auto pathIt{ std::find_if(arguments.begin(), arguments.end(),
                           [&](const auto& arg){ return arg == flag || arg == alias; }) };
    if (pathIt == arguments.end() || std::next(pathIt) == arguments.end()) {
        throw InvalidCmdArgumentsException(Errors::no_file_path + Errors::usage);
    }
    return *std::next(pathIt);
}

const std::string& CommandLineArgsParser::getInputPath() {
    return getPath("-i", "--input");
}

const std::string& CommandLineArgsParser::getOutputPath() {
    return getPath("-o", "--output");
}

///checks if there are any other flags after the flag passed as argument
bool CommandLineArgsParser::isLastFlag(std::string &&flag, std::string &&alias) {
    auto flag_it { std::find_if(arguments.begin(), arguments.end(),
                             [&](const auto& arg){ return (arg == flag || arg == alias); })};

    auto any_flag = std::find_if(std::next(flag_it), arguments.end(),
                 [&](const auto& arg) {
        for (const auto& flag : allFlagsData){
            if ( arg == flag.first || arg == flag.second)
                return true;
        }
        return false;
    });
    return any_flag == arguments.end();
}

/// function called if input flag is set as first argument
/// -> resets vector of args getting data from file and resets fileFlagSpecified bool value
void CommandLineArgsParser::getArgumentsFromFile() {
    std::string fileName { getInputPath() };
    std::ifstream infile{ fileName };
    std::string arg;
    arguments.clear();
    while (infile >> arg){
        if (!arg.empty())
            arguments.push_back(arg);
    }
    fileFlagSpecified = *arguments.begin() == "-f" || *arguments.begin() == "--file";
}

void CommandLineArgsParser::validateInputFlag() {
    if (inputFlagSpecified && arguments.size() > 2){
        throw InvalidCmdArgumentsException(Errors::input_flag_error + Errors::usage);
    }
}

void CommandLineArgsParser::getMultipleParameters(std::string &&flag, std::string &&alias,
                                                  std::vector<std::string>& parameters) {

    auto start{ std::find_if(arguments.begin(), arguments.end(),
                              [&](const auto& arg){ return arg == flag || arg == alias; }) };

    std::for_each(start, arguments.end(), [&](auto arg){ parameters.push_back(arg); });
}

void CommandLineArgsParser::getPalindromesInput(std::vector<std::string>& palindromes) {
    getMultipleParameters("-p", "--palindromes", palindromes);

    ///remove non-palindromic words
    palindromes.erase(std::remove_if(
            palindromes.begin(), palindromes.end(),
            [](std::string& word) {
                return !TextOperations::isPalindrome(word);
            }), palindromes.end());

    ///remove equivalent palindromes
    auto last = std::unique(palindromes.begin(), palindromes.end());
    palindromes.erase(last, palindromes.end());
}

void CommandLineArgsParser::getAnagramsInput(std::vector<std::string> &anagrams) {
    getMultipleParameters("-a", "--anagrams", anagrams);

    ///in case user entered equivalent anagrams
    auto last = std::unique(anagrams.begin(), anagrams.end());
    anagrams.erase(last, anagrams.end());
}

bool CommandLineArgsParser::isOutputFlagSpecified() const {
    return outputFlagSpecified;
}
