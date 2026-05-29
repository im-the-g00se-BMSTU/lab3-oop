#ifndef NUMBERFACTORY_H
#define NUMBERFACTORY_H

#include "ifactorylexeme.h"
#include "numberlexeme.h"

class NumberFactory : public ILexemeFactory {
public:
    std::shared_ptr<Lexeme> create(const std::string& text) const override {
        return std::make_shared<NumberLexeme>(text);
    }
};

#endif // NUMBERFACTORY_H
