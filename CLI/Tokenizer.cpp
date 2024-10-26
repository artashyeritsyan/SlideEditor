#include "Tokenizer.hpp"

bool isInvalid(const std::string& token) {
    for (char c : token) {
        if (!std::isalpha(c) && !std::isdigit(c) && c != '-') {
            return true; 
        }
    }
    return false; 
}

bool isNumber(const std::string& token) {
    for (char c : token) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

bool isDouble(const std::string& token) {
    bool hasDot = false;
    for (char c : token) {
        if (c == '.') {
            if (hasDot) return false;  
            hasDot = true;
        } else if (!std::isdigit(c)) {
            return false;
        }
    }
    return hasDot;
}

bool isWord(const std::string& token) {
    for (char c : token) {
        if (!std::isalpha(c) && c != '_') {
            return false;  
        }
    }
    return true;  
}

bool isArgument(const std::string& token) {
    std::string subtoken = token.substr(1);
    return !token.empty() && token[0] == '-' && isWord(subtoken);
}

bool isValue(const std::string& token) {
    return isNumber(token) || isDouble(token) || isWord(token);
}

SToken Tokenizer::WhatIsTokenType(const std::string& word) {
    if (isNumber(word)) {
        return SToken(SToken::EType::Value, std::stoi(word));
    } else if (isDouble(word)) {
        return SToken(SToken::EType::Value, std::stod(word));
    } else if (isArgument(word)) {
        std::string argument = word.substr(1);
        return SToken(SToken::EType::Arg, argument);
    } else if (isWord(word)) {
        return SToken(SToken::EType::Word, word);
    } else {
        return SToken(SToken::EType::EOL, ""); 
    }
}

std::unique_ptr<SToken> Tokenizer::tokenize(std::istream& inputStream) {
    std::string word;

    if (inputStream >> word) {
        if (isInvalid(word)) {
            throw std::runtime_error("Invalid token: " + word);
        }

        SToken result = WhatIsTokenType(word);
        
        return std::make_unique<SToken>(result.getType(), result.getContent());
    }

    return nullptr; 
}