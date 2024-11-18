#include "SyntaxAnalyzer.hpp"

SyntaxAnalyzer::SyntaxAnalyzer() {
    createCheckingMap();
}

void SyntaxAnalyzer::createCheckingMap()
{
    // _commandRules = std::make_unique<ValueCheckingMap>();


    // _commandRules = {
    //     {"addslide", {
    //         {"id", [this](const std::string& value) { return this->IdValidation(value); }}
    //     }},
    //     {"removeslide", {
    //         {"id", [this](const std::string& value) { return this->IdValidation(value); }}
    //     }},
    //     {"addshape", {
    //         {"pos", [this](const std::string& value) { return this->positionValidation(value); }},
    //         {"size", [this](const std::string& value) { return this->sizeValidation(value); }}
    //     }},
    //     {"removeshape", {
    //         {"id", [this](const std::string& value) { return this->IdValidation(value); }}
    //     }}
    // };

_commandRules = std::make_unique<ValueCheckingMap>(ValueCheckingMap{
    {"addslide", {
        {"id", [this](const std::string& value) -> VariantIntDoubleStr { 
            return this->IdValidation(value); 
        }}
    }},
    {"removeslide", {
        {"id", [this](const std::string& value) -> VariantIntDoubleStr { 
            return this->IdValidation(value); 
        }}
    }},
    {"addshape", {
        {"pos", [this](const std::string& value) -> VariantIntDoubleStr { 
            return this->positionValidation(value); 
        }},
        {"size", [this](const std::string& value) -> VariantIntDoubleStr { 
            return this->sizeValidation(value); 
        }}
    }},
    {"removeshape", {
        {"id", [this](const std::string& value) -> VariantIntDoubleStr { 
            return this->IdValidation(value); 
        }}
    }}
});

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
            throw CLIException("Incorrect command order");
            exit(0);
        }
        token = _tokenizer->nextToken();
    }

    delete _tokenizer;
    return checkCommandCorrectness(tokens);    
}

std::shared_ptr<SCommandInfo> SyntaxAnalyzer::checkCommandCorrectness(std::vector<std::shared_ptr<SToken>> tokens) {

    std::shared_ptr<SCommandInfo> cmdInfo = std::make_unique<SCommandInfo>();

    int i = 0;
    while (tokens[i]->type == ETokenType::WORD && i < tokens.size()) {
        cmdInfo->name += tokens[i++]->value;
    }

    // if (!_commandRules || _commandRules->find(cmdInfo->name) == _commandRules->end()) {
    //     throw CLIException("Invalid command");
    // }

    auto& commandRules = *_commandRules;
    auto commandIter = commandRules.find(cmdInfo->name);
    if (commandIter == commandRules.end()) {
        throw CLIException("Invalid command");
    }


    std::string flag;
    std::string value;
    while(i < tokens.size()) {

        if(tokens[i]->type == ETokenType::FLAG) {
            flag = tokens[i]->value;
            ++i;
            continue;
        }
        else if (tokens[i]->type == ETokenType::VALUE) {
            value = tokens[i]->value;
            ++i;
        }

        // auto& commandMap = (*_commandRules)[cmdInfo->name];
        // if (commandMap.find(flag) == commandMap.end()) {
        //     throw CLIException("Invalid argument - '" + flag + "'");
        // }

        // cmdInfo->arguments[flag].push_back(commandMap[flag](value));

         // Use an iterator to access the flag map for the command
        auto& flagMap = commandIter->second;
        auto flagIter = flagMap.find(flag);
        if (flagIter == flagMap.end()) {
            throw CLIException("Invalid argument - '" + flag + "'");
        }

        // Call the validation function and store the result
        cmdInfo->arguments[flag].push_back(flagIter->second(value));

    }

    return cmdInfo;
}


VariantIntDoubleStr SyntaxAnalyzer::positionValidation(const std::string& value)
{
    try {
        double position = 0;

        try {
            position = std::stod(value);
        } catch (const std::exception&) {
            throw CLIException("Incorrect type");
        }

        return position;
    }
    catch (const CLIException&) {
        throw;
    }
}

VariantIntDoubleStr SyntaxAnalyzer::sizeValidation(const std::string &value)
{
    try {
        double sizeParam = 0;
        
        try {
            sizeParam = std::stod(value);
        } catch (const std::exception& ex) {
            throw CLIException("Incorrect type");
        }

        if (sizeParam <= 0) {
            throw CLIException("Size can't be smaller or equal to 0");
        }

        return sizeParam;
    }
    catch (const CLIException& ex) {
        throw;
    }
}

VariantIntDoubleStr SyntaxAnalyzer::IdValidation(const std::string &value)
{
    try {
        int id = 0;

        try {
            id = std::stoi(value);
        } catch (const std::exception&) {
            throw CLIException("Incorrect type");
        }

        if (id <= 0) {
            throw CLIException("Id can't be smaller or equal to 0");
        }

        return id;
    }
    catch (const CLIException&) {
        throw;
    }
}
