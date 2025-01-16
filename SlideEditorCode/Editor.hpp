#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <iostream>
#include <stack>
#include <memory>

#include "Models/Presentation.hpp"
#include "Actions/IAction.hpp"

class Editor {
public:
    explicit Editor(std::shared_ptr<Presentation> pres);

    // Slide 
    // void addSlide(int slideId = 0);
    // void removeSlide(int slideId);
    // void openNextSlide();
    // void openPrevSlide();
    // void moveSlide(int slideId, int newId);
    // void openSlideById(int slideId);

    // void addItem(ItemTypeEnum type, std::pair<double, double> position, std::pair<double, double> size, const std::string& content);
    // void removeItem(int id);
    // void moveItem(int id, std::pair<int, int> newPosition);
    // void changeItemSize(int id, std::pair<int, int> newSize);

    // void bringItemForward(int id);
    // void sendItemBackward(int id);
    // void bringItemToFront(int id);
    // void sendItemToBack(int id);

    void printSlides();
    void printItems();

    void saveFile(const std::string& path);
    void loadFile(const std::string& path);

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
   
   std::shared_ptr<Presentation> getPresentation() const;
   void process(std::shared_ptr<IAction> action);
   void undo();
   void redo();
    

private:
    std::shared_ptr<Slide> getCurrentSlide();

    std::shared_ptr<Presentation> _presentation;

    std::stack<std::shared_ptr<IAction>> undoStack;
    std::stack<std::shared_ptr<IAction>> redoStack;
};

#endif // EDITOR_HPP
