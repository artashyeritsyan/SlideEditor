#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <memory>

#include "../Enums/ItemTypeEnum.hpp"
#include "../CLI/CLIException.hpp"
#include "Text.hpp"

class Item {
public:
    Item (ItemTypeEnum type, int layerOrder, size_t id, std::pair<int, int> position, int _width, int _height);
    // Item(ItemTypeEnum type, int layerOrder, int x, int y, int _width, int _height, size_t id);
    Item(size_t id);

    size_t getId() const;
    std::string getName() const;
    ItemTypeEnum getType() const;
    std::pair<double, double> getPosition() const;
    double getX() const;
    double getY() const;
    size_t getLayer() const;
    int getWidth() const;
    int getHeight() const;
    bool hasText() const;
    std::string getTextContent() const;

    void setName(const std::string& newName);
    void setType(ItemTypeEnum newType);
    void setPosition(std::pair<int, int> newPosition);
    void setPosition(int x, int y);
    void setLayer(size_t newLayerOrder);
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setTextContent(const std::string& content);
    void setText(std::shared_ptr<Text> text);

private:
    void generateName();

    size_t id;
    std::string _name;
    ItemTypeEnum _type = ItemTypeEnum::Rectangle;
    size_t _layerOrder;
    std::pair<double, double> _position;
    int _width;
    int _height;

    std::shared_ptr<Text> _text = nullptr;

};

#endif // ITEM_HPP