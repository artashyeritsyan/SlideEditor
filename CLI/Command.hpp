#ifndef COMMAND_HPP 
#define COMMAND_HPP

#include <memory>
#include <functional>
#include <unordered_map>
#include <vector>
#include <variant>

#include "Tokenizer.hpp"

static std::unique_ptr<ICommand> create(const std::unique_ptr<CommandInfo>& commandInfo);

struct CommandInfo {
    std::string name;
    std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>> arguments;
};

class ICommand {
public:
    virtual void execute() = 0;

    
};

class CmdAddShape : public ICommand {
    
};

class CmdRemoveShape : public ICommand {

};

#endif // COMMAND_HPP