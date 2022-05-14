#include "LexicalAnalyzer.h"
#include <iostream>

int main() {
    LexicalAnalyzer lexicalAnalyzer;
    //读源码
    bool inputCodeIsOpen = lexicalAnalyzer.openInputCode("src.txt");
    if (!inputCodeIsOpen) {
        std::cout << "Source open Failed." << std::endl;
    }
    return 0;
}
