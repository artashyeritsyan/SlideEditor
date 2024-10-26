#ifndef SEMANTIC_HPP
#define SEMANTIC_HPP

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

#include "Command.hpp"

class SemanticAnalyzer {
public:
    SemanticAnalyzer();

    std::unique_ptr<Command> createCommand(const std::unique_ptr<SCommandInfo>& commandInfo);
    std::unique_ptr<Command> startSemanticAnalyze(const std::unique_ptr<SCommandInfo>& cmdInfo);

private:
    std::unordered_map<std::string, std::function<std::unique_ptr<Command>(argumentsMap)>> _commandMap;

    void initializeCommandMap();
};

#endif //SEMANTIC_HPP