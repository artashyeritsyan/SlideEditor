#include "Slide.hpp"

Slide::Slide() : nextId(1) {}

std::vector<std::shared_ptr<Item>> &Slide::getAllItems() {
    orderByLayer();
    return _items;
}

void Slide::addItem(ItemTypeEnum type, std::pair<double, double> position = {0, 0}, 
                    double width = 0, double height = 0, const std::string& content = "") {

    auto tmpItem = std::make_shared<Item>(type, findMaxOrder() + 1, nextId++, position, width, height);

    if (content != "") {
        tmpItem->setTextContent(content);  ///TODO :: take a ynamic 
    }
    
    _items.push_back(tmpItem);
}

void Slide::addItem(std::shared_ptr<Item> item)
{
    _items.push_back(item);
}

void Slide::removeItem(int id) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        _items.erase(it);
    }
    else {
        throw CLIException("Item with id " + std::to_string(id) + " not found");
    }
}


void Slide::renameItem(int id, const std::string &newName) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        (*it)->setName(newName);
    }
}

void Slide::moveItem(int id, std::pair<double, double> newPosition)
{
    auto it = getItemById(id);
    if (it != _items.end()) {
        (*it)->setPosition(newPosition);
    }
    else {
        throw CLIException("Item with id " + std::to_string(id) + " not found");
    }
}

void Slide::changeItemSize(int id, std::pair<double, double> newSize)
{
    auto it = getItemById(id);
    if (it != _items.end()) {
        (*it)->setWidth(newSize.first);
        (*it)->setHeight(newSize.second);
    }
    else {
        throw CLIException("Item with id " + std::to_string(id) + " not found");
    }
}

bool Slide::nameRepeatingCheck(const std::string  name) {
    return std::find_if(_items.begin(), _items.end(), [name](const std::shared_ptr<Item>& item) {
        return item->getName() == name;
    }) != _items.end();
}

int Slide::findMaxOrder() {
    int maxOrder = 0;
    for (const auto& item : _items) {
        if (item->getLayer() > maxOrder) {
            maxOrder = item->getLayer();
        }
    }
    return maxOrder;
}

void Slide::orderByLayer() {
    std::sort(_items.begin(), _items.end(), [](const std::shared_ptr<Item>& a, const std::shared_ptr<Item>& b) {
        return a->getLayer() < b->getLayer();
    });
}

std::vector<std::shared_ptr<Item>> &Slide::getItemList()
{
    return _items;
}

void Slide::bringItemForward(int id)
{
    auto it = std::find_if(_items.begin(), _items.end(), [id](const std::shared_ptr<Item>& item) {
        return item->getId() == id;
    });

    if (it != _items.end()) {
        if ((*it)->getLayer() < findMaxOrder()) {
            (*it)->setLayer((*it)->getLayer() + 1);
            orderByLayer();
        }
    }
}

void Slide::sendItemBackward(int id) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        if ((*it)->getLayer() > 0)
        {
            (*it)->setLayer((*it)->getLayer() - 1);
            orderByLayer();
        }
    }
}

void Slide::bringItemToFront(int id) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        (*it)->setLayer(findMaxOrder() + 1);
        orderByLayer();
    }
}

void Slide::sendItemToBack(int id) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        (*it)->setLayer(0);
        orderByLayer();
    }
}

std::vector<std::shared_ptr<Item>>::iterator Slide::getItemById(int id) {
    return std::find_if(_items.begin(), _items.end(), [id](const std::shared_ptr<Item>& item) {
        return item->getId() == id;
    });
}

std::vector<std::shared_ptr<Item>>::iterator Slide::getItemByName(const std::string &name) {
    return std::find_if(_items.begin(), _items.end(), [name](const std::shared_ptr<Item>& item) {
        return item->getName() == name;
    });
}
