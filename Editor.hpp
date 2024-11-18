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
    void openSlideById(int slideId);
    void moveSlide(int slideId, int newId);
    void copySlide(int slideId, int newSlidePosition);
    // std::vector<Slide> slidesList(); //print or just return vector of slides


    // Items
    void addShape(std::shared_ptr<Item> shape);
    // void addText(std::string content = "", int x = 0, int y = 0, int widht, int height);
    // void addImage(std::string imagePath, int x = 0, int y = 0, int widht, int height);
    void removeItem(int index);
    // std::vector<Item> itemsList(int slideId);

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
    size_t currSlideIndex = 0;
    std::shared_ptr<Presentation> _presentation;
};

#endif // EDITOR_HPP
