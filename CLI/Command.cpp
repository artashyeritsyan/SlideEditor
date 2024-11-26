#include "Command.hpp"

Command::Command(std::unique_ptr<ArgumentsMap> args)
    : _arguments(std::move(args)) {}

int Command::idValidate()
{
    int slideId = -1;

    auto it = _arguments->find("id");
    if (it != _arguments->end()) {
        if (it->second.size() == 1) {
            slideId = std::get<int>(it->second[0]);
        }
        else {
            throw CLIException("Too many arguments for -id");
        }
    }

    return slideId;
}

std::pair<int, int> Command::idPairValidation()
{
    auto it = _arguments->find("id");

    if (it != _arguments->end()) {

        if (it->second.size() != 2) {
            throw CLIException("2 arguments required for this command");
        }
        else {            
            return (std::pair<int, int>(std::get<int>(it->second[0]), std::get<int>(it->second[1])));
        }
    }
    else {
        throw CLIException("Arguments not found");
    }
}

void CmdAddSlide::execute(std::shared_ptr<Editor>& editor)
{    
    int slideId = idValidate();
    editor->addSlide(slideId);
}

void CmdRemoveSlide::execute(std::shared_ptr<Editor>& editor)
{
    int slideId = idValidate();
    editor->removeSlide(slideId);
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

void CmdMoveSlide::execute(std::shared_ptr<Editor> &editor)
{
    const auto& slideIds = idPairValidation();
    editor->moveSlide(slideIds.first, slideIds.second);
}
