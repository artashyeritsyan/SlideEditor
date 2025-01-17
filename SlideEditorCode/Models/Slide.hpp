#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <iostream>
#include <vector>

#include "Item.hpp"

class Slide {
public:
    Slide();
    Slide(int nextId);
    // int getItemsCount();
    
    // Print all items in slide, ordering by their LayerOrder 
    std::vector<std::shared_ptr<Item>>& getItemList();

    void addItem(ItemTypeEnum type, std::pair<double, double> position, double width, double height, const std::string& text);
    void addItem(std::shared_ptr<Item> item);

    void removeItem(int id);
    void renameItem(int id, const std::string& newName);
    void moveItem(int id, std::pair<double, double> newPosition);
    void changeItemSize(int id, std::pair<double, double> newSize);
    
    std::shared_ptr<Item> getItemById(int id);
    int getItemsCount();
    const int& getNextId() const;

    void bringItemForward(int id);
    void sendItemBackward(int id);
    void bringItemToFront(int id);
    void sendItemToBack(int id);

private:
    bool nameRepeatingCheck(std::string name); 
    int findMaxOrder();
    void orderByLayer();
    std::vector<std::shared_ptr<Item>>::iterator getItemIterById(int id);
    std::vector<std::shared_ptr<Item>>::iterator getItemByName(const std::string &name);


    int nextId = 1;
    std::vector<std::shared_ptr<Item>> _items;
};

#endif // SLIDE_HPP