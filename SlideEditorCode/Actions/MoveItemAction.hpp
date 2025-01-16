#ifndef MOVEITEM_ACTION_HPP
#define MOVEITEM_ACTION_HPP

#include "IAction.hpp"

class MoveItemAction : public IAction {
public:
    explicit MoveItemAction(int id, std::pair<double, double> newPos);

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;

private:
    int id;
    std::pair<double, double> newPosition;
};


#endif // MOVEITEM_ACTION_HPP