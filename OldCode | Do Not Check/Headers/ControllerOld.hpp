#pragma once

#include "Presentation.hpp"
#include "ShapeTypeEnum.hpp"
#include "RGB.hpp"

class ControllerOld {
public:
    ControllerOld () {
        pres = new Presentation;
    }
    ~ControllerOld () {
        delete pres;
    }

    // File
    void newFile();
    void openFile(std::string path);
    void closeFile();
    void saveFile();
    void saveFileAs(const std::string& name, const std::string& path);
    void fileHelp(); // Print commands for file


    // Slide 
    void addSlide(int slideId = 0);
    void removeSlide(int slideId);
    void openNextSlide();
    void openPrevSlide();
    void openSlideById(int slideId);
    void moveSlide(int slideId, int newPosition);
    std::vector<Slide> slidesList(); //print or just return vector of slides
    void copySlide(int slideId, int newSlidePosition);
    void slideHelp(); // Print commands for slide


    // Items
    void addShape(ShapeTypeEnum type = ShapeTypeEnum::Rectangle, std::pair<int, int> position = {0, 0}, int widht, int height);
    void addText(std::string content = "", std::pair<int, int> position = {0, 0}, int widht, int height);
    void addImage(std::string imagePath, std::pair<int, int> position = {0, 0}, int widht, int height);
    void removeItem(int index);
    void removeItem(std::string name);
    void renameItem(std::string name, std::string newName);
    void moveItem(int index, std::pair<int, int> newPosition);
    void moveItem(std::string name, std::pair<int, int> newPosition);
    void editText(int index, std::string newText); // Check the type if it already text or image or etc.
    void changeColor (int itemIndex, RGB newColor);
    void changeBackGroundColor (int itemIndex, RGB newColor);
    void changeOutlineColor (int itemIndex, RGB newColor);
    void changeHightlightColor (int itemIndex, RGB newColor);
    // void rotate item(int itemIndex, rotation);
    std::vector<Item> itemsList();
    void itemInfo(int itemIndex); // print all information about this item;

private:
    Presentation *pres;

};