#include "Semantic.hpp"


SemanticAnalyzer::SemanticAnalyzer() {
    initializeCommandMap();
}

void SemanticAnalyzer::initializeCommandMap() {
    _commandMap["addSlide"] = [](argumentsMap args) -> std::unique_ptr<Command> {
        return std::make_unique<CmdAddSlide>(std::make_unique<argumentsMap>(std::move(args)));
    };

    _commandMap["removeSlide"] = [](argumentsMap args) -> std::unique_ptr<Command> {
        return std::make_unique<CmdRemoveSlide>(std::make_unique<argumentsMap>(std::move(args)));
    };

    _commandMap["addShape"] = [](argumentsMap args) -> std::unique_ptr<Command> {
        return std::make_unique<CmdAddShape>(std::make_unique<argumentsMap>(std::move(args)));
    };

    _commandMap["removeShape"] = [](argumentsMap args) -> std::unique_ptr<Command> {
        return std::make_unique<CmdRemoveShape>(std::make_unique<argumentsMap>(std::move(args)));
    };
}

std::unique_ptr<Command> 
SemanticAnalyzer::createCommand(const std::unique_ptr<SCommandInfo>& commandInfo) {
    auto it = _commandMap.find(commandInfo->name);
    if (it != _commandMap.end()) {
        return it->second(commandInfo->arguments); 
    }
    return nullptr;  
}

std::unique_ptr<Command> 
SemanticAnalyzer::startSemanticAnalyze(const std::unique_ptr<SCommandInfo>& cmdInfo) {
    std::unique_ptr<Command> command = createCommand(cmdInfo);
    if (command) {
        command->execute();  
    } else {
        std::cerr << "Error: Unknown command '" << cmdInfo->name << "'." << std::endl;
    }
    return command;
}
