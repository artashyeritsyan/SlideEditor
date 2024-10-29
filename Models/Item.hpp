#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <memory>
#include "ItemTypeEnum.hpp"

class Item {
public:
    Item (const std::string& name, ItemTypeEnum type, int layerOrder, const std::pair<int, int>& position);
    Item() = default;

    size_t getId() const { return id; }
    std::string getName() const { return name; }
    ItemTypeEnum getType() const { return type; }
    std::pair<int, int> getPosition() const { return position; }
    size_t getLayer() const { return layerOrder; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setId(size_t newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    void setType(ItemTypeEnum newType) { type = newType; }
    void setPosition(std::pair<int, int> newPosition) { position = newPosition; }
    void setPosition(int x, int y) { position = {x, y}; }
    void setLayer(size_t newLayerOrder) { layerOrder = newLayerOrder; }
    void setWidth(int newWidth) { width = newWidth; }
    void setHeight(int newHeight) { height = newHeight; }

    void bringForward();
    void sendBackward();
    void bringToFront();
    void sendToBack();

    size_t id;
    std::string name;
    ItemTypeEnum type = Text;
    size_t layerOrder;
    std::pair<int, int> position = {0, 0};
    int width = 10;
    int height = 10;

    // Parameters for textBox
    std::string data = "";
    int textSize = 9;
    std::string font = "Arial";

    bool italic = false;
    bool bold = false; 
    bool underlined = false;

};

#endif // ITEM_HPP