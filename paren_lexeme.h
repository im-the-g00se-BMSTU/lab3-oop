#ifndef PAREN_LEXEME_H
#define PAREN_LEXEME_H

#include "lexeme.h"

class LeftParenLexeme : public Lexeme {
public:
    LexemeType type() const override {
        return LexemeType::LeftParen;
    }

    std::string text() const override {
        return "(";
    }

    bool canBePlacedAfter(const Lexeme* previous) const override {
        return !previous || previous->type() == LexemeType::LeftParen ||
               previous->type() == LexemeType::BinaryOperator ||
               previous->type() == LexemeType::UnaryOperator;
    }
};

class RightParenLexeme : public Lexeme {
public:
    LexemeType type() const override {
        return LexemeType::RightParen;
    }

    std::string text() const override {
        return ")";
    }

    bool canBePlacedAfter(const Lexeme* previous) const override {
        return previous && (previous->type() == LexemeType::Number ||
                            previous->type() == LexemeType::RightParen);
    }
};

#endif // PAREN_LEXEME_H
