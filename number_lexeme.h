#ifndef NUMBER_LEXEME_H
#define NUMBER_LEXEME_H

#include "constants.h"
#include "lexeme.h"
#include "math_operator.h"

#include <string>

class NumberLexeme : public Lexeme {
public:
    explicit NumberLexeme(const std::string& value);

    std::string text() const override;
    std::shared_ptr<Lexeme> clone() const override;
    bool canBePlacedAfter(const Lexeme* previous) const override;
    void evaluate(std::stack<double>& values) const override;

    void appendDigit(char digit);
    void appendDot();
    const std::string& value() const;
    bool removeLastChar();

private:
    std::string numberText;
};

#endif // NUMBER_LEXEME_H
