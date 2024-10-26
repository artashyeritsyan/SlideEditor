#ifndef SEMANTIC_HPP 
#define SEMANTIC_HPP

#include "Models/Presentation.hpp"
#include "SyntaxAnalyzer.hpp"
#include "Command.hpp"

using CommandsMap = std::unordered_map<std::string, std::function<std::unique_ptr<Command>(argumentsMap)>>;

class SemanticAnalyser {
public:
    SemanticAnalyser(std::shared_ptr<Presentation> pr);

    std::unique_ptr<Command> startSemanticAnalize(const std::unique_ptr<SCommandInfo>& cmdInfo);    

private:
    void initializeCmdMap();
    std::unique_ptr<Command> createCommand(const std::unique_ptr<SCommandInfo> &commandInfo);

private:
    CommandsMap _commandMap;
    std::unique_ptr<Editor> _editor;
};

#endif // SEMANTIC_HPP