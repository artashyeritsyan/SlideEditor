#include "Command.hpp"

#include "../Actions/AddItemAction.hpp"
#include "../Actions/AddSlideAction.hpp"
#include "../Actions/ChangeSizeAction.hpp"
#include "../Actions/RemoveItemAction.hpp"
#include "../Actions/RemoveSlideAction.hpp"
#include "../Actions/MoveItemAction.hpp"
#include "../Actions/MoveSlideAction.hpp"
#include "../Actions/NextPrevSlidesAction.hpp"
#include "../Application/Application.hpp"
#include "../Editor.hpp"



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

void AddSlideCommand::execute()
{    
    int slideId = idVerify();
    int slideIndex = slideId != -1 ? slideId - 1 : slideId;

    std::shared_ptr<Slide> slide = std::make_unique<Slide>();
    auto addAction = std::make_shared<AddSlideAction>(slide, slideIndex);
    Application::getInstance().getEditor()->process(addAction);
}

void RemoveSlideCommand::execute()
{
    int slideId = idVerify();
    int slideIndex = slideId != -1 ? slideId - 1 : slideId;

    auto removeAction = std::make_shared<RemoveSlideAction>(slideIndex);
    Application::getInstance().getEditor()->process(removeAction);
}

void MoveSlideCommand::execute()
{
    const auto& slideIds = idPairVerify();

    auto action = std::make_shared<MoveSlideAction>(slideIds.first - 1, slideIds.second - 1);
    Application::getInstance().getEditor()->process(action);
}

void NextSlideCommand::execute()
{
    // auto action = std::make_shared<NextSlideAction>();
    // Application::getInstance().getEditor()->process(action);

    Application::getInstance().getPresentation()->nextSlide();
}

void PrevSlideCommand::execute()
{
    // auto action = std::make_shared<PrevSlideAction>();
    // Application::getInstance().getEditor()->process(action);

    Application::getInstance().getPresentation()->prevSlide();
}

void AddRectangleCommand::execute()
{
    auto presentation = Application::getInstance().getPresentation();
    presentation->addItem(ItemTypeEnum::Rectangle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
    auto item = presentation->getCurrentSlide()->getItemList().back();

    auto action = std::make_shared<AddItemAction>(item);
    presentation->getCurrentSlide()->removeItem(item->getId());

    Application::getInstance().getEditor()->process(action);
}

void AddCircleCommand::execute()
{
    auto presentation = Application::getInstance().getPresentation();
    presentation->addItem(ItemTypeEnum::Circle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
    auto item = presentation->getCurrentSlide()->getItemList().back();

    auto action = std::make_shared<AddItemAction>(item);
    presentation->getCurrentSlide()->removeItem(item->getId());

    Application::getInstance().getEditor()->process(action);
}

void AddTriangleCommand::execute()
{
    auto presentation = Application::getInstance().getPresentation();
    presentation->addItem(ItemTypeEnum::Triangle, posOrSizeVerify("pos"), posOrSizeVerify("size"), textVerify());
    auto item = presentation->getCurrentSlide()->getItemList().back();

    auto action = std::make_shared<AddItemAction>(item);
    presentation->getCurrentSlide()->removeItem(item->getId());

    Application::getInstance().getEditor()->process(action);
}

void RemoveItemCommand::execute()
{
    int itemId = idVerify();
    if (itemId == -1 || itemId == 0) {
        throw CLIException("Invalid id");
    }
    const auto& item = Application::getInstance().getPresentation()->getCurrentSlide()->getItemById(itemId);

    auto action = std::make_shared<RemoveItemAction>(item);
    Application::getInstance().getEditor()->process(action);
}

void MoveItemCommand::execute()
{
    auto action = std::make_shared<MoveItemAction>(idVerify(), posOrSizeVerify("pos"));
    Application::getInstance().getEditor()->process(action);
}

void ChangeSizeCommand::execute()
{
    auto action = std::make_shared<ChangeItemSizeAction>(idVerify(), posOrSizeVerify("size"));
    Application::getInstance().getEditor()->process(action);
}


void RenameItemCommand::execute()
{
}


// Refactored, but without undo redo logic

void BringForwardCommand::execute()
{
    Application::getInstance().getPresentation()->getCurrentSlide()->bringItemForward(idVerify());
}

void SendBackwardCommand::execute()
{
    Application::getInstance().getPresentation()->getCurrentSlide()->sendItemBackward(idVerify());
}

void BringToFrontCommand::execute()
{
    Application::getInstance().getPresentation()->getCurrentSlide()->bringItemToFront(idVerify());
}

void SendToBackCommand::execute()
{
    Application::getInstance().getPresentation()->getCurrentSlide()->sendItemToBack(idVerify());
}

//


void SaveCommand::execute()
{
    std::string path = pathVerify();
    Application::getInstance().getSerializaton()->serialize(path);
}

void LoadCommand::execute()
{
    std::string path = pathVerify();
    Application::getInstance().getSerializaton()->deserialize(path);
}

void UndoCommand::execute()
{
    Application::getInstance().getEditor()->undo();
}

void RedoCommand::execute()
{
    Application::getInstance().getEditor()->redo();
}

void SlideListCommand::execute()
{
    Application::getInstance().getVisualization()->printSlides();
}

void ItemListCommand::execute()
{
    Application::getInstance().getVisualization()->printItems();
}