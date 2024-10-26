#ifndef   CONTROLLER_HPP
#define   CONTROLLER_HPP

#include <iostream>
#include <sstream>
#include "CLI/Parser.hpp"
#include "CLI/Command.hpp"

class Controller {
public:
    Controller();
    void startProgram();
    
private:
    std::unique_ptr<Parser> _parser;
};

#endif // CONTROLLER_HPP