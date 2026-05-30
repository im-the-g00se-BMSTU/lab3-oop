#ifndef FACADE_H
#define FACADE_H

#include "expression_calculator.h"
#include "expression_editor.h"
#include "constants.h"
#include "exceptions.h"

#include <cmath>
#include <format>
#include <memory>
#include <string>
#include <vector>

class Facade {
public:
    void pressDigit(char digit);
    void pressDot();
    void pressOperator(const std::string& text);
    void pressLeftParen();
    void pressRightParen();
    void pressClear();
    void pressBackspace();
    void pressEquals();

    std::string getDisplayText() const;
    std::string getErrorText() const;
    void clearError();

private:
    std::string formatNumber(double value) const;
    void setError(const std::string& text);

    ExpressionEditor editor;
    ExpressionCalculator calculator;
    std::string errorText;
};

#endif // FACADE_H
