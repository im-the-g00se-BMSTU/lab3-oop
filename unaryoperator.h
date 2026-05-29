#ifndef UNARYOPERATOR_H
#define UNARYOPERATOR_H

#include "operator.h"
#include <functional>
#include "parenlexeme.h"
#include "binaryoperator.h"

class UnaryOperator : public Operator {
public:
    explicit UnaryOperator(const std::string& text) : Operator(text, OperatorType::Unary) {}
    double apply(double value) const {
        const auto* operation = std::get_if<Operator::UnaryOperation>(&getInfo().operation);
        if (!operation)
            throw MathException("Ошибка: Неверная унарная операция");
        return (*operation)(value);
    }

    bool canBePlacedAfter(const Lexeme* previous) const override {
        return !previous || typeid(*previous) == typeid(LeftParenLexeme) || typeid(*previous) == typeid(BinaryOperator);
    }

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<UnaryOperator>(*this);
    }
};

#endif // UNARYOPERATOR_H
