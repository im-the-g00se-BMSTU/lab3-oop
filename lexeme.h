#ifndef LEXEME_H
#define LEXEME_H

#include "constants.h"

#include <memory>
#include <stack>
#include <string>

class Lexeme {
public:
    enum class OperatorPriority {
        None = 0,
        Unary = 2,
        Multiplicative = 3,
        Additive = 4
    };

    virtual ~Lexeme() = default;
    virtual std::string text() const = 0;
    virtual std::shared_ptr<Lexeme> clone() const = 0;
    virtual bool canBePlacedAfter(const Lexeme* previous) const = 0;
    virtual void evaluate(std::stack<double>&) const {}

    virtual bool isEqual(const Lexeme& other) const {
        return typeid(*this) == typeid(other) && text() == other.text();
    }
};

#endif // LEXEME_H
