#include "Presentation.hpp"

void Presentation::addSlide(std::shared_ptr<Slide> slide)
{
    _slides.push_back(slide);
}

void Presentation::addSlide(std::shared_ptr<Slide> slide, int index)
{
    if(index == -1 || index == _slides.size()) {
        _slides.push_back(slide);
    }
    else {
        if (index < _slides.size() && index >= 0) {
            _slides.insert(_slides.begin() + index, slide);
        } 
        else {
            throw CLIException("Id is out of range"); 
        }
    }

    _currentSlideIndex = _slides.size() - 1;
}

void Presentation::removeSlide(int index)
{
    //  auto& slides = _presentation->getSlides();
    // int index = slideId - 1;

    if(index == -1) {
        _slides.pop_back();
    }
    else {
        if (index < _slides.size() && index >= 0 && _slides.size() > 0) {
            _slides.erase(_slides.begin() + index);
        }
        else {
            throw CLIException("Id is out of range");
        }
    }

    prevSlide();
}

void Presentation::moveSlide(int oldIndex, int newIndex)
{
    if (oldIndex >= 0 && oldIndex < _slides.size() && newIndex >= 0 && newIndex < _slides.size()) {
        std::swap(_slides[oldIndex], _slides[newIndex]);
    } else {
        throw CLIException("index out of range");
    }

}

int Presentation::getSlidesCount()
{
    return _slides.size();
}

std::string Presentation::getName() const
{
    return _name;
}

const std::shared_ptr<Slide>& Presentation::getSlideByIndex(int index) {
    index = (index == -1) ? _slides.size() - 1 : index;
    return _slides[index];
}

const std::shared_ptr<Slide>& Presentation::getCurrentSlide()
{
    auto& slide = getSlideByIndex(_currentSlideIndex);
    if(slide == nullptr) {
        throw CLIException("No slide found");
    }
    return slide;
}

std::vector<std::shared_ptr<Slide>>& Presentation::getSlides() {
    return _slides;
}

void Presentation::nextSlide()
{
    if (_currentSlideIndex < _slides.size() - 1) {
        ++_currentSlideIndex;
    }
}

void Presentation::prevSlide()
{
    if (_currentSlideIndex > 0) {
        --_currentSlideIndex;
    }
}

void Presentation::addItem(ItemTypeEnum type, std::pair<double, double> position, std::pair<double, double> size, const std::string &content)
{
    auto& slide = _slides[_currentSlideIndex];
    if (slide == nullptr) {
        throw CLIException("You need to create slide first");
    }

    slide->addItem(type, position, size.first, size.second, content); 
}

void Presentation::removeItem(int id)
{
    getCurrentSlide()->removeItem(id);
}

void Presentation::moveItem(int id, std::pair<double, double> newPosition)
{
    getCurrentSlide()->moveItem(id, newPosition);
}

void Presentation::changeItemSize(int id, std::pair<int, int> newSize)
{
    getCurrentSlide()->changeItemSize(id, newSize);
}

int Presentation::getCurrentSlideIndex()
{
    return _currentSlideIndex;
}

void Presentation::setCurrentSlideIndex(int index)
{
    if (index < _slides.size() && index >= 0) {
        _currentSlideIndex = index;
    }
    _currentSlideIndex = index;
}