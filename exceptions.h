#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class LexemeException : public std::exception {
public:
    explicit LexemeException(const std::string& message)
        : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

class MathException : public std::exception {
public:
    explicit MathException(const std::string& message)
        : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

#endif // EXCEPTIONS_H
