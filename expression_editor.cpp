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
    if (lexeme && lexeme->type() == LexemeType::Number)
        result = static_cast<NumberLexeme*>(lexeme);
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
    lexemes.push_back(lexemeFactory.create(LexemeType::Number, value));
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
        appendLexeme(LexemeType::Number, std::string(1, digit));
}

void ExpressionEditor::appendDot() {
    if (mode == EditorMode::ResultShown)
        clear();
    NumberLexeme* number = lastNumber();
    if (number)
        number->appendDot();
    else
        appendLexeme(LexemeType::Number, "0.");
}

bool ExpressionEditor::hasOpenParen() const {
    int balance = 0;
    for (const std::shared_ptr<Lexeme>& lexeme : lexemes) {
        if (lexeme->type() == LexemeType::LeftParen)
            ++balance;
        else if (lexeme->type() == LexemeType::RightParen)
            --balance;
    }
    return balance > 0;
}

bool ExpressionEditor::lastLexemeCanCloseParen() const {
    const Lexeme* lexeme = lastLexeme();
    return lexeme && (lexeme->type() == LexemeType::Number ||
                      lexeme->type() == LexemeType::RightParen);
}

bool ExpressionEditor::shouldUseUnaryOperator(const std::string& text) const {
    const Lexeme* lexeme = lastLexeme();
    return text == "-" && (!lexeme || lexeme->type() == LexemeType::LeftParen ||
                           lexeme->type() == LexemeType::BinaryOperator);
}

void ExpressionEditor::appendLexeme(LexemeType kind, const std::string& text) {
    if (kind != LexemeType::BinaryOperator && mode == EditorMode::ResultShown)
        clear();
    std::shared_ptr<Lexeme> lexeme = lexemeFactory.create(kind, text);
    Lexeme* previous = lastLexeme();
    if (lexeme->canBePlacedAfter(previous)) {
        lexemes.push_back(lexeme);
        mode = EditorMode::Editing;
    }
}

void ExpressionEditor::appendBinaryOperator(const std::string& text) {
    appendLexeme(LexemeType::BinaryOperator, text);
}

void ExpressionEditor::appendUnaryOperator(const std::string& text) {
    appendLexeme(LexemeType::UnaryOperator, text);
}

void ExpressionEditor::appendOperator(const std::string& text) {
    if (shouldUseUnaryOperator(text))
        appendUnaryOperator(text);
    else
        appendBinaryOperator(text);
}

void ExpressionEditor::appendLeftParen() {
    appendLexeme(LexemeType::LeftParen, "(");
}

void ExpressionEditor::appendRightParen() {
    Lexeme* previous = lastLexeme();
    if (hasOpenParen() && lastLexemeCanCloseParen()) {
        std::shared_ptr<Lexeme> lexeme = lexemeFactory.create(LexemeType::RightParen, ")");
        if (lexeme->canBePlacedAfter(previous)) {
            lexemes.push_back(lexeme);
            mode = EditorMode::Editing;
        }
    }
}

bool ExpressionEditor::canEvaluate() const {
    const Lexeme* lexeme = lastLexeme();
    return !empty() && !hasOpenParen() &&
           (lexeme->type() == LexemeType::Number ||
            lexeme->type() == LexemeType::RightParen);
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
