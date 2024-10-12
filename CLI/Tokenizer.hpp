#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <iostream>
#include <sstream>
#include <string>

enum class TokenType {
    WORD,
    FLAG,
    VALUE,
    END
};

struct SToken {
public:
    TokenType type;
    std::string value;

    SToken(TokenType type, const std::string& value) : type(type), value(value) {}
};

class Tokenizer {
private:
    std::stringstream& inputStream;
    char currentChar;

public:
    Tokenizer(std::stringstream& input);
    SToken nextToken();

private:
    void nextChar();

    SToken parseFlag();
    SToken parseValue();
    SToken parseWord();
};

#endif // TOKENIZER_HPP