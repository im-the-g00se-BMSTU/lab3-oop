#ifndef MANAGER_H
#define MANAGER_H

#include "ifactorylexeme.h"
#include <memory>
#include <map>

#include "binaryoperatorfactory.h"
#include "functionfactory.h"
#include "lexerexception.h"
#include "numberfactory.h"
#include "parenfactory.h"
#include "unaryoperatorfactory.h"

class Manager {
private:
    std::map<LexemeKind, std::shared_ptr<ILexemeFactory>> factories;
public:
    Manager() {
        factories[LexemeKind::Number] = std::make_shared<NumberFactory>();
        factories[LexemeKind::BinaryOperator] = std::make_shared<BinaryOperatorFactory>();
        factories[LexemeKind::UnaryOperator] = std::make_shared<UnaryOperatorFactory>();
        factories[LexemeKind::Function] = std::make_shared<FunctionFactory>();
        factories[LexemeKind::LeftParen] = std::make_shared<ParenFactory>();
        factories[LexemeKind::RightParen] = std::make_shared<ParenFactory>();
    }
    std::shared_ptr<Lexeme> create(LexemeKind kind, const std::string& text) const {
        auto iterator = factories.find(kind);
        if (iterator == factories.end())
            throw LexerException("Подходящая фабрика не найдена");
        return iterator->second->create(text);
    }
};

#endif // MANAGER_H
