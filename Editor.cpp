#include "Editor.hpp"

void Editor::removeSlide(int slideId)
{
}

void Editor::addSlide(int slideId)
{
    std::unique_ptr<Slide> slide = std::make_unique<Slide>();
    if(slideId == 0) {
        _presentation.addSlide(_presentation.slidesCount(), std::move(slide));
    }
    else {
        _presentation.addSlide(--slideId, std::move(slide));
    }
}

void Editor::removeSlide(int slideId)
{
    if(slideId == 0) {
        _presentation.removeSlide(_presentation.slidesCount() - 1);
    }
    else {
        _presentation.removeSlide(--slideId);
    }
}