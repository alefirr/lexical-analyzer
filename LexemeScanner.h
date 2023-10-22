#pragma once

#include <regex>

struct LexemeScanner
{
    LexemeScanner()
            : number_regex(R"((//.*|\/\*)|(\"[^\"\\]*(?:\\.[^\"\\]*)*\"|\'[^\'\\]*(?:\\.[^\'\\]*)*\')|(\b[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?\b|\b0x[0-9A-Fa-f]+\b))"),
              string_regex(R"((//.*|\/\*)|(\"[^\"\\]*\"))"),
              comment_regex(R"((\/\*[\s\S]*?(.*?)\*\/)|(\/\/.*))"),
              reserved_word_regex(R"((//.*|\/\*)|(\"[^\"\\]*(?:\\.[^\"\\]*)*\"|\'[^\'\\]*(?:\\.[^\'\\]*)*\')|\b(abstract|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|this|throw|true|try|typeof|var|void|while|with|yield)\b)"),
              operator_regex(R"((//.*|\/\*)|([\+\-\*\=\%\^\&\|\>\<\~\!]))"),
              delimiter_regex(R"((//.*|\/\*)|([\;\(\)\{\}\[\]\,\:\@]))"),
              identifier_regex(R"((//.*|/\*)|(([a-zA-Z_]\w*)(?=\s*(=|\+=|-=|\*=|\/=)\s*)))")
    {
    }

    std::regex number_regex;
    std::regex string_regex;
    std::regex comment_regex;
    std::regex reserved_word_regex;
    std::regex operator_regex;
    std::regex delimiter_regex;
    std::regex identifier_regex;
};