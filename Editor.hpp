#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <memory>
#include <iostream>

#include "Models/Presentation.hpp"

class Editor {
public:
    explicit Editor(std::shared_ptr<Presentation> pres) : _presentation(pres) {}


    // Slide 
    void addSlide(int slideId = 0);
    void removeSlide(int slideId);
    void openNextSlide();
    void openPrevSlide();
    void moveSlide(size_t slideId, size_t newId);
    void openSlideById(size_t slideId);

    void addItem(ItemTypeEnum type, std::pair<double, double> position, std::pair<double, double> size, const std::string& content);
    void removeItem(int id);
    void moveItem(size_t id, std::pair<int, int> newPosition);
    void changeItemSize(size_t slideId, std::pair<int, int> newSize);

    // Print on screen
    void printSlides();
    void printItems();

    // Will be added in feature
    /*
    void removeItemByName(std::string name);
    void renameItem(std::string name, std::string newName);
    void moveItem(int index, std::pair<int, int> newPosition);
    void moveItem(std::string name, std::pair<int, int> newPosition);
    void editText(int index, std::string newText); // Check the type if it already text or image or etc.
    void changeColor (int itemIndex, RGB newColor);
    void changeBackGroundColor (int itemIndex, RGB newColor);
    void changeOutlineColor (int itemIndex, RGB newColor);
    void changeHightlightColor (int itemIndex, RGB newColor);
    void rotate item(int itemIndex, rotation);
    void itemInfo(int itemIndex); // print all information about this item;


    void newFile();
    void openFile(std::string path);
    void closeFile();
    void saveFile();
    void saveFileAs(const std::string& name, const std::string& path);
    void fileHelp(); // Print commands for file

    */

private:
    // size_t _currSlideIndex = 0;
    std::shared_ptr<Presentation> _presentation;
};

#endif // EDITOR_HPP
