#include "shuntingyard.h"

Lexeme::OperatorPriority ShuntingYard::checkPriority(const std::shared_ptr<Lexeme>& lexeme) const {
    Lexeme::OperatorPriority result = Lexeme::OperatorPriority::NONE;
    Operator* operatorLexeme = dynamic_cast<Operator*>(lexeme.get());
    if (operatorLexeme)
        result = operatorLexeme->getPriority();
    return result;
}

std::vector<std::shared_ptr<Lexeme>> ShuntingYard::translateToRPN(const std::vector<std::shared_ptr<Lexeme>>& lexemes) {
    std::vector<std::shared_ptr<Lexeme>> output;
    std::stack<std::shared_ptr<Lexeme>> ops;
    for (const auto& lexeme : lexemes) {
        const Operator* op = dynamic_cast<const Operator*>(lexeme.get());
        if (typeid(*lexeme) == typeid(NumberLexeme))
            output.push_back(lexeme);
        else if (op->type() == Operator::OperatorType::Function || op->type() == Operator::OperatorType::LeftParen)
            ops.push(lexeme);
        else if (op->type() == Operator::OperatorType::RightParen)
            handleRightParen(output, ops);
        else
            handleOperator(lexeme, output, ops);
    }
    while (!ops.empty()) {
        if (typeid(*ops.top()) == typeid(LeftParenLexeme) || typeid(*ops.top()) == typeid(RightParenLexeme))
            throw LexerException("Ошибка: несогласованные скобки");
        output.push_back(ops.top());
        ops.pop();
    }
    return output;
}

void ShuntingYard::handleRightParen(std::vector<std::shared_ptr<Lexeme>>& output, std::stack<std::shared_ptr<Lexeme>>& ops) const {
    bool leftParenFound = false;
    while (!ops.empty() && !leftParenFound) {
        if (typeid(*ops.top()) == typeid(LeftParenLexeme)) {
            leftParenFound = true;
            ops.pop();
        }
        else {
            output.push_back(ops.top());
            ops.pop();
        }
    }
    if (!leftParenFound) {
        throw LexerException("Ошибка: несогласованные скобки");
    }
    if (!ops.empty() && typeid(*ops.top()) == typeid(FunctionLexeme)) {
        output.push_back(ops.top());
        ops.pop();
    }
}

void ShuntingYard::handleOperator(const std::shared_ptr<Lexeme>& lexeme, std::vector<std::shared_ptr<Lexeme>>& output,
                                  std::stack<std::shared_ptr<Lexeme>>& ops) const {
    while (!ops.empty() && typeid(*ops.top()) != typeid(LeftParenLexeme) && checkPriority(ops.top()) <= checkPriority(lexeme)){
        output.push_back(ops.top());
        ops.pop();
    }
    ops.push(lexeme);
}

double ShuntingYard::popOne(std::stack<double>& vals, const std::string& message) const {
    if (vals.empty())
        throw MathException(message);
    double result = vals.top();
    vals.pop();
    return result;
}

double ShuntingYard::evaluate(const std::vector<std::shared_ptr<Lexeme>>& rpn) {
    std::stack<double> vals;
    for (const auto& lexeme : rpn) {
        if (typeid(*lexeme) == typeid(NumberLexeme))
            vals.push(std::stod(dynamic_cast<const NumberLexeme*>(lexeme.get())->getValue()));
        else if (typeid(*lexeme) == typeid(FunctionLexeme)) {
            double value = popOne(vals, "Ошибка: Недостаточно аргументов для функции");
            vals.push(dynamic_cast<const FunctionLexeme*>(lexeme.get())->apply(value));
        }
        else if (typeid(*lexeme) == typeid(UnaryOperator)) {
            double value = popOne(vals, "Ошибка: Недостаточно аргументов для унарного оператора");
            vals.push(dynamic_cast<const UnaryOperator*>(lexeme.get())->apply(value));
        }
        else if (typeid(*lexeme) == typeid(BinaryOperator)) {
            if (vals.size() < 2)
                throw MathException("Ошибка: Недостаточно аргументов для бинарной операции");
            double right = vals.top();
            vals.pop();
            double left = vals.top();
            vals.pop();
            vals.push(dynamic_cast<const BinaryOperator*>(lexeme.get())->apply(left, right));
        }
    }
    if (vals.size() != 1)
        throw MathException("Ошибка в структуре выражения");
    return vals.top();
}