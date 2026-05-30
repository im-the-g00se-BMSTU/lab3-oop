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
            throw LexemeException("Error: mismatched parentheses");
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
        throw LexemeException("Error: mismatched parentheses");
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

double ExpressionCalculator::evaluate(const std::vector<std::shared_ptr<Lexeme>>& rpn) {
    std::stack<double> values;
    for (const std::shared_ptr<Lexeme>& lexeme : rpn)
        lexeme->evaluate(values);
    if (values.size() != 1)
        throw MathException("Error: invalid expression structure");
    return values.top();
}
