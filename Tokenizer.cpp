#include "Tokenizer.h"


std::vector<Token> Tokenizer::Tokenize(std::string program,  std::regex& regex, TokenType token_type, uint32_t group_id)
{
    tokens.clear();
    std::smatch match;
    uint32_t line_number = 1;
    std::string line;
    size_t pos = 0;
    while ((pos = program.find('\n')) != std::string::npos)
    {
        line = program.substr(0, pos);
        program.erase(0, pos + 1);

        while (std::regex_search(line, match, regex)){
            if (match[group_id].matched){
                tokens.push_back({ match[group_id], token_type, line_number });
            }

            line_number++;
            line = match.suffix().str();
        }

    }
    return tokens;
}


std::vector<Token> Tokenizer::tokenize_number(std::string program)
{
    return Tokenize(program, scanner.number_regex, TokenType::NUMBER, 3);
}


std::vector<Token> Tokenizer::tokenize_string(std::string program)
{
    return Tokenize(program, scanner.string_regex, TokenType::STRING, 2);
}


std::vector<Token> Tokenizer::tokenize_comment(std::string program)
{
    return Tokenize(program, scanner.comment_regex, TokenType::COMMENT, 0);
}


std::vector<Token> Tokenizer::tokenize_reserved_word(std::string program)
{
    return Tokenize(program, scanner.reserved_word_regex, TokenType::RESERVED_WORD, 3);
}


std::vector<Token> Tokenizer::tokenize_operator(std::string program)
{
    return Tokenize(program, scanner.operator_regex, TokenType::OPERATOR, 2);
}


std::vector<Token> Tokenizer::tokenize_delimiter(std::string program)
{
    return Tokenize(program, scanner.delimiter_regex, TokenType::DELIMITER, 2);
}


std::vector<Token> Tokenizer::tokenize_identifier(std::string program)
{
    return Tokenize(program, scanner.identifier_regex, TokenType::IDENTIFIER, 2);
}
