#ifndef SEMANTIC_HPP 
#define SEMANTIC_HPP

#include "Command.hpp"
#include "../Models/Presentation.hpp"
#include "SyntaxAnalyzer.hpp"

using CommandsMap = std::unordered_map<std::string, std::function<std::unique_ptr<Command>(std::unique_ptr<ArgumentsMap>)>>;

class SemanticAnalyser {
public:
    SemanticAnalyser(std::shared_ptr<Presentation> pr);

    std::unique_ptr<Command> startSemanticAnalize(const std::shared_ptr<SCommandInfo>& cmdInfo);    

private:
    void initializeCmdMap();
    std::unique_ptr<Command> createCommand(const std::shared_ptr<SCommandInfo> &commandInfo);

private:
    std::unique_ptr<CommandsMap> _commandMap;
    std::shared_ptr<Editor> _editor;
};

#endif // SEMANTIC_HPP