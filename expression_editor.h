#ifndef EXPRESSION_EDITOR_H
#define EXPRESSION_EDITOR_H

#include "lexeme_factory.h"
#include "number_lexeme.h"

#include <memory>
#include <string>
#include <vector>

enum class EditorMode {
    Editing,
    ResultShown
};

class ExpressionEditor {
public:
    ExpressionEditor();

    void clear();
    void backspace();
    void appendDigit(char digit);
    void appendDot();
    void appendOperator(const std::string& text);
    void appendLeftParen();
    void appendRightParen();
    void setResult(const std::string& value);

    bool empty() const;
    bool canEvaluate() const;
    std::string transformToString() const;
    const std::vector<std::shared_ptr<Lexeme>>& getLexemes() const;

private:
    void appendBinaryOperator(const std::string& text);
    void appendUnaryOperator(const std::string& text);
    void appendLexeme(LexemeType kind, const std::string& text);
    void replaceWithSingleNumber(const std::string& value);

    Lexeme* lastLexeme() const;
    NumberLexeme* lastNumber() const;
    bool hasOpenParen() const;
    bool lastLexemeCanCloseParen() const;
    bool shouldUseUnaryOperator(const std::string& text) const;

    std::vector<std::shared_ptr<Lexeme>> lexemes;
    LexemeFactory lexemeFactory;
    EditorMode mode;
};

#endif // EXPRESSION_EDITOR_H
