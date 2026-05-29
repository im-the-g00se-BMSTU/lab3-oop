#include "calcfacade.h"

CalcFacade::CalcFacade() : errorText("") {}

void CalcFacade::pressDigit(char digit) {
    clearError();
    editor.appendDigit(digit);
}

void CalcFacade::pressDot() {
    clearError();
    editor.appendDot();
}

void CalcFacade::pressOperator(const std::string& text) {
    clearError();
    editor.appendOperator(text);
}

void CalcFacade::pressFunction(const std::string& text) {
    clearError();
    editor.appendFunction(text);
}

void CalcFacade::pressLeftParen() {
    clearError();
    editor.appendLeftParen();
}

void CalcFacade::pressRightParen() {
    clearError();
    editor.appendRightParen();
}

void CalcFacade::pressClear() {
    editor.clear();
    clearError();
}

void CalcFacade::pressBackspace() {
    editor.backspace();
    clearError();
}

void CalcFacade::pressEquals() {
    clearError();
    try {
        if (!editor.canEvaluate())
            setError("Невозможно вычислить выражение");
        else {
            std::vector<std::shared_ptr<Lexeme>> rpn = shuntingYard.translateToRPN(editor.getLexemes());
            double result = shuntingYard.evaluate(rpn);
            editor.setResult(formatNumber(result));
        }
    }
    catch (const LexerException& exception) {
        setError(exception.what());
    }
    catch (const MathException& exception) {
        setError(exception.what());
    }
}

void CalcFacade::pressMemoryAdd() {
    clearError();
    try {
        if (!containsSingleNumber())
            setError("Невозможно сохранить выражение в память");
        else
            memory.add(currentSingleNumber());
    }
    catch (const std::exception& exception) {
        setError(exception.what());
    }
}

void CalcFacade::pressMemorySub() {
    clearError();
    try {
        if (!containsSingleNumber())
            setError("Невозможно сохранить выражение в память");
        else
            memory.sub(currentSingleNumber());
    }
    catch (const std::exception& exception) {
        setError(exception.what());
    }
}

void CalcFacade::pressMemoryRecall() {
    clearError();
    editor.setResult(formatNumber(memory.recall()));
}

void CalcFacade::pressMemoryClear() {
    clearError();
    memory.clear();
}

std::string CalcFacade::getDisplayText() const {
    return editor.transformToString();
}

std::string CalcFacade::getErrorText() const {
    return errorText;
}

void CalcFacade::clearError() {
    errorText.clear();
}

bool CalcFacade::containsSingleNumber() const {
    const std::vector<std::shared_ptr<Lexeme>>& lexemes = editor.getLexemes();
    return lexemes.size() == 1 && typeid(*lexemes[0]) == typeid(NumberLexeme);
}

double CalcFacade::currentSingleNumber() const {
    const std::vector<std::shared_ptr<Lexeme>>& lexemes = editor.getLexemes();
    const NumberLexeme* number = dynamic_cast<const NumberLexeme*>(lexemes[0].get());
    return std::stod(number->getValue());
}

void CalcFacade::setError(const std::string& text) {
    errorText = text;
}

CalcFacade::State CalcFacade::saveState() const {
    State result;
    result.editorState = editor.saveState();
    result.memoryValue = memory.getValue();
    result.errorText = errorText;
    return result;
}

void CalcFacade::restoreState(const State& savedState) {
    editor.restoreState(savedState.editorState);
    memory.setValue(savedState.memoryValue);
    errorText = savedState.errorText;
}

void CalcFacade::restoreState(State&& savedState) {
    editor.restoreState(std::move(savedState.editorState));
    memory.setValue(savedState.memoryValue);
    errorText = std::move(savedState.errorText);
}

void CalcFacade::pressInverse() {
    clearError();

    try {
        if (!containsSingleNumber())
            setError("Невозможно применить 1/x к выражению");
        else if (std::abs(currentSingleNumber()) < Lexeme::EPS)
            throw MathException("Ошибка: Деление на ноль");
        else
            editor.setResult(formatNumber(1.0 / currentSingleNumber()));
    }
    catch (const MathException& exception) {
        setError(exception.what());
    }
}

std::string CalcFacade::formatNumber(double value) const {
    std::string result = "0";
    if (std::abs(value) >= Lexeme::EPS) {
        result = std::format("{:.12g}", value);
        if (result == "-0")
            result = "0";
    }
    return result;
}