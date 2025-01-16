#ifndef NEXTPREVSLIDESACTION_HPP
#define NEXTPREVSLIDESACTION_HPP

#include "IAction.hpp"

class PrevSlideAction;

class NextSlideAction : public IAction {
public:
    explicit NextSlideAction() = default;

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;
};

class PrevSlideAction : public IAction {
public:
    explicit PrevSlideAction() = default;

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;
};

#endif // NEXTPREVSLIDESACTION_HPP