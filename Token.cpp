#include "Token.h"

std::string Token::TokenTypeToString(const TokenType& token_type) const
{
    switch (token_type) {
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::STRING: return "STRING";
        case TokenType::COMMENT: return "COMMENT";
        case TokenType::RESERVED_WORD: return "RESERVED_WORD";
        case TokenType::OPERATOR: return "OPERATOR";
        case TokenType::DELIMITER: return "DELIMITER";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        default: return "UNRECOGNIZED";
    }
}


std::ostream& operator<<(std::ostream& os, const Token& obj)
{
    os << "<" << obj.lexeme << ", " << obj.TokenTypeToString(obj.token_type)<<">"<< std::endl;
    return os;
}
