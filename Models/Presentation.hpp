#ifndef PRESENTATION_HPP
#define PRESENTATION_HPP

#include "Slide.hpp"
#include "Item.hpp"

class Presentation {
public:
    Presentation();
    Presentation(const std::string& name, const std::vector<std::unique_ptr<Slide>> slides)
        : name(name), slides(slides) {}

    // Command functions
    /// TODO: Write an implementation for this functions 

    void addSlide(int index, std::unique_ptr<Slide> slide);

    int slidesCount();
    void removeSlide(int slideId);
    void nextSlide();
    void prevSlide();
    void slideById(int slideId);
    void moveSlide(int slideId, int newPosition);
    std::vector<Slide> getAllSlides() const;
    void copySlide(int slideId, int copiedSlideId);

    std::string getName() const;
    void setName(const std::string& value);
    int getCurrentSlideIndex();

private:
    std::string name;
    std::vector<std::unique_ptr<Slide>> slides;
    int currentSlideIndex = 0;
};


#endif // PRESENTATION_HPP