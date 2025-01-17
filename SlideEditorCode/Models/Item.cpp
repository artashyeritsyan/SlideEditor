#include "Item.hpp"

Item::Item() {
    generateName();
}

Item::Item(ItemTypeEnum type, int layerOrder, int id, std::pair<int, int> position = {0, 0}, int _width = 10, int _height = 10)
    : _type(type), _layerOrder(layerOrder), _position(position), id(id), _width(_width), _height(_height) {
    generateName();
}

// Item::Item(ItemTypeEnum type, int layerOrder, int x = 0, int y = 0, int _width = 10, int _height = 10, size_t id)
//     : _type(type), _layerOrder(layerOrder), _position({x, y}), id(id), _width(_width), _height(_height) {
//     generateName();
// }

Item::Item(int id) : id(id) {
    generateName();
}

int Item::getId() const {
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

int Item::getLayer() const {
    return _layerOrder;
}

int Item::getWidth() const {
    return _width;
}

int Item::getHeight() const {
    return _height;
}

std::string Item::getTextContent() const 
{
    if (_text != nullptr) {
        return _text->getContent();
    }
    return "";
}

bool Item::hasText() const
{
    return _text != nullptr;
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

void Item::setLayer(int newLayerOrder) {
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
    if (_text == nullptr) {
        _text = std::make_shared<Text>();
    }
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