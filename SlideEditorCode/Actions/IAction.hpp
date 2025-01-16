#ifndef IACTION_HPP
#define IACTION_HPP

#include <memory>

#include "../Models/Presentation.hpp"

class IAction : public std::enable_shared_from_this<IAction> {
public:
    IAction() = default;
    virtual ~IAction() = default;

    virtual std::shared_ptr<IAction> doAction(std::shared_ptr<Presentation> document) = 0;
};


#endif // IACTION_HPP
