#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <sstream>
#include <string>
#include <memory>

#include "Token.hpp"


class Tokenizer {
public:
    Tokenizer(std::stringstream& input);
    std::unique_ptr<SToken> nextToken();

private:
    std::stringstream& _inputStream;
    char _currentChar;

    bool _isFlagPassed;

private:
    void nextChar();

    std::unique_ptr<SToken> parseFlag();
    std::unique_ptr<SToken> parseValue();
    std::unique_ptr<SToken> parseWord();

};

#endif // TOKENIZER_HPP