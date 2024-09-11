#pragma once

#include "Item.hpp"
#include "RGB.hpp"

class Shape : Item {
public:
    
private:
    int width;
    int height;

    RGB color;
    RGB outlineColor;
};