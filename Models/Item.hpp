#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <memory>
#include "ItemTypeEnum.hpp"

class Item {
public:
    Item (const std::string& name, ItemTypeEnum type, int layerOrder, const std::pair<int, int>& position);
    Item() = default;

    std::string getName() const;
    ItemTypeEnum getType() const;
    std::pair<int, int> getPosition() const;
    int getLayer() const;
    int getWidth() const;
    int getHeight() const;

    void setName(const std::string&);
    void setType(ItemTypeEnum type) {this->type = type;}
    void setPosition(std::pair<int, int>);
    void setPosition(int x, int y);
    void setLayer(int layerOrder);
    void setWidth(int value);
    void setHeight(int value);

    void bringForward();
    void sendBackward();
    void bringToFront();
    void sendToBack();

    std::string name;
    ItemTypeEnum type = Text;
    int layerOrder;
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