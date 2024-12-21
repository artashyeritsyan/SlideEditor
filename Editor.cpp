#include "Editor.hpp"

void Editor::openNextSlide()
{
    _presentation->nextSlide();
}
     
void Editor::openPrevSlide()
{
    _presentation->prevSlide();
}

void Editor::addSlide(int slideId)
{
    std::shared_ptr<Slide> slide = std::make_unique<Slide>();
    int slideIndex = slideId - 1;

    auto& slides = _presentation->getSlides();
    if(slideId == -1 || slideIndex == slides.size()) {
        slides.push_back(slide);
    }
    else {
        if (slideIndex < slides.size() && slideIndex >= 0) {
            slides.insert(slides.begin() + slideIndex, slide);
        } 
        else {
            throw CLIException("Id is out of range"); 
        }
    }

}

void Editor::removeSlide(int slideId)
{
    auto& slides = _presentation->getSlides();
    int slideIndex = slideId - 1;

    if(slideId == -1) {
        slides.pop_back();
    }
    else {
        if (slideIndex < slides.size() && slideIndex >= 0 && slides.size() > 0) {
            slides.erase(slides.begin() + slideIndex); 
        }
        else {
            throw CLIException("Id is out of range");
        }
    }
    
}

void Editor::moveSlide(size_t slideId, size_t newId)
{
    size_t firstIndex = slideId - 1;
    size_t secondIndex = newId - 1;
    auto& slides = _presentation->getSlides();

    if (firstIndex >= 0 && firstIndex < slides.size() && secondIndex >= 0 && secondIndex < slides.size()) {
        std::swap(slides[firstIndex], slides[secondIndex]);
    } else {
        throw CLIException("index out of range");
    }

}

// std::vector<Item> Editor::itemsList()
// {
//     return std::vector<Item>();
// }

void Editor::printSlides() {
    size_t slideIndex = 1;
    
    const auto& slides = _presentation->getSlides();
    for (const auto& slidePtr : slides) {
        if (slidePtr) {
            std::cout << "Slide " << slideIndex 
                        << ": Items count = " << slidePtr->getAllItems().size()
                        << std::endl;
        }
        ++slideIndex;
    }
}

void Editor::printItems()
{
    const auto &slide = _presentation->getSlideByIndex(_presentation->getCurrentSlideIndex());

    for (const auto& item : slide->getAllItems()) {
        auto pos = item->getPosition();
        std::cout << "ID: " << item->getId()
                    << ",  Name: " << item->getName() 
                    << ",  X: " << pos.first
                    << ",  Y: " << pos.second
                    << ",  W: " << item->getWidth()
                    << ",  H: " << item->getHeight()
                    << std::endl;
    }
}

void Editor::addItem(ItemTypeEnum type, std::pair<double, double> position,
                std::pair<double, double> size, const std::string& content) {

    auto& slide = _presentation->getSlideByIndex(_presentation->getCurrentSlideIndex());
    slide->addItem(type, position, size.first, size.second, content);
}

void Editor::removeItem(int id)
{
    auto& slide = _presentation->getSlideByIndex(_presentation->getCurrentSlideIndex());
    slide->removeItem(id);
}
