#ifndef REMOVEITEM_ACTION_HPP
#define REMOVEITEM_ACTION_HPP

#include "IAction.hpp"

class RemoveItemAction : public IAction {
public:
    explicit RemoveItemAction(std::shared_ptr<Item> item);

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;

private:
    int itemIndex;
    std::shared_ptr<Item> currentItem;
};


#endif // REMOVEITEM_ACTION_HPP