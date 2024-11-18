#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <sstream>
#include <string>
#include <memory>

#include "CLIException.hpp"
#include "Token.hpp"


class Tokenizer {
public:
    Tokenizer(std::stringstream& input);
    std::shared_ptr<SToken> nextToken();

private:
    std::stringstream& _inputStream;
    char _currentChar;

    bool _isFlagPassed;

private:
    void nextChar();

    std::shared_ptr<SToken> parseFlag();
    std::shared_ptr<SToken> parseValue();
    std::shared_ptr<SToken> parseWord();

};

#endif // TOKENIZER_HPP