#include "Slide.hpp"


std::vector<std::shared_ptr<Item>> &Slide::getAllItems()
{
    orderByLayer();
    return _items;
}

void Slide::addItem(ItemTypeEnum type, std::pair<int, int> position = {0, 0})
{
    _items.push_back(std::make_shared<Item>(type, findMaxOrder() + 1, position));
}

size_t Slide::findMaxOrder()
{
    size_t maxOrder = 0;
    for (const auto& item : _items)
    {
        if (item->getLayer() > maxOrder)
        {
            maxOrder = item->getLayer();
        }
    }
    return maxOrder;
}

void Slide::orderByLayer()
{
    std::sort(_items.begin(), _items.end(), [](const std::shared_ptr<Item>& a, const std::shared_ptr<Item>& b) {
        return a->getLayer() < b->getLayer();
    });
}

void Slide::bringItemForward(size_t id)
{
    auto it = std::find_if(_items.begin(), _items.end(), [id](const std::shared_ptr<Item>& item) {
        return item->getId() == id;
    });

    if (it != _items.end())
    {
        if ((*it)->getLayer() < findMaxOrder())
        {
            (*it)->setLayer((*it)->getLayer() + 1);
            orderByLayer();
        }
    }
}

void Slide::sendItemBackward(size_t id)
{

    auto it = getItemById(id);
    if (it != _items.end())
    {
        if ((*it)->getLayer() > 0)
        {
            (*it)->setLayer((*it)->getLayer() - 1);
            orderByLayer();
        }
    }
}

void Slide::bringItemToFront(size_t id)
{
}

void Slide::sendItemToBack(size_t id)
{
}

std::vector<std::shared_ptr<Item>>::iterator Slide::getItemById(size_t id)
{
    return std::find_if(_items.begin(), _items.end(), [id](const std::shared_ptr<Item>& item) {
        return item->getId() == id;
    });
}
