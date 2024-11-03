#ifndef PRESENTATION_HPP
#define PRESENTATION_HPP

#include "Slide.hpp"
#include "Item.hpp"

class Presentation {
public:
    Presentation();
    Presentation(const std::string& name, const std::vector<std::shared_ptr<Slide>> slides)
        : _name(name), _slides(slides) {}


    // Command functions
    /// TODO: Write an implementation for this functions 

    void addSlide(int index, std::shared_ptr<Slide> slide);

    int getSlidesSize();
    const std::shared_ptr<Slide>& getSlideByIndex(int index);
    const std::vector<std::shared_ptr<Slide>>& getAllSlides() const;
    void removeSlide(int index);
    // void nextSlide();
    // void prevSlide();
    void moveSlide(int slideId, int newPosition);
    void copySlide(int slideId, int copiedSlideId);

    std::string getName() const;
    void setName(const std::string& value);
    int getCurrentSlideIndex();

private:
    std::string _name;
    std::vector<std::shared_ptr<Slide>> _slides;
    // int currentSlideIndex = 0;
};


#endif // PRESENTATION_HPP