#include "number_lexeme.h"

NumberLexeme::NumberLexeme(const std::string& value)
    : numberText(value) {}

LexemeType NumberLexeme::type() const {
    return LexemeType::Number;
}

std::string NumberLexeme::text() const {
    return numberText;
}

bool NumberLexeme::canBePlacedAfter(const Lexeme* previous) const {
    return !previous || previous->type() == LexemeType::LeftParen ||
           previous->type() == LexemeType::BinaryOperator ||
           previous->type() == LexemeType::UnaryOperator;
}

void NumberLexeme::evaluate(std::stack<double>& values) const {
    values.push(std::stod(numberText));
}

void NumberLexeme::appendDigit(char digit) {
    if (numberText.size() < Constants::MaxNumberLength)
        numberText += digit;
}

void NumberLexeme::appendDot() {
    if (numberText.empty())
        numberText = "0.";
    else if (numberText.find('.') == std::string::npos &&
             numberText.size() < Constants::MaxNumberLength)
        numberText += '.';
}

const std::string& NumberLexeme::value() const {
    return numberText;
}

bool NumberLexeme::removeLastChar() {
    if (!numberText.empty())
        numberText.pop_back();
    return !numberText.empty();
}
