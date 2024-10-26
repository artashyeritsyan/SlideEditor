#include "Command.hpp"
#include <iostream>





Command::Command(std::unique_ptr<argumentsMap> args)
{
    arguments = std::move(args);
}

void CmdAddShape::execute() override {

}
