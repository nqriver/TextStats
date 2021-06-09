#ifndef TEXTSTATSAPP_INVALIDCMDARGUMENTSEXCEPTION_H
#define TEXTSTATSAPP_INVALIDCMDARGUMENTSEXCEPTION_H


#include <stdexcept>

namespace Errors {
    const std::string usage         = "\nUsage: ./textStats [option] ... [FILE]\n",
                no_file_path        = "File path not specified\n",
                no_file_flag        = "File flag must be specified at first\n",
                input_flag_error    = "Input flag should be followed only by file path\n",
                invalid_file_path   = "Invalid file path\n",
                invalid_option      = "Invalid option\n",
                duplicate_file      = "Duplicate source file\n",
                invalid_order       = "Invalid flags order\n";
}

class InvalidCmdArgumentsException : public std::runtime_error {
public:
    explicit InvalidCmdArgumentsException(const std::string& errorMsg) : std::runtime_error(errorMsg.c_str())
    {
    }
    explicit InvalidCmdArgumentsException(std::string&& errorMsg) : std::runtime_error(errorMsg.c_str())
    {
    }
};


#endif //TEXTSTATSAPP_INVALIDCMDARGUMENTSEXCEPTION_H
