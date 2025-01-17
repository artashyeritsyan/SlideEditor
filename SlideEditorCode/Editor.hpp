#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <iostream>
#include <stack>
#include <memory>

#include "Actions/IAction.hpp"
#include "Application/Application.hpp"

class Editor {
public:
    // explicit Editor();

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
   
//    std::shared_ptr<Presentation> getPresentation() const;
   void process(std::shared_ptr<IAction> action);
   void undo();
   void redo();
    

private:
    // void updatePresentation();

private:
    // std::shared_ptr<Presentation> _presentation;

    std::stack<std::shared_ptr<IAction>> undoStack;
    std::stack<std::shared_ptr<IAction>> redoStack;
};

#endif // EDITOR_HPP
