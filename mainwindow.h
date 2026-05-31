#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "constants.h"
#include "facade.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QMovie>
#include <QPushButton>
#include <QResizeEvent>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::MainWindow* ui;
    Facade facade;

    void connectButtons();

    void updateUi();

    void onDigitButtonClicked();
    void onOperatorButtonClicked();
    void onDotButtonClicked();
    void onLeftParenButtonClicked();
    void onRightParenButtonClicked();
    void onEqualsButtonClicked();
    void onClearButtonClicked();
    void onDeleteButtonClicked();

    // пасхалка
    QMovie* monkeyMovie;
    void setupMonkeyAnimation();
    void updateMonkeySize();
};

#endif // MAINWINDOW_H
