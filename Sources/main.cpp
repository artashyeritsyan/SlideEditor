#include <iostream>

#include "../CLI/SyntaxAnalyzer.hpp"

#define DEBUG

int main() {



    #ifdef DEBUG

    std::string input;

    while (input != "exit" || input != "q") {

        std::cout << "Input command`" << std::endl;
        std::getline(std::cin, input);

        std::stringstream sInput(input);
        
        SyntaxAnalyzer *syntax = new SyntaxAnalyzer;
        auto tokens = syntax->startSyntaxAnalize(sInput);
        if (tokens.size() == 0) {
            return 0;
        }
        
        for (const auto& token : tokens) {
            std::cout << token.getTypeString() << " : " << token.value << std::endl;
        }

    }

    #endif  // DEBUG

    return 0;
}
