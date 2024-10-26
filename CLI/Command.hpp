#ifndef COMMAND_HPP 
#define COMMAND_HPP

#include <memory>
#include <functional>
#include <unordered_map>
#include <vector>
#include <variant>

#include "Tokenizer.hpp"

using argumentsMap = std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>;

struct SCommandInfo {
    std::string name;
    argumentsMap arguments;
};

class Command {
public:
    Command();
    Command(std::unique_ptr<argumentsMap> args);
    virtual ~Command();
    virtual void execute() = 0;

protected:
   std::unique_ptr<argumentsMap> arguments;
};

class CmdAddSlide : public Command {
    CmdAddSlide(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
};

class CmdRemoveSlide : public Command {
    CmdRemoveSlide(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
};

class CmdAddShape : public Command {
public:
    CmdAddShape(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
};

class CmdRemoveShape : public Command {
    CmdRemoveShape(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
};

#endif // COMMAND_HPP