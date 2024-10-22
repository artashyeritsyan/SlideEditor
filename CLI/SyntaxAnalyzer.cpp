#include "SyntaxAnalyzer.hpp"

SyntaxAnalyzer::SyntaxAnalyzer() {
   createCheckingMap();
}

std::unique_ptr<CommandInfo> SyntaxAnalyzer::startSyntaxAnalize(std::stringstream &input)
{
    tokenizer = new Tokenizer(input);
    std::vector<std::unique_ptr<SToken>> tokens;
    std::unique_ptr<SToken> token = tokenizer->nextToken();

    while(token->type != ETokenType::END) {

        if (token->type == ETokenType::WORD && (
        tokens.size() == 0 || 
        tokens[tokens.size() - 1]->type == ETokenType::WORD)) 
        {
            tokens.push_back(token);
        }

        else if (token->type == ETokenType::FLAG &&
        tokens.size() != 0 &&
        tokens[tokens.size() - 1]->type != ETokenType::FLAG)
        {
            tokens.push_back(token);
        }

        else if (token->type == ETokenType::VALUE && (
        tokens[tokens.size() - 1]->type == ETokenType::FLAG ||
        tokens[tokens.size() - 1]->type == ETokenType::VALUE )) 
        {
            tokens.push_back(token);
        }
        
        else 
        {
            // TODO: write custom exceptions class and add this error to it
            std::cerr << "Incorrect command order" << std::endl;
            // return std::vector<SToken>();
            exit(0);
        }
        token = tokenizer->nextToken();
    }

    return checkCommandCorrectness(tokens);    
}

std::unique_ptr<CommandInfo> SyntaxAnalyzer::checkCommandCorrectness(std::vector<std::unique_ptr<SToken>> tokens) {

    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> commandMap;
    std::string cmd = tokens[0]->value;


    std::unique_ptr<CommandInfo> cmdInfo = std::make_unique<CommandInfo>();
    
    int i = 0;
    while (tokens[i]->type == ETokenType::WORD && i < tokens.size()) {
        cmdInfo->name += tokens[i++]->value;
    }

    if (commandRules.find(cmd) == commandRules.end()) {
        std::cerr << "Invalid command" << std::endl;
        // throw an exception
    }

    std::string flag;
    std::string value;
    while(i < tokens.size()) {

        if(tokens[i]->type == ETokenType::FLAG) {
            flag = tokens[i]->value;
        }
        else if (tokens[i]->type == ETokenType::VALUE) {
            value = tokens[i]->value;
        }

        if(commandRules[cmd][flag](value)) {
            cmdInfo->arguments[flag].push_back(value);
        }

    }

    return cmdInfo;
}

void SyntaxAnalyzer::createCheckingMap()
{
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<bool(const std::vector<std::string>&)>>> commandMap = {
        {"addshape", {
            {"pos", [this](const std::string& value) { return this->isPosition(value); }},
            {"size", [this](const std::string& value) { return this->isSize(value); }}
        }},
        {"removeshape", {
            {"id", [this](const std::string& value) { return this->isId(value); }}
        }}
    };
}

bool SyntaxAnalyzer::isPosition(const std::string& value)
{
    try {
        double pos = std::stod(value);
        return true;
    }
    catch (std::exception ex) {
        std::cerr << "Incorrect type" << std::endl;
        return false;
    }
}

bool SyntaxAnalyzer::isSize(const std::string &value)
{
    try {
        double sizeParam = std::stod(value);

        if (sizeParam <= 0) {
            // std::cerr << "Size cant be smaller or equal to 0" << std::endl;
            return false;
        }
        return true;
    }
    catch (std::exception ex) {
        std::cerr << "Incorrect type" << std::endl;
        return false;
    }
}

bool SyntaxAnalyzer::isId(const std::string &value)
{
    try {
        int id = std::stoi(value);

        if (id <= 0) {
            std::cerr << "Id cant be smaller or equal to 0" << std::endl;
            // for exception class in future
            // throw exception("Id cant be smaller or equal to 0");
            return false;
        }
        return true;
    }
    catch (std::exception ex) {
        std::cerr << "Incorrect type" << std::endl;
        return false;
    }
}
