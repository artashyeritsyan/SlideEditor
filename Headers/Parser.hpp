#pragma once

#include "Controller.hpp"
#include "ShapeTypeEnum.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include <sstream>

class Command {
public:
    Command() {
};

    Command parseCommand(const std::string& input);

private:
    Controller ctrl;
    std::map<std::string, std::function<void(const Command&)>> commandMap; 
    std::string name;
    std::map<std::string, std::vector<std::string>> options;     
};
