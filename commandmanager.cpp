#include "commandmanager.h"

CommandManager::CommandManager(CalcFacade& facade) : facade(facade), currentIndex(0) {
    history.push_back(facade.saveState());
}

void CommandManager::executeCommand(std::unique_ptr<ICommand> command) {
    CalcFacade::State before = facade.saveState();
    command->execute();
    CalcFacade::State after = facade.saveState();
    if (before != after) {
        removeRedoStates();
        history.push_back(std::move(after));
        currentIndex = history.size() - 1;
    }
}

void CommandManager::undo() {
    if (currentIndex > 0) {
        --currentIndex;
        facade.restoreState(history[currentIndex]);
    }
}

void CommandManager::redo() {
    if (currentIndex + 1 < history.size()) {
        ++currentIndex;
        facade.restoreState(history[currentIndex]);
    }
}

void CommandManager::removeRedoStates() {
    if (currentIndex + 1 < history.size()) {
        history.erase(history.begin() + currentIndex + 1, history.end());
    }
}



