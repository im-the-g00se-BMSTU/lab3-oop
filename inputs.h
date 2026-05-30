#ifndef INPUTS_H
#define INPUTS_H

#include "facade.h"

#include <string>

class Input {
public:
    explicit Input(Facade& facade)
        : facade(facade) {}

    virtual ~Input() = default;
    virtual void execute() = 0;

protected:
    Facade& facade;
};

class InputDigit : public Input {
public:
    InputDigit(Facade& facade, const std::string& text)
        : Input(facade), text(text) {}

    void execute() override {
        facade.handleDigitInput(text);
    }

private:
    std::string text;
};

class InputOperator : public Input {
public:
    InputOperator(Facade& facade, const std::string& text)
        : Input(facade), text(text) {}

    void execute() override {
        facade.handleOperatorInput(text);
    }

private:
    std::string text;
};

class InputCommand : public Input {
public:
    InputCommand(Facade& facade, InputCommandType type)
        : Input(facade), type(type) {}

    void execute() override {
        facade.handleCommandInput(type);
    }

private:
    InputCommandType type;
};

class InputEvaluation : public Input {
public:
    InputEvaluation(Facade& facade)
        : Input(facade) {}

    void execute() override {
        facade.evaluateExpression();
    }
};

#endif // INPUTS_H
