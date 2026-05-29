#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <vector>
#include <stack>
#include <memory>

#include "lexeme.h"
#include "numberlexeme.h"
#include "binaryoperator.h"
#include "unaryoperator.h"
#include "functionlexeme.h"
#include "lexerexception.h"
#include "mathexception.h"

class ShuntingYard {
public:
    std::vector<std::shared_ptr<Lexeme>> translateToRPN(const std::vector<std::shared_ptr<Lexeme>>& lexemes);
    double evaluate(const std::vector<std::shared_ptr<Lexeme>>& rpn);
private:
    Lexeme::OperatorPriority checkPriority(const std::shared_ptr<Lexeme>& lexeme) const;
    void handleRightParen(std::vector<std::shared_ptr<Lexeme>>& output, std::stack<std::shared_ptr<Lexeme>>& ops) const;
    void handleOperator(const std::shared_ptr<Lexeme>& lexeme, std::vector<std::shared_ptr<Lexeme>>& output,
                        std::stack<std::shared_ptr<Lexeme>>& ops) const;
    double popOne(std::stack<double>& vals, const std::string& message) const;
};



#endif // SHUNTINGYARD_H
