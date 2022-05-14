cmake_minimum_required(VERSION 3.22)
project(LexicalAnalysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(LexicalAnalysis main.cpp LexicalAnalyzer.cpp LexicalAnalyzer.h SymbolTable.cpp SymbolTable.h LexemesTable.cpp LexemesTable.h Utils.cpp Utils.h Token.cpp Token.h Keywords.cpp Keywords.h)
