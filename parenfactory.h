#ifndef PARENFACTORY_H
#define PARENFACTORY_H

#include "ifactorylexeme.h"
#include "parenlexeme.h"
#include "lexerexception.h"

class ParenFactory : public ILexemeFactory {
public:
    std::shared_ptr<Lexeme> create(const std::string& text) const override {
        std::shared_ptr<Lexeme> result;
        if (text == "(" && Operator::exists(text, Operator::OperatorType::LeftParen))
            result = std::make_shared<LeftParenLexeme>();
        else if (text == ")" && Operator::exists(text, Operator::OperatorType::RightParen))
            result = std::make_shared<RightParenLexeme>();
        else
            throw LexerException("Неизвестная скобка: " + text);
        return result;
    }
};
#endif // PARENFACTORY_H
