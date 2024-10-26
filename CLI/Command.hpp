#ifndef COMMAND_HPP 
#define COMMAND_HPP

#include <functional>
#include <unordered_map>
#include <vector>
#include <variant>
#include <string>

#include "Tokenizer.hpp"
#include "Editor.hpp"

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

    virtual void execute(Editor& editor) = 0;

protected:
   std::unique_ptr<argumentsMap> arguments;
};

class CmdAddSlide : public Command {
    CmdAddSlide(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
    void execute(Editor& editor) override;
};

class CmdRemoveSlide : public Command {
    CmdRemoveSlide(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
    void execute(Editor& editor) override;
};

class CmdAddShape : public Command {
public:
    CmdAddShape(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
    void execute(Editor& editor) override;
};

class CmdRemoveShape : public Command {
    CmdRemoveShape(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}
    void execute(Editor& editor) override;
};

#endif // COMMAND_HPP