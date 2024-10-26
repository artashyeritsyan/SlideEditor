#include "SemanticAnalyzer.hpp"

SemanticAnalyser::SemanticAnalyser()
{
    initializeCmdMap();
}

void SemanticAnalyser::initializeCmdMap()
{
// Use pattern Prototype to create the prototypes of each Command Class with their own default values and then just copy it and change values if needed
    _commandMap = {
        { "addslide", [](argumentsMap args) { return std::make_unique<CmdAddSlide>(args); } },
        { "addshape", [](argumentsMap args) { return std::make_unique<CmdAddShape>(args); } },
        { "removeslide", [](argumentsMap args) { return std::make_unique<CmdRemoveSlide>(args); } },
        { "removeshape", [](argumentsMap args) { return std::make_unique<CmdRemoveShape>(args); } }
    };
}

std::unique_ptr<Command> SemanticAnalyser::startSemanticAnalize(const std::unique_ptr<SCommandInfo> &cmdInfo)
{
    return createCommand(cmdInfo);
}

std::unique_ptr<Command> SemanticAnalyser::createCommand(const std::unique_ptr<SCommandInfo> &commandInfo)
{
    if(_commandMap.find(commandInfo->name) == _commandMap.end()) {
        // throw an exception "Semantic error, Wrong command"
        std::cerr << "Semantic error, Wrong command" << std::endl;
    }

    return _commandMap[commandInfo->name](commandInfo->arguments);
}


// for (const auto& arg : commandInfo->arguments) {
//     if (arg.first == "pos") {
//         command.set_X(arg.second[0]);
//         if (arg.second.size() == 2) {
//             command.set_Y(arg.second[0]);
//         }
//     }
//     if (arg.first == "size") {
//         command.setWidth(arg.second[0]);
//         if (arg.second.size() == 2) {
//             command.setHeigth(arg.second[0]);
//         }
//     }
// }