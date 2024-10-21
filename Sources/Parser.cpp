#include "Parser.hpp"

Command Command::parseCommand(const std::string& input) {
    std::istringstream iss(input);
    std::string token;
    Command cmd;
    std::string lastOption;
    int expectedArgs = 0; 

    if (iss >> cmd.name) {
        while (iss >> token) {
            if (token[0] == '-') {
                lastOption = token;

                if (lastOption == "-pos" || lastOption == "-s") {
                    expectedArgs = 2;  
                } else {
                    expectedArgs = 1;  
                }

                cmd.options[lastOption] = std::vector<std::string>();
            } else if (!lastOption.empty() && expectedArgs > 0) {

                cmd.options[lastOption].push_back(token);
                --expectedArgs; 
                if (expectedArgs == 0) {
                    lastOption.clear();
                }
            }
        }
    }

    return cmd;
}

