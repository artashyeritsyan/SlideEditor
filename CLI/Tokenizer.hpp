#ifndef TOKENIZER_HPP 
#define TOKENIZER_HPP

#include <memory>
#include <sstream>
#include <vector>

#include "SToken.hpp"

class Tokenizer {
public:
    
    std::unique_ptr<SToken> tokenize(std::istream& inputStream);  

    SToken WhatIsTokenType(const std::string& word);   

};

#endif //TOKENIZER_HPP