#ifndef OPERATOR_H
#define OPERATOR_H

#include "lexeme.h"
#include "lexerexception.h"
#include "mathexception.h"

#include <cmath>
#include <functional>
#include <map>
#include <string>
#include <variant>

class Operator : public Lexeme {
public:
    enum class OperatorType {
        Binary,
        Unary,
        Function,
        LeftParen,
        RightParen
    };

    using UnaryOperation = std::function<double(double)>;
    using BinaryOperation = std::function<double(double, double)>;
    using Operation = std::variant<std::monostate, UnaryOperation, BinaryOperation>;

    struct OperatorInfo {
        OperatorPriority priority;
        OperatorType type;
        Operation operation;
    };

    Operator(const std::string& text, OperatorType type) : operatorText(text), operatorType(type) {}

    std::string text() const override {
        return operatorText;
    }

    OperatorType type() const {
        return operatorType;
    }

    OperatorPriority getPriority() const {
        return getInfo().priority;
    }

    static bool exists(const std::string& text, OperatorType type) {
        return operatorTable().find({text, type}) != operatorTable().end();
    }
protected:
    const OperatorInfo& getInfo() const {
        auto iterator = operatorTable().find({operatorText, operatorType});
        if (iterator == operatorTable().end())
            throw LexerException("Неизвестная операторная лексема: " + operatorText);
        return iterator->second;
    }
private:
    using OperatorKey = std::pair<std::string, OperatorType>;
    std::string operatorText;
    OperatorType operatorType;
    static const std::map<OperatorKey, OperatorInfo>& operatorTable();
};

#endif // OPERATOR_H
