#include "expression_calculator.h"

std::vector<std::shared_ptr<Lexeme>> ExpressionCalculator::translateToRpn(
    const std::vector<std::shared_ptr<Lexeme>>& lexemes) {
    std::vector<std::shared_ptr<Lexeme>> output;
    std::stack<std::shared_ptr<Lexeme>> operators;
    for (const std::shared_ptr<Lexeme>& lexeme : lexemes) {
        if (lexeme->type() == LexemeType::Number)
            output.push_back(lexeme);
        else if (lexeme->type() == LexemeType::LeftParen)
            operators.push(lexeme);
        else if (lexeme->type() == LexemeType::RightParen)
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
        if (operators.top()->type() == LexemeType::LeftParen)
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
        if (operators.top()->type() == LexemeType::LeftParen)
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
    while (!operators.empty() && operators.top()->type() != LexemeType::LeftParen &&
           operators.top()->priority() <= lexeme->priority()) {
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
