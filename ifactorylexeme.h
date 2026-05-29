#ifndef IFACTORYLEXEME_H
#define IFACTORYLEXEME_H

#include "lexeme.h"
#include <memory>
#include <string>

enum class LexemeKind {
    Number,
    BinaryOperator,
    UnaryOperator,
    Function,
    LeftParen,
    RightParen
};

class ILexemeFactory {
public:
    virtual ~ILexemeFactory() = default;
    virtual std::shared_ptr<Lexeme> create(const std::string& text) const = 0;
};

#endif // IFACTORYLEXEME_H
