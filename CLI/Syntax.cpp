#include "Syntax.hpp"


enum class State { 
    Start,
    Cmd,  
    Arg,   
    Value,   
    Error    
};

std::unordered_map<std::string, std::vector<std::unique_ptr<SToken>>> SyntaxAnalyzer::analyze(std::istream& inputStream) {
    
    Tokenizer tokenizer;
    std::unordered_map<std::string, std::vector<std::unique_ptr<SToken>>> result;

    State currentState = State::Start;
    std::string currentCmd;
    std::string currentArg;

    while (inputStream) {
        std::unique_ptr<SToken> token = tokenizer.tokenize(inputStream);

        if (!token) break;  

        switch (currentState) {
            case State::Start:
                if (token->getType() == SToken::EType::Word) {
                    currentCmd = std::get<std::string>(token->getContent());
                    result[currentCmd] = {};  
                    currentState = State::Cmd;
                } else {
                    currentState = State::Error;
                }
                break;

            case State::Cmd:
                if (token->getType() == SToken::EType::Arg) {
                    currentArg = std::get<std::string>(token->getContent());
                    currentState = State::Arg;
                } else {
                    currentState = State::Error;
                }
                break;

            case State::Arg:
                if (token->getType() == SToken::EType::Value) {
                    result[currentCmd].push_back(std::move(token));  
                    currentState = State::Value;
                } else {
                    currentState = State::Error;
                }
                break;

            case State::Value:
                if (token->getType() == SToken::EType::Arg) {
                    currentArg = std::get<std::string>(token->getContent());
                    currentState = State::Arg;
                } else if (token->getType() == SToken::EType::Word) {
                    currentCmd = std::get<std::string>(token->getContent());
                    result[currentCmd] = {};  
                    currentState = State::Cmd;
                } else if (token->getType() == SToken::EType::EOL) {
                    currentState = State::Start;  
                } else {
                    currentState = State::Error;
                }
                break;

            case State::Error:
                std::cerr << "Error: Invalid token sequence." << std::endl;
                return {};  
        }
    }

    return result;
}
