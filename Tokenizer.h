#pragma once

#include <regex>
#include <vector>

#include "Token.h"
#include "LexemeScanner.h"


class Tokenizer
{
public:
    Tokenizer()
            : scanner()
    {
    }

    std::vector<Token> tokenize_number(std::string program);
    std::vector<Token> tokenize_string(std::string program);
    std::vector<Token> tokenize_comment(std::string program);
    std::vector<Token> tokenize_reserved_word(std::string program);
    std::vector<Token> tokenize_operator(std::string program);
    std::vector<Token> tokenize_delimiter(std::string program);
    std::vector<Token> tokenize_identifier(std::string program);

private:
    std::vector<Token> Tokenize(std::string program, std::regex& pattern, TokenType token_type, uint32_t group_id);

private:
    std::vector<Token> tokens;
    LexemeScanner scanner;
};
