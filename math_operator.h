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

    using UnaryOperation = std::function<double(double)>;
    using BinaryOperation = std::function<double(double, double)>;

    struct Info {
        OperatorPriority priority;
        Type type;
        UnaryOperation unaryOperation;
        BinaryOperation binaryOperation;
    };

    MathOperator(const std::string& text, Type type);

    std::string text() const override;
    Type type() const;
    OperatorPriority priority() const;
    static bool exists(const std::string& text, Type type);

protected:
    const Info& info() const;

private:
    using Key = std::pair<std::string, Type>;

    static const std::map<Key, Info>& operationTable();

    std::string operatorText;
    Type operatorType;
};

#endif // MATH_OPERATOR_H
