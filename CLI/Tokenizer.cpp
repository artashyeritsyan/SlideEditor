#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::stringstream& input) : inputStream(input) {
    nextChar();
}

std::unique_ptr<SToken> Tokenizer::nextToken() {
    while (inputStream) {
        if (isspace(currentChar)) {
            nextChar();
            continue;
        }
        else if (currentChar >= 97 && currentChar <= 122 && !isFlagPassed) {
            return parseWord();
        }
        else if (currentChar == '-') {
            nextChar();
            isFlagPassed = true;
            return parseFlag();
        } 
        else if (isalnum(currentChar)) {
            return parseValue();
        }
        
    }
    return std::make_unique<SToken>(ETokenType::END, "");
}

void Tokenizer::nextChar() {
        inputStream.get(currentChar);
    }

std::unique_ptr<SToken> Tokenizer::parseFlag() {
    std::string flagStr;
    while (inputStream && (currentChar >= 97 && currentChar <= 122)) {
        flagStr += currentChar;
        nextChar();
    }
    return std::make_unique<SToken>(ETokenType::FLAG, flagStr);
}

std::unique_ptr<SToken> Tokenizer::parseValue() {
    std::string valueStr;
    while (inputStream && !isspace(currentChar)) {
        valueStr += currentChar;
        nextChar();
    }
    return std::make_unique<SToken>(ETokenType::VALUE, valueStr);
}

std::unique_ptr<SToken> Tokenizer::parseWord() {
    std::string wordStr;
    while (inputStream && (currentChar >= 97 && currentChar <= 122)) {
        wordStr += currentChar;
        nextChar();
    }
    return std::make_unique<SToken>(ETokenType::WORD, wordStr);
}

std::string SToken::getTypeString() const {
    switch (type) {
        case ETokenType::WORD:  return "WORD";
        case ETokenType::FLAG:  return "FLAG";
        case ETokenType::VALUE: return "VALUE";
        default: return "END";
    }
}
