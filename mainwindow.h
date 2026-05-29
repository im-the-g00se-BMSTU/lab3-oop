#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commandmanager.h"
#include <QAbstractButton>
#include <QProcess>
#include <QDir>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    CalcFacade facade;
    CommandManager commandManager;

    void refreshUi();
    void onDigitButtonClicked();
    void onOperatorButtonClicked();
    void onFunctionButtonClicked();
    void onDotButtonClicked();
    void onLeftParenButtonClicked();
    void onRightParenButtonClicked();
    void onEqualsButtonClicked();
    void onClearButtonClicked();
    void onDellButtonClicked();
    void onUndoButtonClicked();
    void onRedoButtonClicked();
    void onMemoryAddButtonClicked();
    void onMemorySubButtonClicked();
    void onMemoryRecallButtonClicked();
    void onMemoryClearButtonClicked();
    void onInverseButtonClicked();
    void onBestButtonClicked();
};
#endif // MAINWINDOW_H
