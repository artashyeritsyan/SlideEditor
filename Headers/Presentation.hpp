#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "Slide.hpp"

using json = nlohmann::json;

class Presentation {
public:
    Presentation();
    Presentation(const std::string& name, const std::vector<Slide>& slides)
        : name(name), slides(slides) {}

    
    static Presentation fromJSON(const json& jsonData);

    // Command functions
    // TODO: Write an implementation for this functions 
    void addSlide(int index = NULL);
    void removeSlide(int slideId);
    void nextSlide();
    void prevSlide();
    void slideById(int slideId);
    void moveSlide(int slideId, int newPosition);
    std::vector<Slide> allSlides() const;
    void copySlide(int slideId, int copiedSlideId);

    std::string getName() const;
    void setName(const std::string& value);

private:
    std::string name;
    std::vector<Slide> slides;
    int currentSlideIndex = 0;
};