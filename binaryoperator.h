#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include "mathexception.h"
#include <functional>
#include "operator.h"
#include "numberlexeme.h"
#include "parenlexeme.h"

class BinaryOperator : public Operator {
public:
    explicit BinaryOperator(const std::string& text) : Operator(text, OperatorType::Binary) {}

    bool canBePlacedAfter(const Lexeme* previous) const override {
        return previous &&
               (typeid(*previous) == typeid(NumberLexeme) ||
                typeid(*previous) == typeid(RightParenLexeme));
    }

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<BinaryOperator>(*this);
    }

    double apply(double first, double second) const {
        const auto* operation = std::get_if<Operator::BinaryOperation>(&getInfo().operation);
        if (!operation)
            throw MathException("Ошибка: Неверная бинарная операция");
        return (*operation)(first, second);
    }
};

#endif // BINARYOPERATOR_H
