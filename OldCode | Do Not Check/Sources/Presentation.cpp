#include "Presentation.hpp"

// class Presentation {
// public:

//     static Presentation fromJSON(const json& jsonData) {
//         std::string name = jsonData.at("name").get<std::string>();
//         std::string createDate = jsonData.at("createDate").get<std::string>();
//         std::string changedDate = jsonData.at("changedDate").get<std::string>();

//         std::vector<Slide> slides;
//         for (const auto& slideData : jsonData.at("slides")) {
//             int pageNumber = slideData.at("pageNumber").get<int>();

//             // Parse the items in each slide
//             std::vector<Item> items;
//             for (const auto& itemData : slideData.at("items")) {
//                 std::string itemName = itemData.at("name").get<std::string>();
//                 ItemTypeEnum itemType = stringToItemTypeEnum(itemData.at("type").get<std::string>());
//                 int layerOrder = itemData.at("layerOrder").get<int>();
//                 std::pair<int, int> position = {itemData.at("position").at(0).get<int>(), itemData.at("position").at(1).get<int>()};
//                 items.emplace_back(itemName, itemType, layerOrder, position);
//             }

//             slides.emplace_back(pageNumber, items);
//         }

//         return Presentation(name, createDate, changedDate, slides);
//     }


// };

int Presentation::slidesCount()
{
    slides.size();
}

void Presentation::addSlide(int index)
{
    Slide newSlide;
    slides.insert(slides.begin() + index, newSlide);
}

void Presentation::removeSlide(int slideId) {
    slides.erase(slides.begin() + (slideId - 1));
}

void Presentation::nextSlide()
{
    if (currentSlideIndex < slides.size() - 1) {
        ++currentSlideIndex;
    }
}

void Presentation::prevSlide()
{
    if (currentSlideIndex > 0) {
        --currentSlideIndex;
    }
}

void Presentation::slideById(int slideId)
{
    if (slideId < slides.size() + 1 && slideId > 0) {
        currentSlideIndex = slideId - 1;
    }
}

void Presentation::moveSlide(int slideId, int newPosition)
{
    slideId--;
    newPosition--;

    if (slideId < 0 || slideId >= slides.size() || newPosition < 0 || newPosition >= slides.size()) {
        std::cerr << "Invalid Slide Id or slide new Position!" << std::endl;
        return;
    }

    Slide tempSlide = slides[slideId];
    slides.erase(slides.begin() + slideId);
    slides.insert(slides.begin() + newPosition, tempSlide);
}

std::vector<Slide> Presentation::allSlides() const
{
    return slides;
}

void Presentation::copySlide(int slideId, int copiedSlideId)
{
    slideId--;
    copiedSlideId--;

    if (slideId < 0 || slideId >= slides.size() || copiedSlideId < 0 || copiedSlideId >= slides.size()) {
        std::cerr << "Invalid Slide Id or new Slide Position!" << std::endl;
        return;
    }

    Slide tempSlide = slides[slideId];
    slides.insert(slides.begin() + copiedSlideId, tempSlide);
}

std::string Presentation::getName() const
{
    return name;
}

void Presentation::setName(const std::string &value)
{
    name = value;
}

int Presentation::getCurrentSlideIndex()
{
    return currentSlideIndex;
}
