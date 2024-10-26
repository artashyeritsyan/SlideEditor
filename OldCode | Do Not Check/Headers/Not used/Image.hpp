#pragma once

#include "Item.hpp"

class Image : public Item {
public:
    Image(const std::string& name, 
          ItemTypeEnum type, 
          int layerOrder, 
          const std::pair<int, int>& position)
        : Item(name, type, layerOrder, position) {}
    
private:
};