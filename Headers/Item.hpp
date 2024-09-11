#pragma once

#include <string>

#include "ItemTypeEnum.hpp"

class Item {
public:

    std::string getName() const;
    ItemTypeEnum getType() const;
    int getLayer() const;
    std::pair<int, int> getPosition() const;

    void setName(const std::string&);
    void setType(ItemTypeEnum type) {this->type = type;}
    void setLayer(int layerOrder);
    void setPosition(std::pair<int, int>);
    void setPosition(int x, int y);

    void bringForward();
    void sendBackward();
    
    // Set maximal order for item
    void bringToFront();
    // Set minimal order for item
    void sendToBack();


private:
    std::string name;
    ItemTypeEnum type;
    int layerOrder;
    std::pair<int, int> position;
    

};