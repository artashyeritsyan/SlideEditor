#include "Parser.hpp"

Parser::Parser(std::shared_ptr<Presentation> pr)
{
    _syntaxAnalyzer = std::make_unique<SyntaxAnalyzer>();
    _semanticAnalyser = std::make_unique<SemanticAnalyser>(pr);
}

std::shared_ptr<Command> Parser::parse(std::stringstream &input)
{
    std::shared_ptr<SCommandInfo> commandInfo = std::move(_syntaxAnalyzer->startSyntaxAnalize(input));
    std::shared_ptr<Command> command = std::move(_semanticAnalyser->startSemanticAnalize(std::move(commandInfo)));

}
