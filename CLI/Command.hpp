#ifndef COMMAND_HPP 
#define COMMAND_HPP

#include <functional>
#include <unordered_map>
#include <vector>
#include <variant>
#include <string>

#include "Tokenizer.hpp"
#include "../Editor.hpp"

using ArgumentsMap = std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>;

struct SCommandInfo {
    std::string name;
    ArgumentsMap arguments;
};

class Command {
public:
    Command() = default;
    Command(std::unique_ptr<ArgumentsMap> args);
    virtual ~Command() = default;
    virtual void execute(std::shared_ptr<Editor>& editor) = 0;

protected:
    int idValidate();
    std::pair<int, int> idPairValidation();
    std::unique_ptr<ArgumentsMap> _arguments;
};

class CmdAddSlide : public Command {
public:
    CmdAddSlide(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class CmdRemoveSlide : public Command {
public:
    CmdRemoveSlide(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class CmdAddShape : public Command {
public:
    CmdAddShape(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class CmdRemoveShape : public Command {
public:
    CmdRemoveShape(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class CmdSlideList : public Command {
public:
    CmdSlideList(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class CmdMoveSlide : public Command {
public:
    CmdMoveSlide(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

#endif // COMMAND_HPP