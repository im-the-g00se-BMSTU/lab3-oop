#ifndef FACADE_H
#define FACADE_H

#include "expression_calculator.h"
#include "expression_editor.h"
#include "constants.h"

#include <cmath>
#include <exception>
#include <format>
#include <memory>
#include <vector>
#include <map>
#include <string>

enum class InputCommandType {
    Dot,
    LeftParen,
    RightParen,
    Clear,
    Backspace
};

class Facade {
public:
    Facade();

    void handleDigitInput(const std::string& text);
    void handleOperatorInput(const std::string& text);
    void handleCommandInput(InputCommandType type);
    void evaluateExpression();

    std::string getDisplayText() const;
    std::string getErrorText() const;
    void clearError();

private:
    std::string formatNumber(double value) const;
    void setError(const std::string& text);

    ExpressionEditor editor;
    ExpressionCalculator calculator;
    std::string errorText;
    std::map<InputCommandType, void (ExpressionEditor::*)()> commandHandlers;
};

#endif // FACADE_H
