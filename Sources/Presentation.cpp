#include "Presentation.hpp"

class Presentation {
public:

    static Presentation fromJSON(const json& jsonData) {
        std::string name = jsonData.at("name").get<std::string>();
        std::string createDate = jsonData.at("createDate").get<std::string>();
        std::string changedDate = jsonData.at("changedDate").get<std::string>();

        std::vector<Slide> slides;
        for (const auto& slideData : jsonData.at("slides")) {
            int pageNumber = slideData.at("pageNumber").get<int>();

            // Parse the items in each slide
            std::vector<Item> items;
            for (const auto& itemData : slideData.at("items")) {
                std::string itemName = itemData.at("name").get<std::string>();
                ItemTypeEnum itemType = stringToItemTypeEnum(itemData.at("type").get<std::string>());
                int layerOrder = itemData.at("layerOrder").get<int>();
                std::pair<int, int> position = {itemData.at("position").at(0).get<int>(), itemData.at("position").at(1).get<int>()};
                items.emplace_back(itemName, itemType, layerOrder, position);
            }

            slides.emplace_back(pageNumber, items);
        }

        return Presentation(name, createDate, changedDate, slides);
    }

};