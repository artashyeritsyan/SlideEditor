#include "SemanticAnalyzer.hpp"

SemanticAnalyser::SemanticAnalyser()
{
    _commandMap = std::make_unique<CommandsMap>();
    
    initializeCmdMap();
}

void SemanticAnalyser::initializeCmdMap()
{
    *_commandMap = {
        { "addslide", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<AddSlideCommand>(std::move(args)); }},
        { "removeslide", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<RemoveSlideCommand>(std::move(args)); }},
        { "slidelist", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<SlideListCommand>(std::move(args)); }},
        { "moveslide", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<MoveSlideCommand>(std::move(args)); }},
        { "nextslide", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<NextSlideCommand>(std::move(args)); }},
        { "prevslide", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<PrevSlideCommand>(std::move(args)); }},
        { "addrect", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<AddRectangleCommand>(std::move(args)); }},
        { "addcircle", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<AddCircleCommand>(std::move(args)); }},
        { "addtriangle", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<AddTriangleCommand>(std::move(args)); }},
        { "removeitem", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<RemoveItemCommand>(std::move(args)); }},
        { "moveitem", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<MoveItemCommand>(std::move(args)); }},
        { "changesize", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<ChangeSizeCommand>(std::move(args)); }},
        { "itemlist", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<ItemListCommand>(std::move(args)); }},
        { "bringforward", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<BringForwardCommand>(std::move(args)); }},
        { "sendbackward", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<SendBackwardCommand>(std::move(args)); }},
        { "bringtofront", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<BringToFrontCommand>(std::move(args)); }},
        { "sendtoback", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<SendToBackCommand>(std::move(args)); }},
        { "save", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<SaveCommand>(std::move(args)); }},
        { "load", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<LoadCommand>(std::move(args)); }},
        { "undo", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<UndoCommand>(std::move(args)); }},
        { "redo", [](std::unique_ptr<ArgumentsMap> args) { return std::make_unique<RedoCommand>(std::move(args)); }}
    };
}

std::unique_ptr<Command> SemanticAnalyser::startSemanticAnalize(const std::shared_ptr<SCommandInfo> &cmdInfo)
{
    return std::move(createCommand(cmdInfo));
}

std::unique_ptr<Command> SemanticAnalyser::createCommand(const std::shared_ptr<SCommandInfo> &commandInfo)
{
    if(_commandMap->find(commandInfo->name) == _commandMap->end()) {
        throw CLIException("Semantic error, Wrong command");
    }

    return std::move((*_commandMap)[commandInfo->name](std::make_unique<ArgumentsMap>(commandInfo->arguments)));
}