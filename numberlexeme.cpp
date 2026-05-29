#include "numberlexeme.h"
#include "parenlexeme.h"
#include "binaryoperator.h"
#include "unaryoperator.h"

NumberLexeme::NumberLexeme(const std::string& value) : value(value) {}

std::string NumberLexeme::text() const {
    return value;
}

std::shared_ptr<Lexeme> NumberLexeme::clone() const {
    return std::make_shared<NumberLexeme>(*this);
}

bool NumberLexeme::canBePlacedAfter(const Lexeme* previous) const {
    return !previous || typeid(*previous) == typeid(LeftParenLexeme) ||
           typeid(*previous) == typeid(BinaryOperator) ||
           typeid(*previous) == typeid(UnaryOperator);
}
void NumberLexeme::appendDigit(char digit) {
    value += digit;
}

bool NumberLexeme::canAppendDigit() const {
    return value.size() < MAX_LENGTH;
}

bool NumberLexeme::canAppendDot() const {
    return value.find('.') == std::string::npos && value.size() < MAX_LENGTH;
}

void NumberLexeme::appendDot() {
    if (value.empty())
        value = "0.";
    else if (canAppendDot())
        value += '.';
}

const std::string& NumberLexeme::getValue() const {
    return value;
}

bool NumberLexeme::removeLastChar() {
    if (!value.empty())
        value.pop_back();
    return !value.empty();
}
