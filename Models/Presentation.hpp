#ifndef PRESENTATION_HPP
#define PRESENTATION_HPP

#include "Slide.hpp"
#include "Item.hpp"

class Presentation {
public:
    Presentation() = default;
    Presentation(const std::string& name, const std::vector<std::shared_ptr<Slide>> slides)
        : _name(name), _slides(slides) {}

    int getSlidesSize();
    const std::shared_ptr<Slide>& getSlideByIndex(int index);
    std::vector<std::shared_ptr<Slide>>& getSlides();
    
    int getCurrentSlideIndex();
    void setCurrentSlideIndex(int index);

    std::string getName() const;
    void setName(const std::string& value);

    void nextSlide();
    void prevSlide();
    void copySlide(int slideId, int copiedSlideId);

private:
    std::string _name;
    std::vector<std::shared_ptr<Slide>> _slides;
    int _currentSlideIndex = 0;
};


#endif // PRESENTATION_HPP