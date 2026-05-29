#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include "calcfacade.h"
#include "commands.h"
#include <memory>
#include <vector>

class CommandManager {
private:
    void removeRedoStates();

    CalcFacade& facade;
    std::vector<CalcFacade::State> history;
    int currentIndex;
public:
    explicit CommandManager(CalcFacade& facade);

    void executeCommand(std::unique_ptr<ICommand> command);
    void undo();
    void redo();
};
#endif // COMMANDMANAGER_H
