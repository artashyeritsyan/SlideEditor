#include "SyntaxAnalyzer.hpp"
#include <memory>

class Parser {
public:
    Parser ();

    void parse(std::stringstream &input);

private:
    std::unique_ptr<SyntaxAnalyzer> syntaxAnalyzer;
};