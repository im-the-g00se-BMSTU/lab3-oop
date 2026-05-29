#ifndef EXPRESSIONEDITOR_H
#define EXPRESSIONEDITOR_H

#include "manager.h"
#include "numberlexeme.h"
#include <memory>
#include <string>
#include <vector>
#include "parenlexeme.h"

enum class EditorState {
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
    void appendBinaryOperator(const std::string& text);
    void appendUnaryOperator(const std::string& text);
    void appendOperator(const std::string& text);
    void appendFunction(const std::string& text);
    void appendLeftParen();
    void appendRightParen();
    void setResult(const std::string& value);
    bool empty() const;
    bool canEvaluate() const;
    std::string transformToString() const;
    const std::vector<std::shared_ptr<Lexeme>>& getLexemes() const;
    struct State {
        std::vector<std::shared_ptr<Lexeme>> lexemes;
        EditorState editorState;

        bool equals(const State& other) const {
            bool result = editorState == other.editorState && lexemes.size() == other.lexemes.size();
            for (size_t i = 0; i < lexemes.size() && result; ++i)
                result = lexemes[i]->isEqual(*other.lexemes[i]);
            return result;
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
    void restoreState(State&& savedState);

private:
    void appendLexeme(LexemeKind kind, const std::string& text);
    Lexeme* getLastLexeme() const;
    NumberLexeme* getLastNumber() const;
    bool hasOpenParen() const;
    bool lastLexemeCanCloseParen() const;
    bool shouldUseUnaryOperator(const std::string& text) const;
    void replaceWithSingleNumber(const std::string& value);
    void wrapExpression(const std::string& text);
    std::vector<std::shared_ptr<Lexeme>> cloneLexemes(const std::vector<std::shared_ptr<Lexeme>>& source) const;

    std::vector<std::shared_ptr<Lexeme>> lexemes;
    Manager factoryManager;
    EditorState state;
};

#endif // EXPRESSIONEDITOR_H
