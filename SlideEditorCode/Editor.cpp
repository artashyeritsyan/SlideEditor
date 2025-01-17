#include "Editor.hpp"

// Editor::Editor(std::shared_ptr<Presentation> pres) : _presentation(pres) {};

void Editor::process(std::shared_ptr<IAction> action) {
    auto& presentation = Application::getInstance().getPresentation();
    auto inverseAction = action->doAction(presentation);
    undoStack.push(inverseAction);
    while (!redoStack.empty()) {
        redoStack.pop();
    }
}

void Editor::undo() {
    auto& presentation = Application::getInstance().getPresentation();

    if (undoStack.empty()) {
        throw std::runtime_error("Undo stack is empty!");
    }
    auto action = undoStack.top();
    undoStack.pop();
    auto inverseAction = action->doAction(presentation);

    redoStack.push(inverseAction);
}

void Editor::redo() {
    auto& presentation = Application::getInstance().getPresentation();

    if (redoStack.empty()) {
        throw std::runtime_error("Redo stack is empty!");
    }
    auto action = redoStack.top();
    redoStack.pop();
    auto inverseAction = action->doAction(presentation);

    undoStack.push(inverseAction);
}

// std::shared_ptr<Presentation> Editor::getPresentation() const {
//     return _presentation;
// }
