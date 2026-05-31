#ifndef LEXEME_H
#define LEXEME_H

#include "constants.h"

#include <stack>
#include <string>

enum class LexemeType {
    Number,
    BinaryOperator,
    UnaryOperator,
    LeftParen,
    RightParen
};

class Lexeme {
public:
    enum class OperatorPriority {
        None = 0,
        Unary = 2,
        Multiplicative = 3,
        Additive = 4
    };

    virtual ~Lexeme() = default;
    virtual LexemeType type() const = 0;
    virtual std::string text() const = 0;
    virtual bool canBePlacedAfter(const Lexeme* previous) const = 0;
    virtual void evaluate(std::stack<double>&) const {}
    virtual OperatorPriority priority() const {
        return OperatorPriority::None;
    }
};

#endif // LEXEME_H
