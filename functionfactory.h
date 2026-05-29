#ifndef FUNCTIONFACTORY_H
#define FUNCTIONFACTORY_H

#include "ifactorylexeme.h"
#include "functionlexeme.h"
#include "lexerexception.h"

class FunctionFactory : public ILexemeFactory {
public:
    std::shared_ptr<Lexeme> create(const std::string& text) const override {
        if (!Operator::exists(text, Operator::OperatorType::Function))
            throw LexerException("Неизвестная функция: " + text);
        return std::make_shared<FunctionLexeme>(text);
    }
};


#endif // FUNCTIONFACTORY_H
