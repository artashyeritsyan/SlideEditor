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

    while (true) {
        try {
            std::cout << "Input command`" << std::endl;
            std::getline(std::cin, input);

            std::stringstream sInput(input);

            if(input == "exit" || input == "q") {
                break;
            }

            std::shared_ptr<Command> command = _parser->parse(sInput);
            command->execute(_editor);
        } catch (const CLIException& ex) {
            std::cerr << "CLI Error: " << ex.what() << std::endl;
        }
    }
}