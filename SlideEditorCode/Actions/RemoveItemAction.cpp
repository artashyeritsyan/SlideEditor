#include "AddItemAction.hpp"
#include "RemoveItemAction.hpp"

RemoveItemAction::RemoveItemAction(std::shared_ptr<Item> item) : currentItem(item) {}

std::shared_ptr<IAction> RemoveItemAction::doAction(std::shared_ptr<Presentation> document) {
    auto action = std::make_shared<AddItemAction>(currentItem);
    document->getCurrentSlide()->removeItem(currentItem->getId());

    return action;
}
