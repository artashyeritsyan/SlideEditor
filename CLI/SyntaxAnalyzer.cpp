#include "SyntaxAnalyzer.hpp"

SyntaxAnalyzer::SyntaxAnalyzer() {
   createCheckingMap();
}

void SyntaxAnalyzer::createCheckingMap()
{
    _commandRules = {
        {"addslide", {
            {"id", [this](const std::string& value) { return this->IdValidation(value); }}
        }},
        {"removeslide", {
            {"id", [this](const std::string& value) { return this->IdValidation(value); }}
        }},
        {"addshape", {
            {"pos", [this](const std::string& value) { return this->positionValidation(value); }},
            {"size", [this](const std::string& value) { return this->sizeValidation(value); }}
        }},
        {"removeshape", {
            {"id", [this](const std::string& value) { return this->IdValidation(value); }}
        }}
    };
} 

std::shared_ptr<SCommandInfo> SyntaxAnalyzer::startSyntaxAnalize(std::stringstream &input)
{
    _tokenizer = new Tokenizer(input);
    std::vector<std::shared_ptr<SToken>> tokens;
    std::shared_ptr<SToken> token = _tokenizer->nextToken();

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
        token = _tokenizer->nextToken();
    }

    return std::move(checkCommandCorrectness(tokens));    
}

std::shared_ptr<SCommandInfo> SyntaxAnalyzer::checkCommandCorrectness(std::vector<std::shared_ptr<SToken>> tokens) {

    /// TODO: talisa menak 1 bar piti 2 haty ta

    std::string cmd = tokens[0]->value;

    std::shared_ptr<SCommandInfo> cmdInfo = std::make_unique<SCommandInfo>();
    
    int i = 0;
    while (tokens[i]->type == ETokenType::WORD && i < tokens.size()) {
        cmdInfo->name += tokens[i++]->value;
    }

    if (_commandRules.find(cmd) == _commandRules.end()) {
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

        // if(_commandRules[cmd][flag](value)) {
        //     cmdInfo->arguments[flag].push_back(value);
        // }
        
        /// TODO: stugel flagy ka te che find()-ov
        cmdInfo->arguments[flag].push_back(_commandRules[cmd][flag](value));

    }

    return cmdInfo;
}


VariantIntDoubleStr SyntaxAnalyzer::positionValidation(const std::string& value)
{
    try {
        double position = std::stod(value);
        return position;
    }
    catch (std::exception ex) {
        // throw an exception 
        std::cerr << "Incorrect type" << std::endl;
    }
}

VariantIntDoubleStr SyntaxAnalyzer::sizeValidation(const std::string &value)
{
    try {
        double sizeParam = std::stod(value);

        if (sizeParam <= 0) {
            // throw an exception
            std::cerr << "Size cant be smaller or equal to 0" << std::endl;
        }
        return sizeParam;
    }
    catch (std::exception ex) {
        // throw an exception
        std::cerr << "Incorrect type" << std::endl;
    }
}

VariantIntDoubleStr SyntaxAnalyzer::IdValidation(const std::string &value)
{
    try {
        int id = std::stoi(value);

        if (id <= 0) {
            std::cerr << "Id cant be smaller or equal to 0" << std::endl;
            // for exception class in future
            // throw exception("Id cant be smaller or equal to 0");
        }
        return id;
    }
    catch (std::exception ex) {
        // throw an exception 
        std::cerr << "Incorrect type" << std::endl;
    }
}
