#include "number_lexeme.h"

NumberLexeme::NumberLexeme(const std::string& value)
    : numberText(value) {}

std::string NumberLexeme::text() const {
    return numberText;
}

std::shared_ptr<Lexeme> NumberLexeme::clone() const {
    return std::make_shared<NumberLexeme>(*this);
}

bool NumberLexeme::canBePlacedAfter(const Lexeme* previous) const {
    const MathOperator* op = dynamic_cast<const MathOperator*>(previous);
    return !previous || (op && (op->type() == MathOperator::Type::LeftParen ||
                                op->type() == MathOperator::Type::Binary ||
                                op->type() == MathOperator::Type::Unary));
}

void NumberLexeme::evaluate(std::stack<double>& values) const {
    values.push(std::stod(numberText));
}

bool NumberLexeme::canAppendDigit() const {
    return numberText.size() < Constants::MaxNumberLength;
}

void NumberLexeme::appendDigit(char digit) {
    if (canAppendDigit())
        numberText += digit;
}

bool NumberLexeme::canAppendDot() const {
    return numberText.find('.') == std::string::npos &&
           numberText.size() < Constants::MaxNumberLength;
}

void NumberLexeme::appendDot() {
    if (numberText.empty())
        numberText = "0.";
    else if (canAppendDot())
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
