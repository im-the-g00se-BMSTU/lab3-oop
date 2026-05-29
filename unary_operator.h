#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include "constants.h"
#include "math_operator.h"

class UnaryOperator : public MathOperator {
public:
    explicit UnaryOperator(const std::string& text)
        : MathOperator(text, Type::Unary) {}

    bool canBePlacedAfter(const Lexeme* previous) const override {
        const MathOperator* op = dynamic_cast<const MathOperator*>(previous);
        return !previous || (op && (op->type() == Type::LeftParen ||
                                    op->type() == Type::Binary));
    }

    std::shared_ptr<Lexeme> clone() const override {
        return std::make_shared<UnaryOperator>(*this);
    }

    double apply(double value) const {
        if (!info().unaryOperation)
            throw MathException("Error: invalid unary operation");
        return info().unaryOperation(value);
    }
};

#endif // UNARY_OPERATOR_H
