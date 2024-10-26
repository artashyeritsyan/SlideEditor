#include "Item.hpp"

Item::Item(const std::string &name = "", ItemTypeEnum type, int layerOrder, const std::pair<int, int> &position, int width, int height)
{
    if (name == "") {
        this->name = type + std::to_string()
    }
}