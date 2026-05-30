#include "math_operator.h"

MathOperator::MathOperator(const std::string& text, Type type)
    : operatorText(text), operatorType(type) {}

std::string MathOperator::text() const {
    return operatorText;
}

MathOperator::Type MathOperator::type() const {
    return operatorType;
}

Lexeme::OperatorPriority MathOperator::priority() const {
    return info().priority;
}

bool MathOperator::exists(const std::string& text, Type type) {
    return operationTable().find({text, type}) != operationTable().end();
}

const MathOperator::Info& MathOperator::info() const {
    auto iterator = operationTable().find({operatorText, operatorType});
    if (iterator == operationTable().end())
        throw LexemeException("Unknown operator: " + operatorText);
    return iterator->second;
}

const std::map<MathOperator::Key, MathOperator::Info>& MathOperator::operationTable() {
    static const std::map<Key, Info> table = {
        {{"+", Type::Binary}, {OperatorPriority::Additive, Type::Binary, {}, [](double left, double right) {
             return left + right;
         }}},
        {{"-", Type::Binary}, {OperatorPriority::Additive, Type::Binary, {}, [](double left, double right) {
             return left - right;
         }}},
        {{"*", Type::Binary}, {OperatorPriority::Multiplicative, Type::Binary, {}, [](double left, double right) {
             return left * right;
         }}},
        {{"/", Type::Binary}, {OperatorPriority::Multiplicative, Type::Binary, {}, [](double left, double right) {
             if (std::abs(right) < Constants::Epsilon)
                 throw MathException("Error: division by zero");
             return left / right;
         }}},
        {{"-", Type::Unary}, {OperatorPriority::Unary, Type::Unary, [](double value) {
             return -value;
         }, {}}},
        {{"(", Type::LeftParen}, {OperatorPriority::None, Type::LeftParen, {}, {}}},
        {{")", Type::RightParen}, {OperatorPriority::None, Type::RightParen, {}, {}}}
    };
    return table;
}
