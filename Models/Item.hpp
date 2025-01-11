#ifndef ITEM_HPP
#define ITEM_HPP

#include <fstream>
#include <string>
#include <memory>

#include "../Enums/ItemTypeEnum.hpp"
#include "../CLI/CLIException.hpp"
#include "Text.hpp"

class Item {
public:
    Item();
    Item (ItemTypeEnum type, int layerOrder, int id, std::pair<int, int> position, int _width, int _height);
    // Item(ItemTypeEnum type, int layerOrder, int x, int y, int _width, int _height, int id);
    Item(int id);

    int getId() const;
    std::string getName() const;
    ItemTypeEnum getType() const;
    std::pair<double, double> getPosition() const;
    double getX() const;
    double getY() const;
    int getLayer() const;
    int getWidth() const;
    int getHeight() const;
    bool hasText() const;
    std::string getTextContent() const;

    void setName(const std::string& newName);
    void setType(ItemTypeEnum newType);
    void setPosition(std::pair<int, int> newPosition);
    void setPosition(int x, int y);
    void setLayer(int newLayerOrder);
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setTextContent(const std::string& content);
    void setText(std::shared_ptr<Text> text);

    void serialize(std::ofstream& file) const;
    static std::shared_ptr<Item> deserialize(std::ifstream& file);

private:
    void generateName();

    int id;
    std::string _name;
    ItemTypeEnum _type = ItemTypeEnum::Rectangle;
    std::pair<double, double> _position;
    int _width;
    int _height;
    int _layerOrder;

    std::shared_ptr<Text> _text = nullptr;

};

#endif // ITEM_HPP