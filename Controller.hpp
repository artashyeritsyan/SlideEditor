#ifndef   CONTROLLER_HPP
#define   CONTROLLER_HPP

#include <iostream>
#include <sstream>
#include "CLI/Parser.hpp"
#include "CLI/Command.hpp"
#include "Models/Presentation.hpp"

class Controller {
public:
    Controller();
    void startProgram();
    
private:
    std::unique_ptr<Parser> _parser;
    // Need a function for deserializing file into Presentation
    std::shared_ptr<Presentation> _presentation;
};

#endif // CONTROLLER_HPP