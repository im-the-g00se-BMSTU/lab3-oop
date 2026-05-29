#ifndef COMMANDS_H
#define COMMANDS_H

#include "facade.h"

#include <string>

class Command {
public:
    explicit Command(Facade& facade)
        : facade(facade) {}

    virtual ~Command() = default;
    virtual void execute() = 0;

protected:
    Facade& facade;
};

class DigitCommand : public Command {
public:
    DigitCommand(Facade& facade, char digit)
        : Command(facade), digit(digit) {}

    void execute() override {
        facade.pressDigit(digit);
    }

private:
    char digit;
};

class TextCommand : public Command {
public:
    TextCommand(Facade& facade, const std::string& text)
        : Command(facade), text(text) {}

protected:
    std::string text;
};

class OperatorCommand : public TextCommand {
public:
    using TextCommand::TextCommand;

    void execute() override {
        facade.pressOperator(text);
    }
};

class DotCommand : public Command {
public:
    using Command::Command;

    void execute() override {
        facade.pressDot();
    }
};

class LeftParenCommand : public Command {
public:
    using Command::Command;

    void execute() override {
        facade.pressLeftParen();
    }
};

class RightParenCommand : public Command {
public:
    using Command::Command;

    void execute() override {
        facade.pressRightParen();
    }
};

class EqualsCommand : public Command {
public:
    using Command::Command;

    void execute() override {
        facade.pressEquals();
    }
};

class ClearCommand : public Command {
public:
    using Command::Command;

    void execute() override {
        facade.pressClear();
    }
};

class BackspaceCommand : public Command {
public:
    using Command::Command;

    void execute() override {
        facade.pressBackspace();
    }
};

#endif // COMMANDS_H
