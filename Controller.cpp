#include "Controller.hpp"

Controller::Controller()
{
    _presentation = std::make_shared<Presentation>();
    _parser = std::make_unique<Parser>(_presentation);
    _editor = std::make_shared<Editor>(_presentation);
}

void Controller::startProgram()
{
    std::string input;

    try {
        while (true) {

            std::cout << "Input command`" << std::endl;
            std::getline(std::cin, input);

            std::stringstream sInput(input);

            // Temporary solution
            if(input != "exit" || input != "q") {
                break;
            }

            std::shared_ptr<Command> command = _parser->parse(sInput);
            command->execute(_editor);
        }
    } catch (const std::exception& e) {
        std::cerr << "Parsing error: " << e.what() << std::endl;
    }
}