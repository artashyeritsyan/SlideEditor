#ifndef ADDSLIDEACTION_HPP
#define ADDSLIDEACTION_HPP

#include "IAction.hpp"

class AddSlideAction : public IAction {
public:
    explicit AddSlideAction(std::shared_ptr<Slide> slide, int slideIndex);
    // explicit AddSlideAction(int index);

    std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) override;

private:
    int slideIndex;
    std::shared_ptr<Slide> currentSlide;
};


#endif // ADDSLIDEACTION_HPP