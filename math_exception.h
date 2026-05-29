#ifndef MATH_EXCEPTION_H
#define MATH_EXCEPTION_H

#include <exception>
#include <string>

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

#endif // MATH_EXCEPTION_H
