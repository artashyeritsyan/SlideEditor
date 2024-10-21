#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <sstream>
#include <string>
#include <memory>

#include "Token.hpp"


class Tokenizer {
private:
    std::stringstream& inputStream;
    char currentChar;

public:
    Tokenizer(std::stringstream& input);
    std::unique_ptr<SToken> nextToken();

private:
    void nextChar();

    std::unique_ptr<SToken> parseFlag();
    std::unique_ptr<SToken> parseValue();
    std::unique_ptr<SToken> parseWord();

    bool isFlagPassed;
};

#endif // TOKENIZER_HPP