#ifndef MATHEXCEPTION_H
#define MATHEXCEPTION_H

#include <exception>
#include <string>

class MathException : public std::exception{
private:
    std::string message;
public:
    MathException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // MATHEXCEPTION_H
