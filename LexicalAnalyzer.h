/**
 * @author fengclchn@outlook.com
 * @createdBy 冯昶霖
 * @date 2022/5/9 23:49
 */

#ifndef LEXICALANALYSIS_LEXICALANALYZER_H
#define LEXICALANALYSIS_LEXICALANALYZER_H

#include "SymbolTable.h"
#include "LexemesTable.h"
#include <fstream>

class LexicalAnalyzer {
private:
    /*符号表*/
    SymbolTableItem *symbolTableHead;//头节点
    SymbolTableItem *symbolTableTemp;//当前节点
    SymbolTableItem *symbolTableTail;//尾节点
    int SymbolTableLength;
    /*字符串表（词素表）*/
    Lexemes lexemesTable;
    /*文件*/
    std::ifstream inputCode;//读入源文件
    std::ofstream outputSymbolTable;//输出符号表
    std::ofstream outputToken;//输出Token
    std::ofstream outputLexemes;//输出字符串表
public:
    //Constructor
    //LexicalAnalyzer();

    //Destructor
    ~LexicalAnalyzer();

    /*文件操作*/
    bool openInputCode(const std::string &fileName);

    bool openOutputSymbolTable(const std::string &fileName);

    bool openOutputToken(const std::string &fileName);

    bool openOutputLexemes(const std::string &fileName);

    /*符号表操作*/
    //创建符号表
    void createSymbolTable();

    //新增符号表项
    void addSymbolTableItem(SymbolTableItem *newItem);

    //返回标识符在符号表中的位置或者即将插入的位置的相反数
    int findSymbolTableItem(const std::string &symbol);
};

#endif //LEXICALANALYSIS_LEXICALANALYZER_H
