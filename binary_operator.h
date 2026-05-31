#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "constants.h"
#include "exceptions.h"
#include "math_operator.h"

class BinaryOperator : public MathOperator {
public:
    explicit BinaryOperator(const std::string& text)
        : MathOperator(text, Type::Binary) {}

    bool canBePlacedAfter(const Lexeme* previous) const override {
        return previous && (previous->type() == LexemeType::Number ||
                            previous->type() == LexemeType::RightParen);
    }

    double apply(double left, double right) const {
        return applyBinaryOperation(left, right);
    }

    void evaluate(std::stack<double>& values) const override {
        if (values.size() < Constants::BinaryOperandCount)
            throw MathException("Error: not enough arguments for binary operator");
        double right = values.top();
        values.pop();
        double left = values.top();
        values.pop();
        values.push(apply(left, right));
    }
};

#endif // BINARY_OPERATOR_H
