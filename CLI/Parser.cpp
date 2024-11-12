#include "Parser.hpp"

Parser::Parser(std::shared_ptr<Presentation> pr)
{
    _syntaxAnalyzer = std::make_unique<SyntaxAnalyzer>();
    _semanticAnalyser = std::make_unique<SemanticAnalyser>(pr);
}

std::shared_ptr<Command> Parser::parse(std::stringstream &input)
{
    std::shared_ptr<SCommandInfo> commandInfo = _syntaxAnalyzer->startSyntaxAnalize(input);
    std::shared_ptr<Command> command = _semanticAnalyser->startSemanticAnalize(commandInfo);

    return command;

}
