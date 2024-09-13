#pragma once
#include <vector>
#include <string>

#include "Slide.hpp"

using json = nlohmann::json;

class Presentation {
public:
    Presentation();
    Presentation(const std::string& name, const std::string& createDate, const std::string& changedDate, const std::vector<Slide>& slides)
        : name(name), createDate(createDate), changedDate(changedDate), slides(slides) {}

    
    static Presentation fromJSON(const json& jsonData);

    std::string getName() const;
    std::string getCreateDate() const;
    std::string getChangedDate() const; 
    std::vector<Slide> getSlides() const;

    void setName(const std::string& value);
    void setCreateDate(const std::string& value);
    void setChangedDate(const std::string& value);
    void setSlides(const std::vector<Slide>& value);



private:
    std::string name;
    std::string createDate;
    std::string changedDate;
    std::vector<Slide> slides;
};