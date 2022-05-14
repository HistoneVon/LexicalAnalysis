/**
 * @author fengclchn@outlook.com
 * @createdBy 冯昶霖
 * @date 2022/5/14 10:31
 */

#include "Token.h"


std::vector<Token>::size_type TokenTable::saveToken(TokenType typeTemp, TokenValue valueTemp) {
    Token tokenTemp(typeTemp, valueTemp);
    tokens.push_back(tokenTemp);
    return tokens.size() - 1;
}

void TokenTable::printToken() {
    std::cout<<std::endl<<"[Token Table]"<<std::endl;
    for (auto iter = tokens.begin(); iter < tokens.end(); ++iter) {
        if ((*iter).type == TOKEN_IDENTIFIER) {
            std::cout << "(" << "ID" << "\t, " << (*iter).value.indexIdentifier << "\t)" << std::endl;
        } else if ((*iter).type == TOKEN_KEYWORD) {
            std::cout << "(" << "KEY" << "\t, " << (*iter).value.indexKeyword << "\t)" << std::endl;
        } else if ((*iter).type == TOKEN_INT) {
            std::cout << "(" << "INT" << "\t, " << (*iter).value.valInteger << "\t)" << std::endl;
        } else if ((*iter).type == TOKEN_OPERATOR) {
            std::cout << "(" << "OP" << "\t, " << (*iter).value.valOperator << "\t)" << std::endl;
        } else if ((*iter).type == TOKEN_SEPARATOR) {
            std::cout << "(" << "SEP" << "\t, " << (*iter).value.valSeparator << "\t)" << std::endl;
        }
    }
}

