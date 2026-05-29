#include "operator.h"

const std::map<Operator::OperatorKey, Operator::OperatorInfo>& Operator::operatorTable() {
    static const std::map<OperatorKey, OperatorInfo> table = {
        {{"+", OperatorType::Binary}, {OperatorPriority::ADDITIVE, OperatorType::Binary,
                                       BinaryOperation([](double a, double b) { return a + b; })}},

        {{"-", OperatorType::Binary}, {OperatorPriority::ADDITIVE, OperatorType::Binary,
                                       BinaryOperation([](double a, double b) { return a - b; })}},

        {{"*", OperatorType::Binary}, {OperatorPriority::MULTIPLICATIVE, OperatorType::Binary,
                                       BinaryOperation([](double a, double b) { return a * b; })}},

        {{"/", OperatorType::Binary}, {OperatorPriority::MULTIPLICATIVE, OperatorType::Binary,
                                       BinaryOperation([](double a, double b) {
                                           if (std::abs(b) < Lexeme::EPS)
                                               throw MathException("Ошибка: Деление на ноль");
                                           return a / b;
                                       })}},

        {{"-", OperatorType::Unary}, {OperatorPriority::UNARY, OperatorType::Unary,
                                      UnaryOperation([](double value) { return -value; })}},

        {{"sin", OperatorType::Function}, {OperatorPriority::FUNCTION, OperatorType::Function,
                                           UnaryOperation([](double value) { return std::sin(value); })}},

        {{"cos", OperatorType::Function}, {OperatorPriority::FUNCTION, OperatorType::Function,
                                           UnaryOperation([](double value) { return std::cos(value); })}},

        {{"tg", OperatorType::Function}, {OperatorPriority::FUNCTION, OperatorType::Function,
                                          UnaryOperation([](double value) {
                                              if (std::abs(std::cos(value)) < Lexeme::EPS)
                                                  throw MathException("Ошибка: Тангенс не определён");
                                              return std::tan(value);
                                          })}},

        {{"ctg", OperatorType::Function}, {OperatorPriority::FUNCTION, OperatorType::Function,
                                           UnaryOperation([](double value) {
                                               if (std::abs(std::sin(value)) < Lexeme::EPS)
                                                   throw MathException("Ошибка: Котангенс не определён");
                                               return std::cos(value) / std::sin(value);
                                           })}},

        {{"√", OperatorType::Function}, {OperatorPriority::FUNCTION, OperatorType::Function,
                                         UnaryOperation([](double value) {
                                             if (value < 0)
                                                 throw MathException("Ошибка: Корень из отрицательного числа");
                                             return std::sqrt(value);
                                         })}},

        {{"(", OperatorType::LeftParen}, {OperatorPriority::NONE, OperatorType::LeftParen, std::monostate{}}},
        {{")", OperatorType::RightParen}, {OperatorPriority::NONE, OperatorType::RightParen, std::monostate{}}}
    };
    return table;
}