#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <iostream>
#include <vector>

#include "Item.hpp"

class Slide {
public:
    // int getItemsCount();
    
    // Print all items in slide, ordering by their LayerOrder 
    std::vector<std::shared_ptr<Item>>& getAllItems();

    void addItem(ItemTypeEnum type, std::pair<int, int> position);

    /// TODO: Change the logic for index, add Id to every item and use itemId for finding item in vector
    void removeItem(int itemIndex);
    void removeItem(const std::string& name);
    void renameItem(int itemIndex, const std::string& newName);
    void changePosition(int itemIndex);
    void renameItem(const std::string& name, const std::string& newName);

    void bringItemForward(size_t id);
    void sendItemBackward(size_t id);
    void bringItemToFront(size_t id);
    void sendItemToBack(size_t id);

private:
    void nameRepeatingCheck(std::string name); 
    size_t findMaxOrder();
    void orderByLayer();
    std::vector<std::shared_ptr<Item>>::iterator getItemById(size_t id);


    std::vector<std::shared_ptr<Item>> _items;
};

#endif // SLIDE_HPP