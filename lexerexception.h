#ifndef LEXEREXCEPTION_H
#define LEXEREXCEPTION_H
#include <exception>
#include <string>

class LexerException : public std::exception{
private:
    std::string message;
public:
    LexerException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // LEXEREXCEPTION_H
