#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "constants.h"
#include "math_operator.h"
#include "number_lexeme.h"
#include "exceptions.h"

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
