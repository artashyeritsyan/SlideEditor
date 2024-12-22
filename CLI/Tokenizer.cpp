#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::stringstream& input) : _inputStream(input) {
    nextChar();
}

std::shared_ptr<SToken> Tokenizer::nextToken() {
    while (_inputStream) {
        if (isspace(_currentChar)) {
            nextChar();
            continue;
        }
        else if (_currentChar >= 97 && _currentChar <= 122 && !_isFlagPassed) {
            return parseWord();
        }
        else if (_currentChar == '-') {
            nextChar();
            _isFlagPassed = true;
            return parseFlag();
        } 
        else if (isalnum(_currentChar) || '"') {
            return parseValue();
        }
        
    }
    return std::make_unique<SToken>(ETokenType::END, "");
}

void Tokenizer::nextChar() {
        _inputStream.get(_currentChar);
    }

std::shared_ptr<SToken> Tokenizer::parseFlag() {
    std::string flagStr;
    while (_inputStream && (_currentChar >= 97 && _currentChar <= 122)) {
        flagStr += _currentChar;
        nextChar();
    }
    return std::make_unique<SToken>(ETokenType::FLAG, flagStr);
}

std::shared_ptr<SToken> Tokenizer::parseValue() {
    std::string valueStr;

    if (_currentChar == '"') {
        nextChar();
        while (_inputStream && _currentChar != '"') {
            valueStr += _currentChar;
            nextChar();
        }
        if (_currentChar != '"') {
            throw CLIException("You must close the quotes");
        }
        nextChar();
    }
    else {
        while (_inputStream && !isspace(_currentChar)) {
            valueStr += _currentChar;
            nextChar();
        }
    }
    return std::make_unique<SToken>(ETokenType::VALUE, valueStr);
}

std::shared_ptr<SToken> Tokenizer::parseWord() {
    std::string wordStr;
    while (_inputStream && (_currentChar >= 97 && _currentChar <= 122)) {
        wordStr += _currentChar;
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
