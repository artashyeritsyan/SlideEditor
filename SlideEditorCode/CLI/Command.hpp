#ifndef COMMAND_HPP 
#define COMMAND_HPP

#include <functional>
#include <unordered_map>
#include <variant>
#include <vector>
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
    /// TODO: Make this functions static and move them to .cpp file
    int idVerify();
    std::pair<int, int> idPairVerify();
    std::pair<double, double> posOrSizeVerify(const std::string& flag);
    std::string textVerify();
    std::string pathVerify();

protected:
    std::unique_ptr<ArgumentsMap> _arguments;
};

class AddSlideCommand : public Command {
public:
    AddSlideCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class RemoveSlideCommand : public Command {
public:
    RemoveSlideCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class SlideListCommand : public Command {
public:
    SlideListCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class MoveSlideCommand : public Command {
public:
    MoveSlideCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class NextSlideCommand : public Command {
public:
    NextSlideCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class PrevSlideCommand : public Command {
public:
    PrevSlideCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class AddRectangleCommand : public Command {
public:
    AddRectangleCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class AddCircleCommand : public Command {
public:
    AddCircleCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class AddTriangleCommand : public Command {
public:
    AddTriangleCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class RemoveItemCommand : public Command {
public:
    RemoveItemCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class MoveItemCommand : public Command {
public:
    MoveItemCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class RenameItemCommand : public Command { 
public:
    RenameItemCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class ChangeSizeCommand : public Command { 
public:
    ChangeSizeCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class ItemListCommand : public Command { 
public:
    ItemListCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class BringForwardCommand : public Command {
public:
    BringForwardCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class SendBackwardCommand : public Command {
public:
    SendBackwardCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class BringToFrontCommand : public Command {
public:
    BringToFrontCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class SendToBackCommand : public Command {
public:
    SendToBackCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class SaveCommand : public Command {
public:
    SaveCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class LoadCommand : public Command {
public:
    LoadCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class UndoCommand : public Command {
public: 
    UndoCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

class RedoCommand : public Command {
public: 
    RedoCommand(std::unique_ptr<ArgumentsMap> args) : Command(std::move(args)) {}
    void execute(std::shared_ptr<Editor>& editor) override;
};

#endif // COMMAND_HPP