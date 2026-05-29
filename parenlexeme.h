#ifndef PARENLEXEME_H
#define PARENLEXEME_H

#include "operator.h"
#include "numberlexeme.h"

class LeftParenLexeme : public Operator {
public:
    LeftParenLexeme() : Operator("(", OperatorType::LeftParen) {}

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<LeftParenLexeme>(*this);
    }
    bool canBePlacedAfter(const Lexeme* previous) const override;
};

class RightParenLexeme : public Operator {
public:
    RightParenLexeme() : Operator(")", OperatorType::RightParen) {}
    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<RightParenLexeme>(*this);
    }
    bool canBePlacedAfter(const Lexeme* previous) const override;
};

#endif // PARENLEXEME_H
