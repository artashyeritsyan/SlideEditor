#include "MoveItemAction.hpp"

MoveItemAction::MoveItemAction(int id, std::pair<double, double> newPos) : id(id), newPosition(newPos) {};

std::shared_ptr<IAction> MoveItemAction::doAction(std::shared_ptr<Presentation> document) {
    std::pair<double, double> oldPosition = document->getCurrentSlide()->getItemById(id)->getPosition();
    document->moveItem(id, newPosition);

    return std::make_shared<MoveItemAction>(id, oldPosition);
}