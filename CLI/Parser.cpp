#include "Parser.hpp"

Parser::Parser()
{
    _syntaxAnalyzer = std::make_unique<SyntaxAnalyzer>();
}

void Parser::parse(std::stringstream &input)
{
    std::unique_ptr<SCommandInfo> commandInfo = _syntaxAnalyzer->startSyntaxAnalize(input);
    std::unique_ptr<Command> command = _semanticAnalyser->startSemanticAnalize(commandInfo);

    

}
