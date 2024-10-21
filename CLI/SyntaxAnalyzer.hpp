#ifndef SYNTAX_HPP 
#define SYNTAX_HPP

#include <vector>
#include <unordered_map>
#include <functional>

#include "Tokenizer.hpp"
#include "Command.hpp"

using strVectorInMap = std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>>;

class SyntaxAnalyzer {
public:
    SyntaxAnalyzer();
    strVectorInMap startSyntaxAnalize(std::stringstream& input);

private:
    Tokenizer* tokenizer;
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<bool(const std::string)>>> checkingMap;

private:

    strVectorInMap checkCommandCorrectness(std::vector<std::unique_ptr<SToken>> tokens);
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

