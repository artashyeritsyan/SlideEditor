#ifndef   CONTROLLER_HPP
#define   CONTROLLER_HPP

#include <iostream>
#include <sstream>

#include "CLI/Command.hpp"
#include "CLI/Parser.hpp"
#include "Models/Presentation.hpp"

class Controller {
public:
    Controller();
    void startProgram();
    
private:
    std::shared_ptr<Parser> _parser;
    std::shared_ptr<Presentation> _presentation;
    std::shared_ptr<Editor> _editor;
/// TODO: in feature need a function for deserializing file into Presentation
};

#endif // CONTROLLER_HPP