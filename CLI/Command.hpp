#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <memory>
#include <functional>
#include <unordered_map>
#include <vector>
#include <variant>
#include <iostream>  

#include "Tokenizer.hpp"

using argumentsMap = std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>;

struct SCommandInfo {
    std::string name;
    argumentsMap arguments;
};

class Command {
public:
    Command() = default;
    Command(std::unique_ptr<argumentsMap> args) : arguments(std::move(args)) {}
    virtual ~Command() = default;

    virtual void execute() = 0;

protected:
    std::unique_ptr<argumentsMap> arguments;
};

class CmdAddSlide : public Command {
public:
    CmdAddSlide(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}

    void execute() override {
        std::cout << "Executing: Add Slide" << std::endl;
    }
};

class CmdRemoveSlide : public Command {
public:
    CmdRemoveSlide(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}

    void execute() override {
        std::cout << "Executing: Remove Slide" << std::endl;
    }
};

class CmdAddShape : public Command {
public:
    CmdAddShape(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}

    void execute() override {
        std::cout << "Executing: Add Shape" << std::endl;
    }
};

class CmdRemoveShape : public Command {
public:
    CmdRemoveShape(std::unique_ptr<argumentsMap> args) : Command(std::move(args)) {}

    void execute() override {
        std::cout << "Executing: Remove Shape" << std::endl;
    }
};

#endif // COMMAND_HPP
