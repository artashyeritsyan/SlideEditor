#pragma once

#include <vector>

#include "Item.hpp"

class Slide {
public:
    int pageNumber;
    std::vector<Item> items;
    
    int getItemsCount();
    
    // Print all items in slide, ordering bay their LayerOrder 
    std::vector<Item> getAllItems();
    void renameItem(int index);
    void renameItem(std::string name);
    

};