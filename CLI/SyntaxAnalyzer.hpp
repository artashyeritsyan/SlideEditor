#ifndef SYNTAX_HPP 
#define SYNTAX_HPP

#include <vector>
#include <unordered_map>
#include <functional>

#include "Tokenizer.hpp"
#include "Command.hpp"

using ValueCheckingMap = std::unordered_map<std::string, std::unordered_map<std::string, std::function<bool(const std::string)>>>;

class SyntaxAnalyzer {
public:
    SyntaxAnalyzer();
    std::unique_ptr<CommandInfo> startSyntaxAnalize(std::stringstream& input);

private:
    Tokenizer* tokenizer;
    ValueCheckingMap commandRules;

private:

    std::unique_ptr<CommandInfo> checkCommandCorrectness(std::vector<std::unique_ptr<SToken>> tokens);
    void createCheckingMap();

    bool isPosition(const std::string& value);
    bool isSize(const std::string& value);
    bool isId(const std::string& value);
    
};

#endif // SYNTAX_HPP

// Unknown command
// Incorrect command order
// Syntax Error
// 

