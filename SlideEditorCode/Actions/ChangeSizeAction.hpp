#ifndef CHANGESIZE_ACTION_HPP
#define CHANGESIZE_ACTION_HPP

#include "IAction.hpp"

class ChangeItemSizeAction : public IAction {
public:
    explicit ChangeItemSizeAction(int id, std::pair<double, double> newSize);

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;

private:
    int id;
    std::pair<double, double> newSize;
};


#endif // CHANGESIZE_ACTION_HPP