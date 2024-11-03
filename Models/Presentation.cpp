#include "Presentation.hpp"

void Presentation::addSlide(int index, std::shared_ptr<Slide> slide) {
    if (index == _slides.size()) {
        _slides.push_back(slide);
    }
    _slides.insert(_slides.begin() + index, slide);
}

int Presentation::getSlidesSize() {
    return _slides.size();
}

void Presentation::removeSlide(int slideIndex) {
    if (slideIndex < _slides.size() && slideIndex > 0) {
        _slides.erase(_slides.begin() + (slideIndex - 1));
    }
    else {
        /// TODO: throw an excpetion
        std::cerr << "index out of range" << std::endl;
    }
}

std::string Presentation::getName() const
{
    return _name;
}

const std::shared_ptr<Slide>& Presentation::getSlideByIndex(int index) {
    return _slides[index].get();
}

// const std::vector<std::unique_ptr<Slide>> &Presentation::getAllSlides() const
// {
//     return _slides;
// }

 const std::vector<std::shared_ptr<Slide>>& Presentation::getAllSlides() const {
        return _slides;
    }
