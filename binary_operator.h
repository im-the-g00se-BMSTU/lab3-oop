#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "constants.h"
#include "math_operator.h"
#include "number_lexeme.h"

class BinaryOperator : public MathOperator {
public:
    explicit BinaryOperator(const std::string& text)
        : MathOperator(text, Type::Binary) {}

    bool canBePlacedAfter(const Lexeme* previous) const override {
        const MathOperator* op = dynamic_cast<const MathOperator*>(previous);
        return previous && (typeid(*previous) == typeid(NumberLexeme) ||
                            (op && op->type() == Type::RightParen));
    }

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<BinaryOperator>(*this);
    }

    double apply(double left, double right) const {
        if (!info().binaryOperation)
            throw MathException("Error: invalid binary operation");
        return info().binaryOperation(left, right);
    }
};

#endif // BINARY_OPERATOR_H
