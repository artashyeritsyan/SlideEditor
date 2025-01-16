#include "NextPrevSlidesAction.hpp"


std::shared_ptr<IAction> NextSlideAction::doAction(std::shared_ptr<Presentation> document) {
    document->nextSlide();
    return std::make_shared<PrevSlideAction>();
}

std::shared_ptr<IAction> PrevSlideAction::doAction(std::shared_ptr<Presentation> document) {
    document->prevSlide();
    return std::make_shared<NextSlideAction>();
}
