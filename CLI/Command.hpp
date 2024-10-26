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
    Command() = default;
    Command(std::unique_ptr<argumentsMap> args);
    virtual ~Command() = default;

    virtual void execute() = 0;

protected:
   std::unique_ptr<argumentsMap> arguments;
};

class CmdAddSlide : public Command {
    CmdAddSlide(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
    void execute() override;
};

class CmdRemoveSlide : public Command {
    CmdRemoveSlide(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
    void execute() override;
};

class CmdAddShape : public Command {
public:
    CmdAddShape(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
    void execute() override;
};

class CmdRemoveShape : public Command {
    CmdRemoveShape(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
    void execute() override;
};

#endif // COMMAND_HPP