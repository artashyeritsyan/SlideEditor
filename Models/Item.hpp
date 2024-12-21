#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <memory>

#include "../Enums/ItemTypeEnum.hpp"
#include "../CLI/CLIException.hpp"
#include "Text.hpp"

class Item {
public:
    Item (ItemTypeEnum type, int layerOrder, const std::pair<int, int>& position);
    Item(ItemTypeEnum type, int layerOrder, int x, int y);
    Item();

    size_t getId() const { return id; }
    std::string getName() const { return _name; }
    ItemTypeEnum getType() const { return _type; }
    std::pair<double, double> getPosition() const { return _position; }
    double getX() const { return _position.first; }
    double getY() const { return _position.second; }
    size_t getLayer() const { return _layerOrder; }
    int getWidth() const { return _width; }
    int getHeight() const { return _height; }

    void setName(const std::string& newName) { _name = newName; }
    void setType(ItemTypeEnum newType) { _type = newType; }
    void setPosition(std::pair<int, int> newPosition) { _position = newPosition; }
    void setPosition(int x, int y) { _position = {x, y}; }
    void setLayer(size_t newLayerOrder) { _layerOrder = newLayerOrder; }
    void setWidth(int newWidth) { _width = newWidth; }
    void setHeight(int newHeight) { _height = newHeight; }

private:
    void generateName();

    static size_t nextId;
    size_t id;
    std::string _name;
    ItemTypeEnum _type = ItemTypeEnum::Rectangle;
    size_t _layerOrder;
    std::pair<double, double> _position = {0, 0};
    int _width = 10;
    int _height = 10;

    std::shared_ptr<Text> _text = nullptr;

};

#endif // ITEM_HPP