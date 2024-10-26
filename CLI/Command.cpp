#include "Command.hpp"

Command::Command(std::unique_ptr<argumentsMap> args)
{
    arguments = std::move(args);
}

void CmdAddSlide::execute()
{
    std::cout << "Executing: Add Slide" << std::endl;
}

void CmdRemoveSlide::execute()
{
}

void CmdAddShape::execute()
{
}

void CmdRemoveShape::execute()
{
}
