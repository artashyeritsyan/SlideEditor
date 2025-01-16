#ifndef REMOVESLIDEACTION_HPP
#define REMOVESLIDEACTION_HPP

#include "IAction.hpp"

class RemoveSlideAction : public IAction {
public:
    explicit RemoveSlideAction(int slideIndex);

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;

private:
    int slideIndex;
};


#endif // REMOVESLIDEACTION_HPP
