#ifndef LEXEME_FACTORY_H
#define LEXEME_FACTORY_H

#include "binary_operator.h"
#include "exceptions.h"
#include "number_lexeme.h"
#include "paren_lexeme.h"
#include "unary_operator.h"

#include <functional>
#include <map>
#include <memory>
#include <string>

class LexemeFactory {
public:
    LexemeFactory()
        : lexemeCreators({
              {LexemeType::Number, createNumber},
              {LexemeType::BinaryOperator, createBinaryOperator},
              {LexemeType::UnaryOperator, createUnaryOperator},
              {LexemeType::LeftParen, createLeftParen},
              {LexemeType::RightParen, createRightParen}
          }) {}

    std::shared_ptr<Lexeme> create(LexemeType kind, const std::string& text) const {
        auto iterator = lexemeCreators.find(kind);
        if (iterator == lexemeCreators.end())
            throw LexemeException("Suitable lexeme factory was not found");
        std::shared_ptr<Lexeme> result = iterator->second(text);
        return result;
    }

private:
    using Creator = std::function<std::shared_ptr<Lexeme>(const std::string&)>;
    std::map<LexemeType, Creator> lexemeCreators;

    static std::shared_ptr<Lexeme> createNumber(const std::string& text) {
        return std::make_shared<NumberLexeme>(text);
    }

    static std::shared_ptr<Lexeme> createBinaryOperator(const std::string& text) {
        return std::make_shared<BinaryOperator>(text);
    }

    static std::shared_ptr<Lexeme> createUnaryOperator(const std::string& text) {
        return std::make_shared<UnaryOperator>(text);
    }

    static std::shared_ptr<Lexeme> createLeftParen(const std::string& text) {
        if (text != "(")
            throw LexemeException("Unknown left parenthesis: " + text);
        return std::make_shared<LeftParenLexeme>();
    }

    static std::shared_ptr<Lexeme> createRightParen(const std::string& text) {
        if (text != ")")
            throw LexemeException("Unknown right parenthesis: " + text);
        return std::make_shared<RightParenLexeme>();
    }
};

#endif // LEXEME_FACTORY_H
