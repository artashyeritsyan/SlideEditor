#include "Parser.hpp"

Parser::Parser()
{
    syntaxAnalyzer = std::make_unique<SyntaxAnalyzer>();
}

void Parser::parse(std::stringstream &input)
{
    auto commandMap = syntaxAnalyzer->startSyntaxAnalize(input);

    

}
