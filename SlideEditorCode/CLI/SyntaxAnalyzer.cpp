#include "SyntaxAnalyzer.hpp"

SyntaxAnalyzer::SyntaxAnalyzer() {
    createCheckingMap();
}

void SyntaxAnalyzer::createCheckingMap()
{
    _commandRules = {
        {"addslide", {
            {"id", [this](const std::string& value) { return this->idValidation(value); }},
            {"none", nullptr }
        }},
        {"removeslide", {
            {"id", [this](const std::string& value) { return this->idValidation(value); }},
            {"none", nullptr }
        }},
        {"moveslide", {
            {"id", [this](const std::string& value) { return this->idValidation(value); }},
        }},
        {"slidelist", {{"none", nullptr }}},
        {"itemlist", {{"none", nullptr }}},
        {"nextslide", {{"none", nullptr }}},
        {"prevslide", {{"none", nullptr }}},
        {"addrect", createItemCommand()},
        {"addcircle", createItemCommand()},
        {"addtriangle", createItemCommand()},
        {"removeitem", {
            idNameValidationCommand()
        }},
        {"moveitem", {
            {"id", [this](const std::string& value) { return this->idValidation(value); }},
            {"name", [this](const std::string& value) { return this->nameValidation(value); }},
            {"pos", [this](const std::string& value) { return this->positionValidation(value); }}
        }},
        {"changesize", {
            {"id", [this](const std::string& value) { return this->idValidation(value); }},
            {"name", [this](const std::string& value) { return this->nameValidation(value); }},
            {"size", [this](const std::string& value) { return this->sizeValidation(value); }}
        }},
        {"renameitem", idNameValidationCommand()},
        {"bringforward", idNameValidationCommand()},
        {"sendbackward", idNameValidationCommand()},
        {"bringtofront", idNameValidationCommand()},
        {"sendtoback", idNameValidationCommand()},
        {"save", {
            {"f", [this](const std::string& value) { return this->nameValidation(value); }},
            {"none", nullptr }
        }},
        {"load", {
            {"f", [this](const std::string& value) { return this->nameValidation(value); }},
            {"none", nullptr }
        }}
    };
}

std::unordered_map<std::string, std::function<VariantIntDoubleStr(const std::string&)>> SyntaxAnalyzer::idNameValidationCommand() {
    return {
        {"id", [this](const std::string& value) { return this->idValidation(value); }},
        {"name", [this](const std::string& value) { return this->nameValidation(value); }}
    };
}

std::unordered_map<std::string, std::function<VariantIntDoubleStr(const std::string&)>> SyntaxAnalyzer::createItemCommand() {
    return {
        {"pos", [this](const std::string& value) { return this->positionValidation(value); }},
        {"size", [this](const std::string& value) { return this->sizeValidation(value); }},
        {"t", [this](const std::string& value) { return value; }},
        {"none", nullptr }
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
    while (i < tokens.size() && tokens[i]->type == ETokenType::WORD) {
        cmdInfo->name += tokens[i++]->value;
    }

    if (_commandRules.find(cmdInfo->name) == _commandRules.end()) {
        throw CLIException("Invalid command");
    }

    if (i == tokens.size() ) {
        if (_commandRules[cmdInfo->name].find("none") != _commandRules[cmdInfo->name].end()) {
            return cmdInfo;
        }
        else {
            throw CLIException("Expected arguments");
        }
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

        auto& commandMap = _commandRules[cmdInfo->name];
        if (commandMap.find(flag) == commandMap.end()) {
            throw CLIException("Invalid argument - '" + flag + "'");
        }

        cmdInfo->arguments[flag].push_back(commandMap[flag](value));
    }
    
    if (cmdInfo->arguments.size() == 0) {
        throw CLIException("Invalid argument");
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
    catch (const CLIException& ex) {
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

VariantIntDoubleStr SyntaxAnalyzer::idValidation(const std::string &value)
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
    catch (const CLIException& ex) {
        throw;
    }
}

VariantIntDoubleStr SyntaxAnalyzer::nameValidation(const std::string &value)
{
    if (value.empty()) {
        throw CLIException("Name cannot be empty");
    }

    if (!std::isalpha(value[0])) {
        throw CLIException("Name must start with an alphabetic character");
    }

    return value;
}
