#include <iostream>
#include <fstream>
#include <sstream>

#include "Tokenizer.h"

typedef int (*TokenizeFunctions) (std::string program);

void get_tokens(const std::vector<Token>& tokens)
{
    for (const Token& token : tokens)
        std::cout << token;
    std::cout << '\n';
}


std::string open_file()
{
    std::string program;
    std::fstream program_file;

    std::string filePath = "test.txt";

    if (filePath.size() >= 3 && filePath.substr(filePath.size() - 3) == "txt")
    {
        program_file.open(filePath, std::ios::in);
        if (program_file.is_open())
        {
            std::stringstream buffer;
            buffer << program_file.rdbuf();
            program = buffer.str();
        }
        else
            std::cerr << "Error opening file." << std::endl;
    }
    else
        std::cerr << "Only .js files are allowed" << std::endl;

    return program;
}

int main() {
    std::string program = open_file();

    Tokenizer tokenizer;

    get_tokens(tokenizer.tokenize_number(program));
    get_tokens(tokenizer.tokenize_string(program));
    get_tokens(tokenizer.tokenize_comment(program));
    get_tokens(tokenizer.tokenize_reserved_word(program));
    get_tokens(tokenizer.tokenize_operator(program));
    get_tokens(tokenizer.tokenize_delimiter(program));
    get_tokens(tokenizer.tokenize_identifier(program));
}
