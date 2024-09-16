#include "Controller.hpp"

void Controller::addSlide(int slideId = 0)
{
    if(slideId == 0) {
        pres->addSlide(pres->slidesCount());
    }
    else {
        pres->addSlide(--slideId);
    }
}

void Controller::removeSlide(int slideId)
{
    pres->removeSlide(--slideId);
}

void Controller::openNextSlide()
{
    pres->nextSlide();
}

void Controller::openPrevSlide()
{
    pres->prevSlide();
}
