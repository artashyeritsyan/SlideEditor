#include "Command.hpp"

using CommandFactory = std::unordered_map<std::string, std::function<std::unique_ptr<ICommand>()>>;

static CommandFactory commandFactory = {
    { "addslide", []() { return std::make_unique<CmdAddShape>(); } },
    { "removeslide", []() { return std::make_unique<CmdRemoveShape>(); } }
};


std::unique_ptr<ICommand> create(const std::unique_ptr<CommandInfo> &commandInfo)
{
    if(commandFactory.find(commandInfo->name) == commandFactory.end()) {
        // throw an exception "Semantic error, Wrong command"
        std::cerr << "Semantic error, Wrong command" << std::endl;
    }
  
    std::unique_ptr<ICommand> command = commandFactory[commandInfo->name]();

    for (const auto& arg : commandInfo->arguments) {
        if (arg.first == "pos") {
            command.set_X(arg.second[0]);
            if (arg.second.size() == 2) {
                command.set_Y(arg.second[0]);
            }
        }
        if (arg.first == "size") {
            command.setWidth(arg.second[0]);
            if (arg.second.size() == 2) {
                command.setHeigth(arg.second[0]);
            }
        }
    }


}
