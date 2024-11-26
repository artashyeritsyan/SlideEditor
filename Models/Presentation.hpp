#ifndef PRESENTATION_HPP
#define PRESENTATION_HPP

#include "Slide.hpp"
#include "Item.hpp"

class Presentation {
public:
    Presentation() = default;
    Presentation(const std::string& name, const std::vector<std::shared_ptr<Slide>> slides)
        : _name(name), _slides(slides) {}


    // Command functions
    /// TODO: Write an implementation for this functions 

    // void addSlide(int index, std::shared_ptr<Slide> slide);
    // void removeSlide(int index);
    // void moveSlide(int slideId, int newPosition);

    int getSlidesSize();
    const std::shared_ptr<Slide>& getSlideByIndex(size_t index);
    std::vector<std::shared_ptr<Slide>>& getSlides();
    void nextSlide();
    void prevSlide();
    size_t getCurrentSlideIndex();
    void copySlide(int slideId, int copiedSlideId);

    std::string getName() const;
    void setName(const std::string& value);

private:
    std::string _name;
    std::vector<std::shared_ptr<Slide>> _slides;
    size_t _currentSlideIndex = 0;
};


#endif // PRESENTATION_HPP