#include "expression_calculator.h"

Lexeme::OperatorPriority ExpressionCalculator::priority(const std::shared_ptr<Lexeme>& lexeme) const {
    Lexeme::OperatorPriority result = Lexeme::OperatorPriority::None;
    const MathOperator* op = dynamic_cast<const MathOperator*>(lexeme.get());
    if (op)
        result = op->priority();
    return result;
}

std::vector<std::shared_ptr<Lexeme>> ExpressionCalculator::translateToRpn(
    const std::vector<std::shared_ptr<Lexeme>>& lexemes) {
    std::vector<std::shared_ptr<Lexeme>> output;
    std::stack<std::shared_ptr<Lexeme>> operators;
    for (const std::shared_ptr<Lexeme>& lexeme : lexemes) {
        const MathOperator* op = dynamic_cast<const MathOperator*>(lexeme.get());
        if (typeid(*lexeme) == typeid(NumberLexeme))
            output.push_back(lexeme);
        else if (op->type() == MathOperator::Type::LeftParen)
            operators.push(lexeme);
        else if (op->type() == MathOperator::Type::RightParen)
            handleRightParen(output, operators);
        else
            handleOperator(lexeme, output, operators);
    }
    appendRemainingOperators(output, operators);
    return output;
}

void ExpressionCalculator::appendRemainingOperators(
    std::vector<std::shared_ptr<Lexeme>>& output,
    std::stack<std::shared_ptr<Lexeme>>& operators) const {
    while (!operators.empty()) {
        if (typeid(*operators.top()) == typeid(LeftParenLexeme))
            throw LexerException("Error: mismatched parentheses");
        output.push_back(operators.top());
        operators.pop();
    }
}

void ExpressionCalculator::handleRightParen(
    std::vector<std::shared_ptr<Lexeme>>& output,
    std::stack<std::shared_ptr<Lexeme>>& operators) const {
    bool leftParenFound = false;
    while (!operators.empty() && !leftParenFound) {
        if (typeid(*operators.top()) == typeid(LeftParenLexeme))
            leftParenFound = true;
        else
            output.push_back(operators.top());
        operators.pop();
    }
    if (!leftParenFound)
        throw LexerException("Error: mismatched parentheses");
}

void ExpressionCalculator::handleOperator(const std::shared_ptr<Lexeme>& lexeme,
                                          std::vector<std::shared_ptr<Lexeme>>& output,
                                          std::stack<std::shared_ptr<Lexeme>>& operators) const {
    while (!operators.empty() && typeid(*operators.top()) != typeid(LeftParenLexeme) &&
           priority(operators.top()) <= priority(lexeme)) {
        output.push_back(operators.top());
        operators.pop();
    }
    operators.push(lexeme);
}

double ExpressionCalculator::popValue(std::stack<double>& values, const std::string& message) const {
    if (values.empty())
        throw MathException(message);
    double result = values.top();
    values.pop();
    return result;
}

void ExpressionCalculator::evaluateLexeme(const std::shared_ptr<Lexeme>& lexeme,
                                          std::stack<double>& values) const {
    if (typeid(*lexeme) == typeid(NumberLexeme))
        values.push(std::stod(dynamic_cast<const NumberLexeme*>(lexeme.get())->value()));
    else if (typeid(*lexeme) == typeid(UnaryOperator)) {
        double value = popValue(values, "Error: not enough arguments for unary operator");
        values.push(dynamic_cast<const UnaryOperator*>(lexeme.get())->apply(value));
    } else if (typeid(*lexeme) == typeid(BinaryOperator))
        evaluateBinaryOperator(*dynamic_cast<const BinaryOperator*>(lexeme.get()), values);
}

void ExpressionCalculator::evaluateBinaryOperator(const BinaryOperator& op,
                                                  std::stack<double>& values) const {
    if (values.size() < Constants::BinaryOperandCount)
        throw MathException("Error: not enough arguments for binary operator");
    double right = values.top();
    values.pop();
    double left = values.top();
    values.pop();
    values.push(op.apply(left, right));
}

double ExpressionCalculator::evaluate(const std::vector<std::shared_ptr<Lexeme>>& rpn) {
    std::stack<double> values;
    for (const std::shared_ptr<Lexeme>& lexeme : rpn)
        evaluateLexeme(lexeme, values);
    if (values.size() != 1)
        throw MathException("Error: invalid expression structure");
    return values.top();
}
