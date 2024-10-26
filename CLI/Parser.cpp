#include "Parser.hpp"

Parser::Parser()
{
    _syntaxAnalyzer = std::make_unique<SyntaxAnalyzer>();
}

std::unique_ptr<Command> Parser::parse(std::stringstream &input)
{
    std::unique_ptr<SCommandInfo> commandInfo = _syntaxAnalyzer->startSyntaxAnalize(input);
    std::unique_ptr<Command> command = _semanticAnalyser->startSemanticAnalize(commandInfo);

    

}
