#ifndef FUNCTIONLEXEME_H
#define FUNCTIONLEXEME_H

#include "operator.h"
#include <functional>
#include "parenlexeme.h"
#include "binaryoperator.h"
#include "unaryoperator.h"

class FunctionLexeme : public Operator {
public:
    explicit FunctionLexeme(const std::string& text) : Operator(text, OperatorType::Function) {}

    double apply(double value) const {
        const auto* operation = std::get_if<Operator::UnaryOperation>(&getInfo().operation);
        if (!operation)
            throw MathException("Ошибка: Неверная функция");
        return (*operation)(value);
    }

    bool canBePlacedAfter(const Lexeme* previous) const override {
        return !previous || typeid(*previous) == typeid(LeftParenLexeme) ||
               typeid(*previous) == typeid(BinaryOperator) || typeid(*previous) == typeid(UnaryOperator);
    }

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<FunctionLexeme>(*this);
    }
};

#endif // FUNCTIONLEXEME_H
