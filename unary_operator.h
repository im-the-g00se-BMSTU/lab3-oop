#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include "exceptions.h"
#include "math_operator.h"

class UnaryOperator : public MathOperator {
public:
    explicit UnaryOperator(const std::string& text)
        : MathOperator(text, Type::Unary) {}

    bool canBePlacedAfter(const Lexeme* previous) const override {
        return !previous || previous->type() == LexemeType::LeftParen ||
               previous->type() == LexemeType::BinaryOperator;
    }

    double apply(double value) const {
        return applyUnaryOperation(value);
    }

    void evaluate(std::stack<double>& values) const override {
        if (values.empty())
            throw MathException("Error: not enough arguments for unary operator");
        double value = values.top();
        values.pop();
        values.push(apply(value));
    }
};

#endif // UNARY_OPERATOR_H
