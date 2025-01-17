#include "Visualization.hpp"

void Visualization::printSlides() const {
    auto presentation = Application::getInstance().getPresentation();

    int slideIndex = 0;
    
    int currentSlideIndex = presentation->getCurrentSlideIndex();
    const auto& slides = presentation->getSlides();
    if (slides.empty()) {
        throw CLIException("No slides found");
    }

    for (const auto& slidePtr : slides) {
        if (slidePtr) {
            if (currentSlideIndex == slideIndex) std::cout << ">";
            std::cout << " Slide " << slideIndex + 1 
                        << ": Items count = " << slidePtr->getItemList().size()
                        << std::endl;
        }
        ++slideIndex;
    }
}

void Visualization::printItems() const
{
    auto presentation = Application::getInstance().getPresentation();

    const auto &slide = presentation->getSlideByIndex(presentation->getCurrentSlideIndex());
    if (slide == nullptr) {
        throw CLIException("Slide is empty");
    }

    for (const auto& item : slide->getItemList()) {
        auto pos = item->getPosition();
        std::cout << "ID: " << item->getId()
                    << ", Name: " << item->getName() 
                    << ",  X: " << pos.first
                    << ",  Y: " << pos.second
                    << ",  W: " << item->getWidth()
                    << ",  H: " << item->getHeight();

        if (item->hasText()) {
            if (!item->getTextContent().empty()) {
                std::cout << ",  Text: " << '"' << item->getTextContent() << '"';
            }
        }
        std::cout << std::endl;
    }
}
