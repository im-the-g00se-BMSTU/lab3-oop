#ifndef LEXEME_H
#define LEXEME_H
#include <string>

#include <memory>

class Lexeme {
public:
    static constexpr double EPS = 1e-12;

    enum class OperatorPriority {
        NONE = 0,
        FUNCTION = 2,
        UNARY = 3,
        MULTIPLICATIVE = 4,
        ADDITIVE = 5
    };
    virtual ~Lexeme() = default;
    virtual std::string text() const = 0;
    virtual std::shared_ptr<Lexeme> clone() const = 0;
    virtual bool canBePlacedAfter(const Lexeme* previous) const = 0;
    virtual bool isEqual(const Lexeme& other) const {
        return typeid(*this) == typeid(other) && this->text() == other.text();
    }
};
#endif // LEXEME_H
