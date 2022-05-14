#include "LexicalAnalyzer.h"
#include <iostream>

int main() {
    LexicalAnalyzer lexicalAnalyzer;
    //读源码
    bool inputCodeIsOpen = lexicalAnalyzer.openInputCode("src.txt");
    if (!inputCodeIsOpen) {
        std::cout << "Source open Failed." << std::endl;
    }
    //打开输出文件
    //TODO 输出至文件
    //创建符号表
    lexicalAnalyzer.createSymbolTable();
    //自动机
    lexicalAnalyzer.FA();
    //打印结果
    lexicalAnalyzer.printSymbolTable();
    lexicalAnalyzer.lexemesTable.printLexemes();
    lexicalAnalyzer.tokenTable.printToken();
    //关文件
    lexicalAnalyzer.closeInputCode();
    return 0;
}
