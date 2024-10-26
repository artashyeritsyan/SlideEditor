#pragma once

#include "Presentation.hpp"
#include <mutex>

class FileManager {

private:
    FileManager();

    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;

    static FileManager* instance;

    static std::mutex mutex_;

public:
    static FileManager* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance == nullptr) {
            instance = new FileManager();
        }
        return instance;
    }

    void saveFile();

    void loadFile();
};

// Initialize static members
FileManager* FileManager::instance = nullptr;
std::mutex FileManager::mutex_;
