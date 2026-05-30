#ifndef EXPRESSION_CALCULATOR_H
#define EXPRESSION_CALCULATOR_H

#include "binary_operator.h"
#include "constants.h"
#include "exceptions.h"
#include "math_operator.h"
#include "number_lexeme.h"
#include "paren_lexeme.h"
#include "unary_operator.h"

#include <memory>
#include <stack>
#include <vector>

class ExpressionCalculator {
public:
    std::vector<std::shared_ptr<Lexeme>> translateToRpn(const std::vector<std::shared_ptr<Lexeme>>& lexemes);
    double evaluate(const std::vector<std::shared_ptr<Lexeme>>& rpn);

private:
    Lexeme::OperatorPriority priority(const std::shared_ptr<Lexeme>& lexeme) const;
    void appendRemainingOperators(std::vector<std::shared_ptr<Lexeme>>& output,
                                  std::stack<std::shared_ptr<Lexeme>>& operators) const;
    void handleRightParen(std::vector<std::shared_ptr<Lexeme>>& output,
                          std::stack<std::shared_ptr<Lexeme>>& operators) const;
    void handleOperator(const std::shared_ptr<Lexeme>& lexeme,
                        std::vector<std::shared_ptr<Lexeme>>& output,
                        std::stack<std::shared_ptr<Lexeme>>& operators) const;
};

#endif // EXPRESSION_CALCULATOR_H
