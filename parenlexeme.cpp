#include "parenlexeme.h"
#include "numberlexeme.h"
#include "functionlexeme.h"
#include "binaryoperator.h"
#include "unaryoperator.h"

#include <typeinfo>

bool LeftParenLexeme::canBePlacedAfter(const Lexeme* previous) const {
    return !previous || typeid(*previous) == typeid(FunctionLexeme) || typeid(*previous) == typeid(LeftParenLexeme) ||
           typeid(*previous) == typeid(BinaryOperator) || typeid(*previous) == typeid(UnaryOperator);
}

bool RightParenLexeme::canBePlacedAfter(const Lexeme* previous) const {
    return previous && (typeid(*previous) == typeid(NumberLexeme) || typeid(*previous) == typeid(RightParenLexeme));
}