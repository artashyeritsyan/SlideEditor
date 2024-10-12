#ifndef SYNTAX_HPP 
#define SYNTAX_HPP

#include <vector>

#include "Tokenizer.hpp"

class SyntaxAnalyzer {
public:

    std::vector<SToken> start(std::stringstream& input);

private:

    Tokenizer* tokenizer;
};

#endif // SYNTAX_HPP

// Unknown command
// Incorrect command order
// Syntax Error
// 

