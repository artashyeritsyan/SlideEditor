#include "Slide.hpp"


std::vector<std::shared_ptr<Item>> &Slide::getAllItems() {
    orderByLayer();
    return _items;
}

void Slide::addItem(ItemTypeEnum type, std::pair<double, double> position = {0, 0}, 
                    double width = 0, double height = 0, const std::string& content = "") {

    auto tmpItem = std::make_shared<Item>(type, findMaxOrder() + 1, position, width, height);

    if (content != "") {
        tmpItem->setTextContent(content);
    }
    
    _items.push_back(tmpItem);
}

// void Slide::addItem(ItemTypeEnum type, double x, double y) {
//     _items.push_back(std::make_shared<Item>(type, findMaxOrder() + 1, x, y));
// }

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

// void Slide::removeItem(const std::string &name) {
//     auto it = getItemByName(name);
//     if (it != _items.end()) {
//         _items.erase(it);
//     }
//     else {
//         throw CLIException("Item with name " + name + " not found");
//     }
// }

void Slide::renameItem(size_t id, const std::string &newName) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        (*it)->setName(newName);
    }
}

bool Slide::nameRepeatingCheck(const std::string  name) {
    return std::find_if(_items.begin(), _items.end(), [name](const std::shared_ptr<Item>& item) {
        return item->getName() == name;
    }) != _items.end();
}

size_t Slide::findMaxOrder() {
    size_t maxOrder = 0;
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

void Slide::bringItemForward(size_t id)
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

void Slide::sendItemBackward(size_t id) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        if ((*it)->getLayer() > 0)
        {
            (*it)->setLayer((*it)->getLayer() - 1);
            orderByLayer();
        }
    }
}

void Slide::bringItemToFront(size_t id) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        (*it)->setLayer(findMaxOrder() + 1);
        orderByLayer();
    }
}

void Slide::sendItemToBack(size_t id) {
    auto it = getItemById(id);
    if (it != _items.end()) {
        (*it)->setLayer(0);
        orderByLayer();
    }
}

std::vector<std::shared_ptr<Item>>::iterator Slide::getItemById(size_t id) {
    return std::find_if(_items.begin(), _items.end(), [id](const std::shared_ptr<Item>& item) {
        return item->getId() == id;
    });
}

std::vector<std::shared_ptr<Item>>::iterator Slide::getItemByName(const std::string &name) {
    return std::find_if(_items.begin(), _items.end(), [name](const std::shared_ptr<Item>& item) {
        return item->getName() == name;
    });
}
