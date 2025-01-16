#ifndef ADDITEM_ACTION_HPP
#define ADDITEM_ACTION_HPP

#include "IAction.hpp"

class AddItemAction : public IAction {
public:
    explicit AddItemAction(std::shared_ptr<Item> item);

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;

private:
    int itemIndex;
    std::shared_ptr<Item> currentItem;
};


#endif // ADDITEM_ACTION_HPP