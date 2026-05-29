#ifndef COMMANDS_H
#define COMMANDS_H

#include "calcfacade.h"
#include <memory>
#include <string>

class ICommand {
public:
    explicit ICommand(CalcFacade& facade) : facade(facade) {}

    virtual ~ICommand() = default;

    virtual void execute() = 0;

protected:
    CalcFacade& facade;
};

class DigitCommand : public ICommand {
public:
    DigitCommand(CalcFacade& facade, char digit) : ICommand(facade), digit(digit) {}

    void execute() override {
        facade.pressDigit(digit);
    }

private:
    char digit;
};

class DotCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressDot();
    }
};

class OperatorCommand : public ICommand {
public:
    OperatorCommand(CalcFacade& facade, const std::string& text) : ICommand(facade), text(text) {}

    void execute() override {
        facade.pressOperator(text);
    }

private:
    std::string text;
};

class FunctionCommand : public ICommand {
public:
    FunctionCommand(CalcFacade& facade, const std::string& text)
        : ICommand(facade), text(text) {
    }

    void execute() override {
        facade.pressFunction(text);
    }

private:
    std::string text;
};

class LeftParenCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressLeftParen();
    }
};

class RightParenCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressRightParen();
    }
};

class EqualsCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressEquals();
    }
};

class ClearCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressClear();
    }
};

class BackspaceCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressBackspace();
    }
};

class MemoryAddCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressMemoryAdd();
    }
};

class MemorySubCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressMemorySub();
    }
};

class MemoryRecallCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressMemoryRecall();
    }
};

class MemoryClearCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressMemoryClear();
    }
};

class InverseCommand : public ICommand {
public:
    using ICommand::ICommand;

    void execute() override {
        facade.pressInverse();
    }
};


#endif // COMMANDS_H
