#include "Command.hpp"

Command::Command(std::shared_ptr<argumentsMap> args)
{
    _arguments = std::move(args);
}

int Command::indexValidate()
{
    int slideIndex = -1;
    if(_arguments->find("i") == _arguments->end()) {
        std::cerr << "Error: Missing required argument 'i' for slide index." << std::endl;
        return slideIndex;
    }

    auto it = _arguments->find("i");
    if (it == _arguments->end()) {
        std::cerr << "Error: Missing required argument 'i' for slide index." << std::endl;
        return slideIndex;
    }

    slideIndex = std::get<int>(it->second[0]);
    return slideIndex;
}

void CmdAddSlide::execute(std::shared_ptr<Editor>& editor)
{    
    int slideIndex = indexValidate();

    editor->addSlide(slideIndex);
}

void CmdRemoveSlide::execute(std::shared_ptr<Editor>& editor)
{
    int slideIndex = indexValidate();

    editor->removeSlide(slideIndex);
}

void CmdAddShape::execute(std::shared_ptr<Editor>& editor)
{
}

void CmdRemoveShape::execute(std::shared_ptr<Editor>& editor)
{
}
