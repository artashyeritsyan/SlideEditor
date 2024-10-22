#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>

enum class ETokenType {
    WORD,
    FLAG,
    VALUE,
    END
};

struct SToken {
public:
    ETokenType type;
    // value need to be std::variant
    std::string value;

    SToken(ETokenType type, const std::string& value) : type(type), value(value) {}

    std::string getTypeString() const;
};

#endif // TOKEN_HPP