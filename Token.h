#pragma once
#include <string>
#include <iostream>

enum class TokenType
{
    NUMBER,
    STRING,
    COMMENT,
    RESERVED_WORD,
    OPERATOR,
    DELIMITER,
    IDENTIFIER,
};

struct Token
{
    std::string lexeme;
    TokenType token_type;
    uint32_t line;

    friend std::ostream& operator<<(std::ostream& os, const Token& obj);
    std::string TokenTypeToString(const TokenType& token_type) const;
};




