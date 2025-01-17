#include "Serialization.hpp"
#include "../Models/Presentation.hpp"
#include <fstream>
#include <iostream>

void Serialization::serialize(const std::string &path)
{
    std::ofstream file(path, std::ios::out | std::ios::binary);
    if (!file.is_open()) {
        throw CLIException("Can't open file");
    }

    serializePresentation(file);

    file.close();

    /// TODO: move print part to View
    std::cout << "Presentation saved successfully." << std::endl;
}

void Serialization::serializePresentation(std::ofstream& file)
{
    auto slides = Application::getInstance().getPresentation()->getSlides();

    size_t slideCount = slides.size();
    file.write(reinterpret_cast<const char*>(&slideCount), sizeof(slideCount));

    for (const auto& slide : slides) {
        serializeSlide(file, slide);
    }

}

void Serialization::serializeSlide(std::ofstream &file, std::shared_ptr<Slide> slide)
{
    const auto& items = slide->getItemList();
    size_t itemCount = items.size();
    int nextId = slide->getNextId();

    file.write(reinterpret_cast<const char*>(&itemCount), sizeof(itemCount));
    file.write(reinterpret_cast<const char*>(&nextId), sizeof(nextId));

    for (const auto& item : items) {
        serializeItem(file, item);
    }
}

void Serialization::serializeItem(std::ofstream &file, std::shared_ptr<Item> item)
{
    int id = item->getId();
    size_t nameLength = item->getName().size();
    std::pair<double, double> position = item->getPosition();
    ItemTypeEnum type = item->getType();
    double width = item->getWidth();
    double height = item->getHeight();
    int layer = item->getLayer();
    
    file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    file.write(item->getName().c_str(), nameLength);
    file.write(reinterpret_cast<const char*>(&id), sizeof(id));
    file.write(reinterpret_cast<const char*>(&type), sizeof(type));
    file.write(reinterpret_cast<const char*>(&position), sizeof(position));
    file.write(reinterpret_cast<const char*>(&width), sizeof(width));
    file.write(reinterpret_cast<const char*>(&height), sizeof(height));
    file.write(reinterpret_cast<const char*>(&layer), sizeof(layer));

    std::string textContent = item->getTextContent();
    if(textContent.empty()) {
        size_t textLength = 0;
        file.write(reinterpret_cast<const char*>(&textLength), sizeof(textLength));
        return;
    }

    size_t textLength = textContent.size();
    file.write(reinterpret_cast<const char*>(&textLength), sizeof(textLength));
    file.write(textContent.c_str(), textLength);
}

void Serialization::deserialize(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Failed to open file for reading.");
    }

    const auto& pres = deserializePresentation(file);
    Application::getInstance().getPresentation() = pres;
        file.close();
    
    /// TODO: move print part to View
    std::cout << "Presentation loaded successfully." << std::endl;
}

std::shared_ptr<Presentation> Serialization::deserializePresentation(std::ifstream &file)
{
    std::shared_ptr<Presentation> presentation = std::make_shared<Presentation>();
    size_t slideCount;
    file.read(reinterpret_cast<char*>(&slideCount), sizeof(slideCount));

    for (size_t i = 0; i < slideCount; ++i) {
        auto slide = deserializeSlide(file);
        presentation->addSlide(slide);
    }

    return presentation;
}

std::shared_ptr<Slide> Serialization::deserializeSlide(std::ifstream &file)
{
    size_t itemCount;
    int nextId;
    file.read(reinterpret_cast<char*>(&itemCount), sizeof(itemCount));
    file.read(reinterpret_cast<char*>(&nextId), sizeof(nextId));

    auto slide = std::make_shared<Slide>(nextId);

    for (size_t i = 0; i < itemCount; ++i) {
        auto item = deserializeItem(file);
        slide->addItem(item);
    }

    return slide;
}

std::shared_ptr<Item> Serialization::deserializeItem(std::ifstream &file)
{
    size_t nameLength;
    file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    std::string name(nameLength, '\0');
    int id;
    int width;
    int height;
    int layerOrder;
    ItemTypeEnum type;
    std::pair<double, double> position;

    file.read(&name[0], nameLength);
    file.read(reinterpret_cast<char*>(&id), sizeof(id));
    file.read(reinterpret_cast<char*>(&type), sizeof(type));
    file.read(reinterpret_cast<char*>(&position), sizeof(position));
    file.read(reinterpret_cast<char*>(&width), sizeof(width));
    file.read(reinterpret_cast<char*>(&height), sizeof(height));
    file.read(reinterpret_cast<char*>(&layerOrder), sizeof(layerOrder));
    
    size_t textLength;
    file.read(reinterpret_cast<char*>(&textLength), sizeof(textLength));

    auto item = std::make_shared<Item>(id);
    item->setName(name);
    item->setType(type);
    item->setPosition(position);
    item->setWidth(width);
    item->setHeight(height);

    item->setLayer(layerOrder);
    if (textLength != 0) {
        std::string textContent;
        textContent.resize(textLength);
        file.read(&textContent[0], textLength);
        item->setTextContent(textContent);
    }
    
    return item;
}




