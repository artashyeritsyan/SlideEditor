#include "Command.hpp"

#include "../Actions/AddItemAction.hpp"
#include "../Actions/AddSlideAction.hpp"
#include "../Actions/ChangeSizeAction.hpp"
#include "../Actions/RemoveItemAction.hpp"
#include "../Actions/RemoveSlideAction.hpp"
#include "../Actions/MoveItemAction.hpp"
#include "../Actions/MoveSlideAction.hpp"
#include "../Actions/NextPrevSlidesAction.hpp"


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

// Refactored
void AddSlideCommand::execute(std::shared_ptr<Editor>& editor)
{    
    int slideId = idVerify();
    int slideIndex = slideId != -1 ? slideId - 1 : slideId;

    std::shared_ptr<Slide> slide = std::make_unique<Slide>();
    auto addAction = std::make_shared<AddSlideAction>(slide, slideIndex);
    editor->process(addAction);
}

// Refactored
void RemoveSlideCommand::execute(std::shared_ptr<Editor>& editor)
{
    int slideId = idVerify();
    int slideIndex = slideId != -1 ? slideId - 1 : slideId;

    auto removeAction = std::make_shared<RemoveSlideAction>(slideIndex);
    editor->process(removeAction);
}

void SlideListCommand::execute(std::shared_ptr<Editor> &editor)
{
    /// TODO: move print part to View
    editor->printSlides();
}

// Refactored
void MoveSlideCommand::execute(std::shared_ptr<Editor> &editor)
{
    const auto& slideIds = idPairVerify();

    auto action = std::make_shared<MoveSlideAction>(slideIds.first - 1, slideIds.second - 1);
    editor->process(action);
}

// Refactored
void NextSlideCommand::execute(std::shared_ptr<Editor> &editor)
{
    auto action = std::make_shared<NextSlideAction>();
    editor->process(action);
}

// Refactored
void PrevSlideCommand::execute(std::shared_ptr<Editor> &editor)
{
    auto action = std::make_shared<PrevSlideAction>();
    editor->process(action);
}

// Refactored
void AddRectangleCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->getPresentation()->addItem(ItemTypeEnum::Rectangle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
    auto item = editor->getPresentation()->getCurrentSlide()->getItemList().back();

    auto addAction = std::make_shared<AddItemAction>(item);
    editor->getPresentation()->getCurrentSlide()->removeItem(item->getId());

    editor->process(addAction);
}

// Refactored
void AddCircleCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->getPresentation()->addItem(ItemTypeEnum::Circle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
    auto item = editor->getPresentation()->getCurrentSlide()->getItemList().back();

    auto addAction = std::make_shared<AddItemAction>(item);
    editor->getPresentation()->getCurrentSlide()->removeItem(item->getId());

    editor->process(addAction);
}

// Refactored
void AddTriangleCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->getPresentation()->addItem(ItemTypeEnum::Triangle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
    auto item = editor->getPresentation()->getCurrentSlide()->getItemList().back();

    auto action = std::make_shared<AddItemAction>(item);
    editor->getPresentation()->getCurrentSlide()->removeItem(item->getId());

    editor->process(action);
}

// Refactored
void RemoveItemCommand::execute(std::shared_ptr<Editor> &editor)
{
    int itemId = idVerify();
    if (itemId == -1 || itemId == 0) {
        throw CLIException("Invalid id");
    }
    const auto& item = editor->getPresentation()->getCurrentSlide()->getItemById(itemId);

    auto action = std::make_shared<RemoveItemAction>(item);
    editor->process(action);
}

// Refactored
void MoveItemCommand::execute(std::shared_ptr<Editor> &editor)
{
    auto action = std::make_shared<MoveItemAction>(idVerify(), posOrSizeVerify("pos"));
    editor->process(action);
}

// Refactored
void ChangeSizeCommand::execute(std::shared_ptr<Editor> &editor)
{
    auto action = std::make_shared<ChangeItemSizeAction>(idVerify(), posOrSizeVerify("size"));
    editor->process(action);
}


void RenameItemCommand::execute(std::shared_ptr<Editor> &editor)
{
}

void ItemListCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->printItems();
}


// Refactored, but without undo redo logic

void BringForwardCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->getPresentation()->getCurrentSlide()->bringItemForward(idVerify());
}

void SendBackwardCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->getPresentation()->getCurrentSlide()->sendItemBackward(idVerify());
}

void BringToFrontCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->getPresentation()->getCurrentSlide()->bringItemToFront(idVerify());
}

void SendToBackCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->getPresentation()->getCurrentSlide()->sendItemToBack(idVerify());
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

void UndoCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->undo();
}

void RedoCommand::execute(std::shared_ptr<Editor> &editor)
{
    editor->redo();
}
