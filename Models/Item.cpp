#include "Item.hpp"

Item::Item(ItemTypeEnum type, int layerOrder, size_t id, std::pair<int, int> position = {0, 0}, int _width = 10, int _height = 10)
    : _type(type), _layerOrder(layerOrder), _position(position), id(id), _width(_width), _height(_height) {
    generateName();
}

// Item::Item(ItemTypeEnum type, int layerOrder, int x = 0, int y = 0, int _width = 10, int _height = 10, size_t id)
//     : _type(type), _layerOrder(layerOrder), _position({x, y}), id(id), _width(_width), _height(_height) {
//     generateName();
// }

Item::Item(size_t id) : id(id) {
    generateName();
}

size_t Item::getId() const {
    return id;
}

std::string Item::getName() const {
    return _name;
}

ItemTypeEnum Item::getType() const {
    return _type;
}

std::pair<double, double> Item::getPosition() const {
    return _position;
}

double Item::getX() const {
    return _position.first;
}

double Item::getY() const {
    return _position.second;
}

size_t Item::getLayer() const {
    return _layerOrder;
}

int Item::getWidth() const {
    return _width;
}

int Item::getHeight() const {
    return _height;
}

void Item::setName(const std::string& newName) {
    _name = newName;
}

void Item::setType(ItemTypeEnum newType) {
    _type = newType;
}

void Item::setPosition(std::pair<int, int> newPosition) {
    _position = newPosition;
}

void Item::setPosition(int x, int y) {
    _position = {x, y};
}

void Item::setLayer(size_t newLayerOrder) {
    _layerOrder = newLayerOrder;
}

void Item::setWidth(int newWidth) {
    _width = newWidth;
}

void Item::setHeight(int newHeight) {
    _height = newHeight;
}

void Item::setTextContent(const std::string &content)
{
    _text->setContent(content);
}

void Item::setText(std::shared_ptr<Text> text)
{
    _text = text;
}

void Item::generateName() {
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


