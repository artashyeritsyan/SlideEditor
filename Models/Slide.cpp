#include "Slide.hpp"


std::vector<std::unique_ptr<Item>> &Slide::getAllItems()
{
    return _items;
}
