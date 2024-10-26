#pragma once

#include "Item.hpp"
#include "RGB.hpp"

class Shape : public Item {
public:

    Shape(const std::string& name, 
          ItemTypeEnum type, 
          int layerOrder, 
          const std::pair<int, int>& position)
        : Item(name, type, layerOrder, position) {}
    
    
    RGB getColor() const;
    RGB getOutlineColor() const;

    void setColor(RGB& value);
    void setOutlineColor(RGB& value);

private:

    RGB color;          //
    RGB outlineColor;   //
    //int outlineWeight;
};