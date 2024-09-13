#include <iostream>

#include "FileManager.hpp"

// FileManager* FileManager::instance = nullptr;
// std::mutex FileManager::mutex_;

int main() {
    FileManager* fileManager = FileManager::getInstance();
    // fileManager->saveFile();
    fileManager->loadFile();

    return 0;
}
