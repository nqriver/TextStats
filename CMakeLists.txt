cmake_minimum_required(VERSION 3.17)
project(TextStatsApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(TextStatsApp ./src/main.cpp ./src/CommandLineArgsParser.cpp ./src/CommandLineArgsParser.h
        ./src/InvalidCmdArgumentsException.h ./src/Functions.cpp ./src/Functions.h ./src/OperationsHandler.cpp
        ./src/OperationsHandler.h ./src/CallbackManager.cpp ./src/CallbackManager.h)