#include "expression_editor.h"

ExpressionEditor::ExpressionEditor()
    : mode(EditorMode::Editing) {}

void ExpressionEditor::clear() {
    lexemes.clear();
    mode = EditorMode::Editing;
}

bool ExpressionEditor::empty() const {
    return lexemes.empty();
}

const std::vector<std::shared_ptr<Lexeme>>& ExpressionEditor::getLexemes() const {
    return lexemes;
}

Lexeme* ExpressionEditor::lastLexeme() const {
    Lexeme* result = nullptr;
    if (!empty())
        result = lexemes.back().get();
    return result;
}

NumberLexeme* ExpressionEditor::lastNumber() const {
    NumberLexeme* result = nullptr;
    Lexeme* lexeme = lastLexeme();
    if (lexeme)
        result = dynamic_cast<NumberLexeme*>(lexeme);
    return result;
}

std::string ExpressionEditor::transformToString() const {
    std::string result;
    for (const std::shared_ptr<Lexeme>& lexeme : lexemes)
        result += lexeme->text();
    return result;
}

void ExpressionEditor::replaceWithSingleNumber(const std::string& value) {
    lexemes.clear();
    lexemes.push_back(lexemeFactory.create(LexemeKind::Number, value));
}

void ExpressionEditor::setResult(const std::string& value) {
    replaceWithSingleNumber(value);
    mode = EditorMode::ResultShown;
}

void ExpressionEditor::appendDigit(char digit) {
    if (mode == EditorMode::ResultShown)
        clear();
    NumberLexeme* number = lastNumber();
    if (number)
        number->appendDigit(digit);
    else
        appendLexeme(LexemeKind::Number, std::string(1, digit));
}

void ExpressionEditor::appendDot() {
    if (mode == EditorMode::ResultShown)
        clear();
    NumberLexeme* number = lastNumber();
    if (number)
        number->appendDot();
    else
        appendLexeme(LexemeKind::Number, "0.");
}

bool ExpressionEditor::hasOpenParen() const {
    int balance = 0;
    for (const std::shared_ptr<Lexeme>& lexeme : lexemes) {
        if (typeid(*lexeme) == typeid(LeftParenLexeme))
            ++balance;
        else if (typeid(*lexeme) == typeid(RightParenLexeme))
            --balance;
    }
    return balance > 0;
}

bool ExpressionEditor::lastLexemeCanCloseParen() const {
    const Lexeme* lexeme = lastLexeme();
    return lexeme && (typeid(*lexeme) == typeid(NumberLexeme) ||
                      typeid(*lexeme) == typeid(RightParenLexeme));
}

bool ExpressionEditor::shouldUseUnaryOperator(const std::string& text) const {
    const Lexeme* lexeme = lastLexeme();
    return text == "-" && (!lexeme || typeid(*lexeme) == typeid(LeftParenLexeme) ||
                           typeid(*lexeme) == typeid(BinaryOperator));
}

void ExpressionEditor::appendLexeme(LexemeKind kind, const std::string& text) {
    if (kind != LexemeKind::BinaryOperator && mode == EditorMode::ResultShown)
        clear();
    std::shared_ptr<Lexeme> lexeme = lexemeFactory.create(kind, text);
    Lexeme* previous = lastLexeme();
    if (lexeme->canBePlacedAfter(previous)) {
        lexemes.push_back(lexeme);
        mode = EditorMode::Editing;
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

void ExpressionEditor::appendLeftParen() {
    appendLexeme(LexemeKind::LeftParen, "(");
}

void ExpressionEditor::appendRightParen() {
    Lexeme* previous = lastLexeme();
    if (hasOpenParen() && lastLexemeCanCloseParen()) {
        std::shared_ptr<Lexeme> lexeme = lexemeFactory.create(LexemeKind::RightParen, ")");
        if (lexeme->canBePlacedAfter(previous)) {
            lexemes.push_back(lexeme);
            mode = EditorMode::Editing;
        }
    }
}

bool ExpressionEditor::canEvaluate() const {
    const Lexeme* lexeme = lastLexeme();
    return !empty() && !hasOpenParen() &&
           (typeid(*lexeme) == typeid(NumberLexeme) ||
            typeid(*lexeme) == typeid(RightParenLexeme));
}

void ExpressionEditor::backspace() {
    if (mode == EditorMode::ResultShown)
        clear();
    else if (!lexemes.empty()) {
        NumberLexeme* number = lastNumber();
        if (!number || !number->removeLastChar())
            lexemes.pop_back();
    }
    mode = EditorMode::Editing;
}
