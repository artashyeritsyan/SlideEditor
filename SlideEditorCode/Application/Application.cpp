#include "Application.hpp"

Application& Application::getInstance() {
    static Application instance;
    return instance;
}

Application::Application() {
    _presentation = std::make_shared<Presentation>();
    _editor = std::make_shared<Editor>();
    _parser = std::make_shared<Parser>();
    _controller = std::make_shared<Controller>();
    _visualization = std::make_shared<Visualization>();
}

std::shared_ptr<Editor> Application::getEditor() const {
    return _editor;
}

std::shared_ptr<Presentation> &Application::getPresentation()
{
    return _presentation;
}

std::shared_ptr<Serialization> Application::getSerializaton() const
{
    return _serialization;
}

std::shared_ptr<Parser> Application::getParser() const {
    return _parser;
}

std::shared_ptr<Visualization> Application::getVisualization() const {
    return _visualization;
}

std::shared_ptr<Controller> Application::getController() const {
    return _controller;
}

void Application::run() {
    _controller->startProgram(); 
}



