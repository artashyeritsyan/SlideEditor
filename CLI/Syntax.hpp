#ifndef SYNTAX_HPP
#define SYNTAX_HPP

#include <unordered_map>
#include <vector>
#include <memory>
#include <istream>
#include "SToken.hpp"
#include "Tokenizer.hpp"

class SyntaxAnalyzer {
public:
    std::unordered_map<std::string, std::vector<std::unique_ptr<SToken>>> analyze(std::istream& inputStream);
};

#endif // SYNTAX_HPP
