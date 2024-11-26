#include "Presentation.hpp"

// void Presentation::addSlide(int index, std::shared_ptr<Slide> slide)
// {
//     if (index == _slides.size()) {
//         _slides.push_back(slide);
//     }
//     _slides.insert(_slides.begin() + index, slide);
// }

// void Presentation::removeSlide(int slideIndex) {
//     if (slideIndex < _slides.size() && slideIndex > 0) {
//         _slides.erase(_slides.begin() + (slideIndex - 1));
//     }
//     else {
//         throw CLIException("index out of range");
//     }
// }

int Presentation::getSlidesSize() {
    return _slides.size();
}


std::string Presentation::getName() const
{
    return _name;
}

const std::shared_ptr<Slide>& Presentation::getSlideByIndex(size_t index) {
    return _slides[index];
}

// const std::vector<std::unique_ptr<Slide>> &Presentation::getSlides() const
// {
//     return _slides;
// }

std::vector<std::shared_ptr<Slide>>& Presentation::getSlides() {
    return _slides;
}

void Presentation::nextSlide()
{
    if (_currentSlideIndex < _slides.size() - 2) {
        ++_currentSlideIndex;
    }
}

void Presentation::prevSlide()
{
    if (_currentSlideIndex > 0) {
        --_currentSlideIndex;
    }
}

size_t Presentation::getCurrentSlideIndex()
{
    return _currentSlideIndex;
}
