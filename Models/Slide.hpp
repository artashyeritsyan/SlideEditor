#pragma once

#include <iostream>
#include <vector>

#include "Item.hpp"

class Slide {
public:
    Slide();
    ~Slide() {}

    // int getItemsCount();
    
    // Print all items in slide, ordering bay their LayerOrder 
    std::vector<std::unique_ptr<Item>>& getAllItems();

    void addItem(ItemTypeEnum type, std::pair<int, int> position = {0, 0}, std::string name = "");

    /// TODO: Change the logic for index, add Id to every item and use itemId for finding item in vector
    void removeItem(int itemIndex);
    void removeItem(const std::string& name);
    void renameItem(int itemIndex, const std::string& newName);
    void changePosition(int itemIndex);

    void renameItem(const std::string& name, const std::string& newName);

private:
    // int pageNumber;
    std::vector<std::unique_ptr<Item>> _items;

    void nameRepeatingCheck(std::string name); 
    size_t findMaxOrder();
};