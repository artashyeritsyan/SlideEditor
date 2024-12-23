#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <iostream>
#include <vector>

#include "Item.hpp"

class Slide {
public:
    Slide();
    // int getItemsCount();
    
    // Print all items in slide, ordering by their LayerOrder 
    std::vector<std::shared_ptr<Item>>& getAllItems();

    void addItem(ItemTypeEnum type, std::pair<double, double> position, double width, double height, const std::string& text);
    void addItem(std::shared_ptr<Item> item);

    void removeItem(int id);
    void renameItem(size_t id, const std::string& newName);
    void renameItem(const std::string& name, const std::string& newName);
    void moveItem(size_t id, std::pair<double, double> newPosition);
    void changeItemSize(size_t id, std::pair<double, double> newSize);
    void setText(size_t id, const std::string& text);
    
    std::vector<std::shared_ptr<Item>>& getItemList();

    void bringItemForward(size_t id);
    void sendItemBackward(size_t id);
    void bringItemToFront(size_t id);
    void sendItemToBack(size_t id);

private:
    bool nameRepeatingCheck(std::string name); 
    size_t findMaxOrder();
    void orderByLayer();
    std::vector<std::shared_ptr<Item>>::iterator getItemById(size_t id);
    std::vector<std::shared_ptr<Item>>::iterator getItemByName(const std::string &name);


    size_t nextId = 1;
    std::vector<std::shared_ptr<Item>> _items;
};

#endif // SLIDE_HPP