#ifndef STOKEN_HPP 
#define STOKEN_HPP

#include <variant>
#include <string>
#include <iostream>

struct SToken {
    enum class EType {
        Word,
        Arg,
        Value,
        Invalid,
        EOL 
    } _type;

    std::variant<std::string, int, double> _content;

    SToken(EType type, std::variant<std::string, int, double> content) : _type(type), _content(content) {}

    EType getType() const { return _type; }
    std::variant<std::string, int, double> getContent() const { return _content; }

};

#endif //STOKEN_HPP