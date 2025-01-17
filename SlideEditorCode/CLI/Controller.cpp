#include "Controller.hpp"
#include "../Application/Application.hpp"
#include "../Models/Presentation.hpp"

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

            std::shared_ptr<Command> command = Application::getInstance().getParser()->parse(sInput);
            command->execute();
        } catch (const CLIException& ex) {
            std::cerr << "CLI Error: " << ex.what() << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
}