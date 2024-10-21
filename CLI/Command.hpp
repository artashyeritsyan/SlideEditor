#ifndef COMMAND_HPP 
#define COMMAND_HPP

#include <memory>
#include <unordered_map>
#include <vector>
#include <variant>

#include "Tokenizer.hpp"

struct CommandInfo {
    std::string name;
    std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>> arg;
};

class ICommand {
public:
    virtual void execute() = 0;

    static std::unique_ptr<ICommand> create(CommandInfo commandInfo);
};

class CmdAddShape {
    

};

#endif // COMMAND_HPP