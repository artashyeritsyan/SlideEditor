#include "MoveSlideAction.hpp"

MoveSlideAction::MoveSlideAction(int oldIndex, int newIndex) : _oldIndex(oldIndex), _newIndex(newIndex) {};

std::shared_ptr<IAction> MoveSlideAction::doAction(std::shared_ptr<Presentation> document)
{
    document->moveSlide(_oldIndex, _newIndex);
    return std::make_shared<MoveSlideAction>(_newIndex, _oldIndex);
}