#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::stringstream& input) : inputStream(input) {
        nextChar();
    }

SToken Tokenizer::nextToken() {
    while (inputStream) {
        if (isspace(currentChar)) {
            nextChar();
            continue;
        }

        if (currentChar == '-') {
            nextChar();
            return parseFlag();
        }

        if (isdigit(currentChar)) {
            return parseValue();
        }

        if (isalpha(currentChar)) {
            return parseWord();
        }
        
    }
    return SToken(TokenType::END, "");
}

void Tokenizer::nextChar() {
        inputStream.get(currentChar);
    }

SToken Tokenizer::parseFlag() {
    std::string flagStr;
    while (inputStream && (currentChar >= 97 || currentChar <= 122)) {
        flagStr += currentChar;
        nextChar();
    }
    return SToken(TokenType::FLAG, flagStr);
}

SToken Tokenizer::parseValue() {
    std::string valueStr;
    while (inputStream && !isspace(currentChar)) {
        valueStr += currentChar;
        nextChar();
    }
    return SToken(TokenType::VALUE, valueStr);
}

SToken Tokenizer::parseWord() {
    std::string wordStr;
    while (inputStream && (currentChar >= 97 || currentChar <= 122)) {
        wordStr += currentChar;
        nextChar();
    }
    return SToken(TokenType::WORD, wordStr);
}



    