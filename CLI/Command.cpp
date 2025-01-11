#include "Command.hpp"

Command::Command(std::unique_ptr<ArgumentsMap> args)
    : _arguments(std::move(args)) {}

int Command::idVerify()
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

std::pair<int, int> Command::idPairVerify()
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

std::pair<double, double> Command::posOrSizeVerify(const std::string& flag) 
{
    std::pair<double, double> result = (flag == "size") ? std::make_pair(10.0, 10.0) : std::make_pair(0.0, 0.0);

    auto it = _arguments->find(flag);
    if (it != _arguments->end()) {
        switch (it->second.size()) {
        case 0:
            break;
        case 1:
            result.first = std::get<double>(it->second[0]);
            break;
        case 2:
            result = std::pair<double, double>(std::get<double>(it->second[0]), std::get<double>(it->second[1]));
            break;
        default:
            throw CLIException("Too many arguments for -" + flag);
        }
    }

    return result;
}

/// TODO: pathVerify() and textVerify() are very similar. Consider refactoring them into one function.
std::string Command::textVerify()
{
    std::string text = "";
    auto it = _arguments->find("t");

    if (it != _arguments->end()) {

        if (it->second.size() > 1) {
            throw CLIException("Too many arguments for -t option");
        }
        else {            
            text = std::get<std::string>(it->second[0]);
        }
    }
    return text;
}

std::string Command::pathVerify()
{
    std::string path = "";

    // "f" is for file path
    auto it = _arguments->find("f");

    if (it != _arguments->end()) {

        if (it->second.size() > 1) {
            throw CLIException("Too many arguments for -f option");
        }
        else {            
            path = std::get<std::string>(it->second[0]);
        }
    }
    return path;
}

void AddSlideCommand::execute(std::shared_ptr<Editor>& editor)
{    
    int slideId = idVerify();
    editor->addSlide(slideId);
}

void RemoveSlideCommand::execute(std::shared_ptr<Editor>& editor)
{
    int slideId = idVerify();
    editor->removeSlide(slideId);
}

void SlideListCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->printSlides();
}

void MoveSlideCommand::execute(std::shared_ptr<Editor> &editor)
{
    const auto& slideIds = idPairVerify();
    editor->moveSlide(slideIds.first, slideIds.second);
}

void NextSlideCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->openNextSlide();
}

void PrevSlideCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->openPrevSlide();
}

void AddRectangleCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->addItem(ItemTypeEnum::Rectangle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
}

void AddCircleCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->addItem(ItemTypeEnum::Circle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
}

void AddTriangleCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->addItem(ItemTypeEnum::Triangle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
}

void RemoveItemCommand::execute(std::shared_ptr<Editor> &editor)
{
    int itemId = idVerify();
    if (itemId == -1 || itemId == 0) {
        throw CLIException("Invalid id");
    }

    editor->removeItem(itemId);
}

void MoveItemCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->moveItem(idVerify(), posOrSizeVerify("pos"));
}

void RenameItemCommand::execute(std::shared_ptr<Editor> &editor)
{
}

void ItemListCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->printItems();
}

void ChangeSizeCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->changeItemSize(idVerify(), posOrSizeVerify("size"));
}

void BringForwardCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->bringItemForward(idVerify());
}

void SendBackwardCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->sendItemBackward(idVerify());
}

void BringToFrontCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->bringItemToFront(idVerify());
}

void SendToBackCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->sendItemToBack(idVerify());
}

void SaveCommand::execute(std::shared_ptr<Editor> &editor)
{
    std::string path = pathVerify();
    editor->saveFile(path);
}

void LoadCommand::execute(std::shared_ptr<Editor> &editor)
{
    std::string path = pathVerify();
    editor->loadFile(path);
}
