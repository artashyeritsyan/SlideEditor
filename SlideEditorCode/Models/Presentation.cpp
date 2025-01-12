#include "Presentation.hpp"

void Presentation::addSlide(std::shared_ptr<Slide> slide)
{
    _slides.push_back(slide);
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
    return _slides[index];
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


void Presentation::serialize(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file for writing." << std::endl;
        return;
    }

    size_t slideCount = _slides.size();
    file.write(reinterpret_cast<const char*>(&slideCount), sizeof(slideCount));

    for (const auto& slide : _slides) {
        slide->serialize(file);
    }

    file.close();

    /// TODO: move print part to View
    std::cout << "Presentation saved successfully." << std::endl;
}

std::shared_ptr<Presentation> Presentation::deserialize(const std::string& filename) {
    std::shared_ptr<Presentation> presentation;
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file for reading." << std::endl;
        return presentation;
    }

    presentation = std::make_shared<Presentation>();
    size_t slideCount;
    file.read(reinterpret_cast<char*>(&slideCount), sizeof(slideCount));

    for (size_t i = 0; i < slideCount; ++i) {
        auto slide = Slide::deserialize(file);
        presentation->addSlide(slide);
    }

    file.close();
    
    /// TODO: move print part to View
    std::cout << "Presentation loaded successfully." << std::endl;
    return presentation;
}
