#include "Command.hpp"

Command::Command(std::unique_ptr<argumentsMap> args)
{
    _arguments = std::move(args);
}

void CmdAddSlide::execute(Editor& editor)
{
    editor.addSlide();
}

void CmdRemoveSlide::execute(Editor& editor)
{
    if(_arguments->find("i") == _arguments->end()) {
        std::cerr << "Error: Missing required argument 'i' for slide index." << std::endl;
        return;
    }

    auto it = _arguments->find("i");
    if (it == _arguments->end()) {
        std::cerr << "Error: Missing required argument 'i' for slide index." << std::endl;
        return;
    }

    int slideIndex = std::get<int>(it->second[0]);

    editor.removeSlide(slideIndex);
}

void CmdAddShape::execute(Editor& editor)
{
}

void CmdRemoveShape::execute(Editor& editor)
{
}
