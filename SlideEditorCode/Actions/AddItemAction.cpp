#include "AddItemAction.hpp"
#include "RemoveItemAction.hpp"

AddItemAction::AddItemAction(std::shared_ptr<Item> item) : currentItem(item) {}

std::shared_ptr<IAction> AddItemAction::doAction(std::shared_ptr<Presentation> document)
{
    document->getCurrentSlide()->addItem(currentItem);
    return make_shared<RemoveItemAction>(currentItem);
};
