#ifndef LEXER_EXCEPTION_H
#define LEXER_EXCEPTION_H

#include <exception>
#include <string>

class LexerException : public std::exception {
public:
    explicit LexerException(const std::string& message)
        : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

#endif // LEXER_EXCEPTION_H
