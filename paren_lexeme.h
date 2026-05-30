#ifndef PAREN_LEXEME_H
#define PAREN_LEXEME_H

#include "math_operator.h"
#include "number_lexeme.h"

class LeftParenLexeme : public MathOperator {
public:
    LeftParenLexeme() : MathOperator("(", Type::LeftParen) {}

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<LeftParenLexeme>(*this);
    }

    bool canBePlacedAfter(const Lexeme* previous) const override {
        const MathOperator* op = dynamic_cast<const MathOperator*>(previous);
        return !previous || (op && (op->type() == Type::LeftParen ||
                                    op->type() == Type::Binary ||
                                    op->type() == Type::Unary));
    }
};

class RightParenLexeme : public MathOperator {
public:
    RightParenLexeme()
        : MathOperator(")", Type::RightParen) {}

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<RightParenLexeme>(*this);
    }

    bool canBePlacedAfter(const Lexeme* previous) const override {
        const MathOperator* op = dynamic_cast<const MathOperator*>(previous);
        return previous && (typeid(*previous) == typeid(NumberLexeme) ||
                            (op && op->type() == Type::RightParen));
    }
};

#endif // PAREN_LEXEME_H
