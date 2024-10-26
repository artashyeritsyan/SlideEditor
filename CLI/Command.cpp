#include "Command.hpp"

Command::Command(std::unique_ptr<argumentsMap> args)
{
    arguments = std::move(args);
}

void CmdAddSlide::execute(Editor& editor)
{
    editor.addSlide();
}

void CmdRemoveSlide::execute(Editor& editor)
{
    editor.removeSlide();
}

void CmdAddShape::execute(Editor& editor)
{
}

void CmdRemoveShape::execute(Editor& editor)
{
}
