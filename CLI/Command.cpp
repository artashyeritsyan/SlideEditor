#include "Command.hpp"

Command::Command(std::unique_ptr<ArgumentsMap> args)
    : _arguments(std::move(args)) {}

int Command::indexValidate()
{
    int slideIndex = -1;

    auto it = _arguments->find("id");
    if (it == _arguments->end()) {
        throw CLIException("Missing required argument '-id' for slide index.");
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

void CmdSlideList::execute(std::shared_ptr<Editor> &editor)
{
    editor->printSlides();
}
