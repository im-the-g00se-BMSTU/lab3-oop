#ifndef MATH_OPERATOR_H
#define MATH_OPERATOR_H

#include "constants.h"
#include "lexeme.h"
#include "exceptions.h"

#include <cmath>
#include <functional>
#include <map>
#include <string>

class MathOperator : public Lexeme {
public:
    enum class Type {
        Binary,
        Unary,
        LeftParen,
        RightParen
    };

    MathOperator(const std::string& text, Type type);

    std::string text() const override;
    Type type() const;
    OperatorPriority priority() const;

protected:
    double applyBinaryOperation(double left, double right) const;
    double applyUnaryOperation(double value) const;

private:
    using BinaryOperation = std::function<double(double, double)>;
    using UnaryOperation = std::function<double(double)>;
    using PriorityKey = std::pair<std::string, Type>;

    void validateOperator() const;

    std::string operatorText;
    Type operatorType;
    std::map<std::string, BinaryOperation> binaryOperations;
    std::map<std::string, UnaryOperation> unaryOperations;
    std::map<PriorityKey, OperatorPriority> priorities;
};

#endif // MATH_OPERATOR_H
