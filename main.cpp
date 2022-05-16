#include "LexicalAnalyzer.h"

int main(int argc, char *argv[]) {
    //实例化
    LexicalAnalyzer lexicalAnalyzer;
    //读源码
    bool inputCodeIsOpen = lexicalAnalyzer.openInputCode(argv[1]);
    if (!inputCodeIsOpen) {
        return 0;
    }
    //创建符号表
    lexicalAnalyzer.createSymbolTable();
    //自动机
    lexicalAnalyzer.FA();
    //打印结果
    lexicalAnalyzer.printSymbolTable();
    lexicalAnalyzer.lexemesTable.printLexemes();
    lexicalAnalyzer.tokenTable.printToken();
    //输出至文件
    lexicalAnalyzer.openOutputSymbolTable("SymbolTable.csv");
    lexicalAnalyzer.outputSymbolTableToFile();
    lexicalAnalyzer.openOutputToken("Tokens.csv");
    lexicalAnalyzer.outputTokenToFile();
    lexicalAnalyzer.openOutputLexemes("Lexemes.csv");
    lexicalAnalyzer.outputLexemesToFile();
    //关文件
    lexicalAnalyzer.closeInputCode();
    lexicalAnalyzer.closeOutputSymbolTable();
    lexicalAnalyzer.closeOutputToken();
    lexicalAnalyzer.closeOutputLexemes();
    return 0;
}
