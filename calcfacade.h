#ifndef CALCFACADE_H
#define CALCFACADE_H

#include "expressioneditor.h"
#include "memory.h"
#include "shuntingyard.h"
#include <format>

class CalcFacade {
public:
    CalcFacade();

    void pressDigit(char digit);
    void pressDot();
    void pressOperator(const std::string& text);
    void pressFunction(const std::string& text);
    void pressInverse();
    void pressLeftParen();
    void pressRightParen();

    void pressClear();
    void pressBackspace();
    void pressEquals();

    void pressMemoryAdd();
    void pressMemorySub();
    void pressMemoryRecall();
    void pressMemoryClear();

    std::string getDisplayText() const;
    std::string getErrorText() const;
    void clearError();
    std::string formatNumber(double value) const;

    struct State {
        ExpressionEditor::State editorState;
        double memoryValue;
        std::string errorText;

        bool equals(const State& other) const {
            return editorState == other.editorState && std::abs(memoryValue - other.memoryValue) <= Lexeme::EPS && errorText == other.errorText;
        }
        bool operator==(const State& other) const {
            return this->equals(other);
        }
        bool operator!=(const State& other) const {
            return !(*this == other);
        }
    };

    State saveState() const;
    void restoreState(const State& state);
    void restoreState(State&& state);
private:
    bool containsSingleNumber() const;
    double currentSingleNumber() const;
    void setError(const std::string& text);

    ExpressionEditor editor;
    ShuntingYard shuntingYard;
    Memory memory;
    std::string errorText;
};
#endif // CALCFACADE_H
