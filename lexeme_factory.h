#ifndef LEXEME_FACTORY_H
#define LEXEME_FACTORY_H

#include "binary_operator.h"
#include "constants.h"
#include "lexer_exception.h"
#include "number_lexeme.h"
#include "paren_lexeme.h"
#include "unary_operator.h"

#include <memory>
#include <string>

enum class LexemeKind {
    Number,
    BinaryOperator,
    UnaryOperator,
    LeftParen,
    RightParen
};

class LexemeFactory {
public:
    std::shared_ptr<Lexeme> create(LexemeKind kind, const std::string& text) const {
        std::shared_ptr<Lexeme> result;
        if (kind == LexemeKind::Number)
            result = std::make_shared<NumberLexeme>(text);
        else
            result = createOperator(kind, text);
        return result;
    }

private:
    std::shared_ptr<Lexeme> createOperator(LexemeKind kind, const std::string& text) const {
        std::shared_ptr<Lexeme> result;
        if (kind == LexemeKind::BinaryOperator)
            result = createBinaryOperator(text);
        else if (kind == LexemeKind::UnaryOperator)
            result = createUnaryOperator(text);
        else if (kind == LexemeKind::LeftParen)
            result = createLeftParen(text);
        else if (kind == LexemeKind::RightParen)
            result = createRightParen(text);
        else
            throw LexerException("Suitable lexeme factory was not found");
        return result;
    }

    std::shared_ptr<Lexeme> createBinaryOperator(const std::string& text) const {
        if (!MathOperator::exists(text, MathOperator::Type::Binary))
            throw LexerException("Unknown binary operator: " + text);
        return std::make_shared<BinaryOperator>(text);
    }

    std::shared_ptr<Lexeme> createUnaryOperator(const std::string& text) const {
        if (!MathOperator::exists(text, MathOperator::Type::Unary))
            throw LexerException("Unknown unary operator: " + text);
        return std::make_shared<UnaryOperator>(text);
    }

    std::shared_ptr<Lexeme> createLeftParen(const std::string& text) const {
        if (text != "(")
            throw LexerException("Unknown left parenthesis: " + text);
        return std::make_shared<LeftParenLexeme>();
    }

    std::shared_ptr<Lexeme> createRightParen(const std::string& text) const {
        if (text != ")")
            throw LexerException("Unknown right parenthesis: " + text);
        return std::make_shared<RightParenLexeme>();
    }
};

#endif // LEXEME_FACTORY_H
