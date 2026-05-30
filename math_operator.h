#ifndef MATH_OPERATOR_H
#define MATH_OPERATOR_H

#include "lexeme.h"
#include "constants.h"
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

    LexemeKind kind() const override;
    std::string text() const override;
    OperatorPriority priority() const override;

protected:
    double applyBinaryOperation(double left, double right) const;
    double applyUnaryOperation(double value) const;

private:
    using BinaryOperation = std::function<double(double, double)>;
    using UnaryOperation = std::function<double(double)>;
    using PriorityKey = std::pair<std::string, Type>;

    void validateOperator() const;
    static double add(double left, double right);
    static double subtract(double left, double right);
    static double multiply(double left, double right);
    static double divide(double left, double right);
    static double negate(double value);

    std::string operatorText;
    Type operatorType;
    std::map<std::string, BinaryOperation> binaryOperations;
    std::map<std::string, UnaryOperation> unaryOperations;
    std::map<PriorityKey, OperatorPriority> priorities;
};

#endif // MATH_OPERATOR_H
