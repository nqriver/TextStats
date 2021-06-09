cmake_minimum_required(VERSION 3.17)
project(TextStatsApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(TextStatsApp main.cpp CommandLineArgsParser.cpp CommandLineArgsParser.h InvalidCmdArgumentsException.h Functions.cpp Functions.h OperationsHandler.cpp OperationsHandler.h CallbackManager.cpp CallbackManager.h)