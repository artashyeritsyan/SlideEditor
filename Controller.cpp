#include "Controller.hpp"

Controller::Controller()
{
    _parser = std::make_unique<Parser>();
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

            std::unique_ptr<Command> command = _parser->parse(sInput);
            command->execute();
        }
    } catch (const std::exception& e) {
        std::cerr << "Parsing error: " << e.what() << std::endl;
    }
}