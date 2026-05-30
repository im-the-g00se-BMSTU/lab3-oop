#ifndef PAREN_LEXEME_H
#define PAREN_LEXEME_H

#include "math_operator.h"

class LeftParenLexeme : public MathOperator {
public:
    LeftParenLexeme() : MathOperator("(", Type::LeftParen) {}

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<LeftParenLexeme>(*this);
    }

    bool canBePlacedAfter(const Lexeme* previous) const override {
        return !previous || previous->kind() == LexemeKind::LeftParen ||
               previous->kind() == LexemeKind::BinaryOperator ||
               previous->kind() == LexemeKind::UnaryOperator;
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
        return previous && (previous->kind() == LexemeKind::Number ||
                            previous->kind() == LexemeKind::RightParen);
    }
};

#endif // PAREN_LEXEME_H
