#include "ChangeSizeAction.hpp"

ChangeItemSizeAction::ChangeItemSizeAction(int id, std::pair<double, double> newPos) : id(id), newSize(newPos) {};

std::shared_ptr<IAction> ChangeItemSizeAction::doAction(std::shared_ptr<Presentation> document) {
    std::pair<double, double> oldSize = std::make_pair(document->getCurrentSlide()->getItemById(id)->getWidth(),
                                                       document->getCurrentSlide()->getItemById(id)->getHeight());
    
    document->changeItemSize(id, newSize);

    return std::make_shared<ChangeItemSizeAction>(id, oldSize);
}