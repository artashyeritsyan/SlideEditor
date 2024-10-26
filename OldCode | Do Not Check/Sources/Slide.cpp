#include "Slide.hpp"
#include "Item.hpp"
// #include "Text.hpp"
// #include "Shape.hpp"
// #include "Image.hpp"

void Slide::addItem(ItemTypeEnum type = ItemTypeEnum::text, std::pair<int, int> position = {0, 0}, std::string name = "")
{
    if (name == "") {
        name = std::to_string(type) + std::to_string(items.size());
    }

    int layerOrder = findMaxOrder() + 1;
    Item newItem(name, type, layerOrder, position);
    items.push_back(newItem);

    //I think i need to write this function using just Item class without Shape, Text and Image classes
    // switch (type): {
    //     case ItemTypeEnum::text:
    //         Text textBox(name, type, layerOrder, position);
    //         items.push_back(dynamic_cast<Item*>(&textBox));
    //         break;

    //     case ItemTypeEnum::shape:
    //         Shape shape(name, type, layerOrder, position);
    //         items.push_back(dynamic_cast<Item*>(&shape));
    //         break;

    //     case ItemTypeEnum::image:
    //         Image picture(name, type, layerOrder, position);
    //         items.push_back(dynamic_cast<Item*>(&picture));
    //         break;
    // }

}

size_t Slide::findMaxOrder()
{
    size_t max = 0;
    for (size_t i = 0; i < items.size(); ++i) {
        if (i > max) {
            max = i;
        }
    }

    return max;
}
