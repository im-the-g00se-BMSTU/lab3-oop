#include "expressioneditor.h"
#include "binaryoperator.h"
#include "unaryoperator.h"

ExpressionEditor::ExpressionEditor() : state(EditorState::Editing) {}

void ExpressionEditor::clear() {
    lexemes.clear();
    state = EditorState::Editing;
}

bool ExpressionEditor::empty() const {
    return lexemes.empty();
}

const std::vector<std::shared_ptr<Lexeme>>& ExpressionEditor::getLexemes() const {
    return lexemes;
}

Lexeme* ExpressionEditor::getLastLexeme() const {
    Lexeme* result = nullptr;
    if (!this->empty())
        result = lexemes.back().get();
    return result;
}

NumberLexeme* ExpressionEditor::getLastNumber() const {
    NumberLexeme* result = nullptr;
    Lexeme* last = getLastLexeme();
    if (last)
        result = dynamic_cast<NumberLexeme*>(last);
    return result;
}

std::string ExpressionEditor::transformToString() const {
    std::string result;
    for(size_t i = 0; i < lexemes.size(); ++i)
        result += lexemes[i]->text();
    return result;
}

void ExpressionEditor::replaceWithSingleNumber(const std::string& value) {
    lexemes.clear();
    lexemes.push_back(factoryManager.create(LexemeKind::Number, value));
}

void ExpressionEditor::setResult(const std::string& value) {
    replaceWithSingleNumber(value);
    state = EditorState::ResultShown;
}

void ExpressionEditor::appendDigit(char digit) {
    if (state == EditorState::ResultShown)
        clear();
    NumberLexeme* number = getLastNumber();
    if (number && number->canAppendDigit())
        number->appendDigit(digit);
    else {
        std::string text(1, digit);
        std::shared_ptr<Lexeme> lexeme = factoryManager.create(LexemeKind::Number, text);
        Lexeme* last = getLastLexeme();
        if (lexeme->canBePlacedAfter(last)) {
            lexemes.push_back(lexeme);
            state = EditorState::Editing;
        }
    }
}

void ExpressionEditor::appendDot() {
    NumberLexeme* number = nullptr;
    if (state == EditorState::ResultShown)
        clear();
    number = getLastNumber();
    if (number && number->canAppendDot())
            number->appendDot();
    else {
        Lexeme* lexeme = getLastLexeme();
        if (!lexeme || typeid(*lexeme) == typeid(BinaryOperator) || typeid(*lexeme) == typeid(UnaryOperator) ||
            typeid(*lexeme) == typeid(LeftParenLexeme))
            lexemes.push_back(factoryManager.create(LexemeKind::Number, "0."));
    }
}

bool ExpressionEditor::hasOpenParen() const {
    int balance = 0;
    for(std::size_t i = 0; i < lexemes.size(); ++i) {
        if (typeid(*lexemes[i]) == typeid(LeftParenLexeme))
            ++balance;
        else if (typeid(*lexemes[i]) == typeid(RightParenLexeme))
            --balance;
    }
    return balance > 0;
}

bool ExpressionEditor::lastLexemeCanCloseParen() const {
    const Lexeme* last = getLastLexeme();
    return last && (typeid(*last) == typeid(NumberLexeme) || typeid(*last) == typeid(RightParenLexeme));
}

bool ExpressionEditor::shouldUseUnaryOperator(const std::string& text) const {
    const Lexeme* last = getLastLexeme();
    return text == "-" && (!last || typeid(*last) == typeid(LeftParenLexeme) || typeid(*last) == typeid(BinaryOperator));
}

void ExpressionEditor::appendLexeme(LexemeKind kind, const std::string& text) {
    std::shared_ptr<Lexeme> lexeme;
    if (kind != LexemeKind::BinaryOperator && state == EditorState::ResultShown)
        clear();
    Lexeme* last = getLastLexeme();
    lexeme = factoryManager.create(kind, text);
    if (lexeme->canBePlacedAfter(last)) {
        lexemes.push_back(lexeme);
        state = EditorState::Editing;
    }
}

void ExpressionEditor::appendBinaryOperator(const std::string& text) {
    appendLexeme(LexemeKind::BinaryOperator, text);
}

void ExpressionEditor::appendUnaryOperator(const std::string& text) {
    appendLexeme(LexemeKind::UnaryOperator, text);
}

void ExpressionEditor::appendOperator(const std::string& text) {
    if (shouldUseUnaryOperator(text))
        appendUnaryOperator(text);
    else
        appendBinaryOperator(text);
}

void ExpressionEditor::appendFunction(const std::string& text) {
    if (state == EditorState::ResultShown && !empty())
        wrapExpression(text);
    else
        appendLexeme(LexemeKind::Function, text);
}

void ExpressionEditor::appendLeftParen() {
    appendLexeme(LexemeKind::LeftParen, "(");
}

void ExpressionEditor::appendRightParen() {
    Lexeme* last = getLastLexeme();
    if (hasOpenParen() && lastLexemeCanCloseParen()) {
        std::shared_ptr<Lexeme> lexeme = factoryManager.create(LexemeKind::RightParen, ")");
        if (lexeme->canBePlacedAfter(last)) {
                lexemes.push_back(lexeme);
                state = EditorState::Editing;
            }
        }
}

void ExpressionEditor::wrapExpression(const std::string& text) {
    std::vector<std::shared_ptr<Lexeme>> wrapped;
    wrapped.push_back(factoryManager.create(LexemeKind::Function, text));
    wrapped.push_back(factoryManager.create(LexemeKind::LeftParen, "("));
    for (size_t i = 0; i < lexemes.size(); ++i)
        wrapped.push_back(lexemes[i]);
    wrapped.push_back(factoryManager.create(LexemeKind::RightParen, ")"));
    lexemes = wrapped;
    state = EditorState::Editing;
}

bool ExpressionEditor::canEvaluate() const {
    const Lexeme* last = getLastLexeme();
    return !empty() && !hasOpenParen() && (typeid(*last) == typeid(NumberLexeme) || typeid(*last) == typeid(RightParenLexeme));
}

void ExpressionEditor::backspace() {
    if (state == EditorState::ResultShown)
        clear();
    else if (!lexemes.empty()) {
        NumberLexeme* number = getLastNumber();
        if (!number)
            lexemes.pop_back();
        else if (number && !number->removeLastChar())
            lexemes.pop_back();
    }
    state = EditorState::Editing;
}

std::vector<std::shared_ptr<Lexeme>> ExpressionEditor::cloneLexemes(const std::vector<std::shared_ptr<Lexeme>>& source) const {
    std::vector<std::shared_ptr<Lexeme>> result;
    result.reserve(source.size());
    for (std::size_t i = 0; i < source.size(); ++i)
        result.push_back(source[i]->clone());
    return result;
}

ExpressionEditor::State ExpressionEditor::saveState() const {
    State result = {.editorState = state};
    result.lexemes = cloneLexemes(lexemes);
    return result;
}

void ExpressionEditor::restoreState(const State& savedState) {
    lexemes = cloneLexemes(savedState.lexemes);
    state = savedState.editorState;
}

void ExpressionEditor::restoreState(State&& savedState) {
    lexemes = std::move(savedState.lexemes);
    state = savedState.editorState;
}