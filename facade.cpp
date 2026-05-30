#include "facade.h"

Facade::Facade()
    : commandHandlers({
          {InputCommandType::Dot, &ExpressionEditor::appendDot},
          {InputCommandType::LeftParen, &ExpressionEditor::appendLeftParen},
          {InputCommandType::RightParen, &ExpressionEditor::appendRightParen},
          {InputCommandType::Clear, &ExpressionEditor::clear},
          {InputCommandType::Backspace, &ExpressionEditor::backspace}
      }) {}

void Facade::handleDigitInput(const std::string& text) {
    clearError();
    if (!text.empty())
        editor.appendDigit(text.front());
}

void Facade::handleOperatorInput(const std::string& text) {
    clearError();
    editor.appendOperator(text);
}

void Facade::handleCommandInput(InputCommandType type) {
    clearError();
    auto iterator = commandHandlers.find(type);
    if (iterator != commandHandlers.end())
        (editor.*iterator->second)();
}

void Facade::evaluateExpression() {
    try {
        if (!editor.canEvaluate())
            setError("Cannot evaluate expression");
        else {
            std::vector<std::shared_ptr<Lexeme>> rpn = calculator.translateToRpn(editor.getLexemes());
            editor.setResult(formatNumber(calculator.evaluate(rpn)));
        }
    } catch (const std::exception& exception) {
        setError(exception.what());
    }
}

std::string Facade::getDisplayText() const {
    return editor.transformToString();
}

std::string Facade::formatNumber(double value) const {
    std::string result = "0";
    if (std::abs(value) >= Constants::Epsilon) {
        result = std::format("{:.{}g}", value, Constants::NumberFormatPrecision);
        if (result == "-0")
            result = "0";
    }
    return result;
}

std::string Facade::getErrorText() const {
    return errorText;
}

void Facade::clearError() {
    errorText.clear();
}

void Facade::setError(const std::string& text) {
    errorText = text;
}
