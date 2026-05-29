#ifndef UNARYOPERATORFACTORY_H
#define UNARYOPERATORFACTORY_H

#include "ifactorylexeme.h"
#include "unaryoperator.h"
#include "lexerexception.h"

class UnaryOperatorFactory : public ILexemeFactory {
public:
    std::shared_ptr<Lexeme> create(const std::string& text) const override {
        if (!Operator::exists(text, Operator::OperatorType::Unary))
            throw LexerException("Неизвестный унарный оператор: " + text);
        return std::make_shared<UnaryOperator>(text);
    }
};

#endif // UNARYOPERATORFACTORY_H
