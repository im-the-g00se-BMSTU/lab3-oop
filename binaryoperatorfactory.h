#ifndef BINARYOPERATORFACTORY_H
#define BINARYOPERATORFACTORY_H

#include "ifactorylexeme.h"
#include "binaryoperator.h"
#include "lexerexception.h"

class BinaryOperatorFactory : public ILexemeFactory {
public:
    std::shared_ptr<Lexeme> create(const std::string& text) const override {
        if (!Operator::exists(text, Operator::OperatorType::Binary))
            throw LexerException("Неизвестный бинарный оператор: " + text);
        return std::make_shared<BinaryOperator>(text);
    }
};



#endif // BINARYOPERATORFACTORY_H
