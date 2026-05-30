#include "math_operator.h"

MathOperator::MathOperator(const std::string& text, Type type)
    : operatorText(text),
      operatorType(type),
      binaryOperations({
          {"+", [](double left, double right) { return left + right; }},
          {"-", [](double left, double right) { return left - right; }},
          {"*", [](double left, double right) { return left * right; }},
          {"/", [](double left, double right) {
               if (std::abs(right) < Constants::Epsilon)
                   throw MathException("Error: division by zero");
               return left / right;
           }}
      }),
      unaryOperations({
          {"-", [](double value) { return -value; }}
      }),
      priorities({
          {{"+", Type::Binary}, OperatorPriority::Additive},
          {{"-", Type::Binary}, OperatorPriority::Additive},
          {{"*", Type::Binary}, OperatorPriority::Multiplicative},
          {{"/", Type::Binary}, OperatorPriority::Multiplicative},
          {{"-", Type::Unary}, OperatorPriority::Unary},
          {{"(", Type::LeftParen}, OperatorPriority::None},
          {{")", Type::RightParen}, OperatorPriority::None}
      }) {
    validateOperator();
}

std::string MathOperator::text() const {
    return operatorText;
}

MathOperator::Type MathOperator::type() const {
    return operatorType;
}

Lexeme::OperatorPriority MathOperator::priority() const {
    auto iterator = priorities.find({operatorText, operatorType});
    return iterator->second;
}

void MathOperator::validateOperator() const {
    if (priorities.find({operatorText, operatorType}) == priorities.end())
        throw LexemeException("Unknown operator: " + operatorText);
}

double MathOperator::applyBinaryOperation(double left, double right) const {
    auto iterator = binaryOperations.find(operatorText);
    if (iterator == binaryOperations.end())
        throw MathException("Error: invalid binary operation");
    return iterator->second(left, right);
}

double MathOperator::applyUnaryOperation(double value) const {
    auto iterator = unaryOperations.find(operatorText);
    if (iterator == unaryOperations.end())
        throw MathException("Error: invalid unary operation");
    return iterator->second(value);
}
