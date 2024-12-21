#include "Item.hpp"

size_t Item::nextId = 1;

Item::Item(ItemTypeEnum type, int layerOrder, const std::pair<int, int>& position)
    : _type(type), _layerOrder(layerOrder), _position(position), id(nextId++) {
    generateName();
}

Item::Item(ItemTypeEnum type, int layerOrder, int x, int y) 
    : _type(type), _layerOrder(layerOrder), _position(std::pair(x, y)), id(nextId++) {
    generateName();
}

Item::Item() : id(nextId++) {
    generateName();
}

void Item::generateName()
{
    switch (_type) {
        case ItemTypeEnum::Rectangle:
            _name = "Rect_" + std::to_string(id);
            break;
        case ItemTypeEnum::Triangle:
            _name = "Triangle_" + std::to_string(id);
            break;
        case ItemTypeEnum::Circle:
            _name = "Circle_" + std::to_string(id);
            break;
        case ItemTypeEnum::Line:
            _name = "Line_" + std::to_string(id);
            break;
        default:
            _name = "Unknown_" + std::to_string(id);
            break;
    }
}
