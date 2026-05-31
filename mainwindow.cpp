#include "mainwindow.h"

#include <string>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), facade(), monkeyMovie(nullptr) {
    ui->setupUi(this);
    setupMonkeyAnimation();

    connectButtons();
    updateUi();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::connectButtons() {
    connect(ui->digit0Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit1Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit2Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit3Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit4Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit5Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit6Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit7Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit8Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit9Button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);

    connect(ui->plusButton, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->minusButton, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->multiplyButton, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->divideButton, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->dotButton, &QPushButton::clicked, this, &MainWindow::onDotButtonClicked);

    connect(ui->leftParenButton, &QPushButton::clicked, this, &MainWindow::onLeftParenButtonClicked);
    connect(ui->rightParenButton, &QPushButton::clicked, this, &MainWindow::onRightParenButtonClicked);
    connect(ui->equalsButton, &QPushButton::clicked, this, &MainWindow::onEqualsButtonClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::onClearButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteButtonClicked);
}

void MainWindow::updateUi() {
    ui->displayLineEdit->setText(QString::fromStdString(facade.getDisplayText()));
    ui->errorLabel->setText(QString::fromStdString(facade.getErrorText()));
}

void MainWindow::onDigitButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button && !button->text().isEmpty()) {
        std::string text(1, button->text().front().toLatin1());
        facade.handleDigitInput(text);
        updateUi();
    }
}

void MainWindow::onOperatorButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        facade.handleOperatorInput(button->text().toStdString());
        updateUi();
    }
}

void MainWindow::onDotButtonClicked() {
    facade.handleCommandInput(InputCommandType::Dot);
    updateUi();
}

void MainWindow::onLeftParenButtonClicked() {
    facade.handleCommandInput(InputCommandType::LeftParen);
    updateUi();
}

void MainWindow::onRightParenButtonClicked() {
    facade.handleCommandInput(InputCommandType::RightParen);
    updateUi();
}

void MainWindow::onClearButtonClicked() {
    facade.handleCommandInput(InputCommandType::Clear);
    updateUi();
}

void MainWindow::onDeleteButtonClicked() {
    facade.handleCommandInput(InputCommandType::Backspace);
    updateUi();
}

void MainWindow::onEqualsButtonClicked() {
    facade.evaluateExpression();
    updateUi();
}

// пасхалка
void MainWindow::setupMonkeyAnimation() {
    monkeyMovie = new QMovie(":/res/monkey.gif", QByteArray(), this);
    ui->monkeyLabel->setMovie(monkeyMovie);
    updateMonkeySize();
    monkeyMovie->start();
}

void MainWindow::updateMonkeySize() {
    QSize size = ui->monkeyLabel->contentsRect().size();
    monkeyMovie->setScaledSize(QSize(size.width(), size.height()));
    ui->monkeyLabel->setVisible(width() > Constants::MonkeyVisibleMinWidth);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    updateMonkeySize();
    QMainWindow::resizeEvent(event);
}
