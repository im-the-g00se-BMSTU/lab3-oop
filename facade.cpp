#include "facade.h"

void Facade::pressDigit(char digit) {
    clearError();
    editor.appendDigit(digit);
}

void Facade::pressDot() {
    clearError();
    editor.appendDot();
}

void Facade::pressOperator(const std::string& text) {
    clearError();
    editor.appendOperator(text);
}

void Facade::pressLeftParen() {
    clearError();
    editor.appendLeftParen();
}

void Facade::pressRightParen() {
    clearError();
    editor.appendRightParen();
}

void Facade::pressClear() {
    editor.clear();
    clearError();
}

void Facade::pressBackspace() {
    editor.backspace();
    clearError();
}

void Facade::pressEquals() {
    clearError();
    try {
        if (!editor.canEvaluate())
            setError("Cannot evaluate expression");
        else {
            std::vector<std::shared_ptr<Lexeme>> rpn = calculator.translateToRpn(editor.getLexemes());
            editor.setResult(formatNumber(calculator.evaluate(rpn)));
        }
    } catch (const LexemeException& exception) {
        setError(exception.what());
    } catch (const MathException& exception) {
        setError(exception.what());
    }
}

std::string Facade::getDisplayText() const {
    return editor.transformToString();
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

std::string Facade::formatNumber(double value) const {
    std::string result = "0";
    if (std::abs(value) >= Constants::Epsilon) {
        result = std::format("{:.{}g}", value, Constants::NumberFormatPrecision);
        if (result == "-0")
            result = "0";
    }
    return result;
}
