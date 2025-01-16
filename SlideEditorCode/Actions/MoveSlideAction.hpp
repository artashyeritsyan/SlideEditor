#ifndef MOVESLIDE_ACTION_HPP
#define MOVESLIDE_ACTION_HPP

#include "IAction.hpp"

class MoveSlideAction : public IAction {
public:
    explicit MoveSlideAction(int oldIndex, int newIndex);

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;

private:
    int _oldIndex;
    int _newIndex;
};


#endif // MOVESLIDE_ACTION_HPP