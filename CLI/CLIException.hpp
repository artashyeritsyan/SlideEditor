#ifndef   EXCEPTION_HPP
#define   EXCEPTION_HPP

#include <exception>
#include <string>

class CLIException : public std::exception {
private:
    std::string message_;

public:
    explicit CLIException(const std::string& message)
        : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }
};

#endif // EXCEPTION_HPP
