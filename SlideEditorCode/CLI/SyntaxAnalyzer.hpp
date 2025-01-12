#ifndef SYNTAX_HPP 
#define SYNTAX_HPP

#include <functional>
#include <unordered_map>
#include <vector>

#include "Command.hpp"
#include "Tokenizer.hpp"

using VariantIntDoubleStr = std::variant<int, double, std::string>;
using ValueCheckingMap = std::unordered_map<std::string, std::unordered_map<std::string, std::function<VariantIntDoubleStr(const std::string&)>>>;

class SyntaxAnalyzer {
public:
    SyntaxAnalyzer();
    std::shared_ptr<SCommandInfo> startSyntaxAnalize(std::stringstream& input);

private:
    std::shared_ptr<SCommandInfo> checkCommandCorrectness(std::vector<std::shared_ptr<SToken>> tokens);
    std::unordered_map<std::string, std::function<VariantIntDoubleStr(const std::string&)>> createItemCommand();
    std::unordered_map<std::string, std::function<VariantIntDoubleStr(const std::string&)>> idNameValidationCommand();
    void createCheckingMap();

    VariantIntDoubleStr positionValidation(const std::string& value);
    VariantIntDoubleStr sizeValidation(const std::string& value);
    VariantIntDoubleStr idValidation(const std::string& value);
    VariantIntDoubleStr nameValidation(const std::string& value);

private:
    Tokenizer* _tokenizer;
    ValueCheckingMap _commandRules;
};

#endif // SYNTAX_HPP
