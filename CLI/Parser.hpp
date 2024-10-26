#ifndef PARSER_HPP 
#define PARSER_HPP

#include <memory>

#include "SyntaxAnalyzer.hpp"
#include "SemanticAnalyzer.hpp"

class Parser {
public:
    Parser (std::shared_ptr<Presentation> pr);
    std::unique_ptr<Command> parse(std::stringstream &input);


private:
    std::unique_ptr<SyntaxAnalyzer> _syntaxAnalyzer;
    std::unique_ptr<SemanticAnalyser> _semanticAnalyser;
};

#endif // PARSER_HPP