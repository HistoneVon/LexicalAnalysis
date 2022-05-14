/**
 * @author fengclchn@outlook.com
 * @createdBy 冯昶霖
 * @date 2022/5/9 23:49
 */

#include "LexemesTable.h"
#include "LexicalAnalyzer.h"
#include <iostream>

//Constructor
//LexicalAnalyzer::LexicalAnalyzer() {}

//Destructor
LexicalAnalyzer::~LexicalAnalyzer() {
    if (outputSymbolTable.is_open()) {
        outputSymbolTable.close();
    }
    if (outputToken.is_open()) {
        outputToken.close();
    }
    if (outputLexemes.is_open()) {
        outputLexemes.close();
    }
}

//创建符号表
void LexicalAnalyzer::createSymbolTable() {
    //初始化符号表长度
    SymbolTableLength = 0;
    //创建头节点（头节点名称索引默认为-1）
    symbolTableHead = new SymbolTableItem(-1);
    //当前节点指针指向头节点
    symbolTableTail = symbolTableHead;
    symbolTableTemp = symbolTableTail;
}

//新增符号表项
void LexicalAnalyzer::addSymbolTableItem(SymbolTableItem *newItem) {
    symbolTableTail->next = newItem;
    symbolTableTail = symbolTableTemp->next;
    symbolTableTail->next = nullptr;
    symbolTableTemp = symbolTableTail;
    //符号表长度+1
    SymbolTableLength += 1;
}

//返回标识符在符号表中的位置或者即将插入的位置的相反数
int LexicalAnalyzer::findSymbolTableItem(const std::string &symbol) {
    unsigned int nameIndex = lexemesTable.findLexeme(symbol);
    if (nameIndex >= 0) {//如果词素表中查到了该词素
        int pos = 0;//第一个有内容的节点为0
        SymbolTableItem *p = symbolTableHead;
        while (p->next) {//如果下一节点不是nullptr（本节点不是尾）
            p = p->next;
            if (nameIndex == p->getName()) {//比对符号表name字段与查出来的标识符在字符串表中的索引
                return pos;//如果相等则返回该符号表位置，该位置是标识符在符号表中的位置
            }
            pos++;
        }
    }
    return -1;//没查到返回-1
}

bool LexicalAnalyzer::openInputCode(const std::string &fileName) {
    inputCode.open(fileName);
    if (inputCode) {
        return true;
    } else {
        return false;
    }
}

bool LexicalAnalyzer::openOutputSymbolTable(const std::string &fileName) {
    outputSymbolTable.open(fileName);
    if (outputSymbolTable) {
        return true;
    } else {
        return false;
    }
}

bool LexicalAnalyzer::openOutputToken(const std::string &fileName) {
    outputToken.open(fileName);
    if (outputToken) {
        return true;
    } else {
        return false;
    }
}

bool LexicalAnalyzer::openOutputLexemes(const std::string &fileName) {
    outputLexemes.open(fileName);
    if (outputLexemes) {
        return true;
    } else {
        return false;
    }
}




