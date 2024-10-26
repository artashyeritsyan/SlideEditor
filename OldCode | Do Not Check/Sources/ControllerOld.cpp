#include "ControllerOld.hpp"

void ControllerOld::addSlide(int slideId = 0)
{
    if(slideId == 0) {
        pres->addSlide(pres->slidesCount());
    }
    else {
        pres->addSlide(--slideId);
    }
}

void ControllerOld::removeSlide(int slideId)
{
    pres->removeSlide(--slideId);
}

void ControllerOld::openNextSlide()
{
    pres->nextSlide();
}

void ControllerOld::openPrevSlide()
{
    pres->prevSlide();
}
