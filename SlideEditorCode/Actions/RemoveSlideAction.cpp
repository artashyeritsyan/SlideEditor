#include "RemoveSlideAction.hpp"
#include "AddSlideAction.hpp"

RemoveSlideAction::RemoveSlideAction(int slideIndex) : slideIndex(slideIndex) {};

std::shared_ptr<IAction> RemoveSlideAction::doAction(std::shared_ptr<Presentation> document) {
    auto action = std::make_shared<AddSlideAction>(document->getSlideByIndex(slideIndex), slideIndex);
    document->removeSlide(slideIndex);
    
    return action;
}


