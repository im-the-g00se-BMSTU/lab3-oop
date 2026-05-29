#ifndef NUMBERLEXEME_H
#define NUMBERLEXEME_H

#include "lexeme.h"
#include <string>

class NumberLexeme : public Lexeme {
public:
    explicit NumberLexeme(const std::string& value);
    bool canAppendDigit() const;
    std::string text() const override;
    std::shared_ptr<Lexeme> clone() const override;
    bool canBePlacedAfter(const Lexeme* previous) const override;
    void appendDigit(char digit);
    bool canAppendDot() const;
    void appendDot();
    const std::string& getValue() const;
    bool removeLastChar();

    static constexpr std::size_t MAX_LENGTH = 16;
private:
    std::string value;
};

#endif // NUMBERLEXEME_H
