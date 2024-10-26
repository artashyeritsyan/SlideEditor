#include "Presentation.hpp"

void Presentation::addSlide(int index, std::unique_ptr<Slide> slide)
{
    if (index == slides.size()) {
        slides.push_back(slide);
    }
    slides.insert(slides.begin() + index, slide);
}

void Presentation::removeSlide(int slideIndex) {
    if (slideIndex < slides.size() && slideIndex > 0) {
        slides.erase(slides.begin() + (slideIndex - 1));
    }
    else {
        /// TODO: throw an excpetion
        std::cerr << "index out of range" << std::endl;
    }
}