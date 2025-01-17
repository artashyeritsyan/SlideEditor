#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include "../CLI/Controller.hpp"
#include "../CLI/Parser.hpp"
#include "../Editor.hpp"
#include "../Models/Presentation.hpp"
#include "../Visualization/Visualization.hpp"
#include "../Serialization/Serialization.hpp"

class Serialization;
class Visualization;
class Editor;

class Application {
public:
    static Application& getInstance();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    std::shared_ptr<Controller> getController() const;
    std::shared_ptr<Editor> getEditor() const;
    std::shared_ptr<Parser> getParser() const;
    std::shared_ptr<Presentation>& getPresentation();
    std::shared_ptr<Serialization> getSerializaton() const;
    std::shared_ptr<Visualization> getVisualization() const;

    void run();

private:
    Application();

    std::shared_ptr<Controller> _controller;
    std::shared_ptr<Editor> _editor;
    std::shared_ptr<Parser> _parser;
    std::shared_ptr<Presentation> _presentation;
    std::shared_ptr<Serialization> _serialization;
    std::shared_ptr<Visualization> _visualization;
};


#endif // APPLICATION_HPP
