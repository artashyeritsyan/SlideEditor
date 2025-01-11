#ifndef PRESENTATION_HPP
#define PRESENTATION_HPP

#include "Slide.hpp"
#include "Item.hpp"

class Presentation {
public:
    Presentation() = default;
    Presentation(const std::string& name, const std::vector<std::shared_ptr<Slide>> slides)
        : _name(name), _slides(slides) {}


    int getSlidesCount();
    const std::shared_ptr<Slide>& getSlideByIndex(int index);
    std::vector<std::shared_ptr<Slide>>& getSlides();
    
    int getCurrentSlideIndex();
    void setCurrentSlideIndex(int index);

    std::string getName() const;
    void setName(const std::string& value);

    void addSlide(std::shared_ptr<Slide> slide);
    void nextSlide();
    void prevSlide();
    void copySlide(int slideId, int copiedSlideId);


    void serialize(const std::string& filename) const;
    static std::shared_ptr<Presentation> deserialize(const std::string& filename);

private:
    std::string _name;
    std::vector<std::shared_ptr<Slide>> _slides;
    int _currentSlideIndex = 0;
};


#endif // PRESENTATION_HPP