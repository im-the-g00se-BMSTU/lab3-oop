#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), facade(), monkeyMovie(nullptr) {
    ui->setupUi(this);
    setupMonkeyAnimation();

    connectButtons();
    refreshUi();
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

void MainWindow::refreshUi() {
    ui->displayLineEdit->setText(QString::fromStdString(facade.getDisplayText()));
    ui->errorLabel->setText(QString::fromStdString(facade.getErrorText()));
}

void MainWindow::executeCommand(Command& command) {
    command.execute();
    refreshUi();
}

void MainWindow::onDigitButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button && !button->text().isEmpty()) {
        DigitCommand command(facade, button->text().front().toLatin1());
        executeCommand(command);
    }
}

void MainWindow::onOperatorButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        OperatorCommand command(facade, button->text().toStdString());
        executeCommand(command);
    }
}

void MainWindow::onDotButtonClicked() {
    DotCommand command(facade);
    executeCommand(command);
}

void MainWindow::onLeftParenButtonClicked() {
    LeftParenCommand command(facade);
    executeCommand(command);
}

void MainWindow::onRightParenButtonClicked() {
    RightParenCommand command(facade);
    executeCommand(command);
}

void MainWindow::onEqualsButtonClicked() {
    EqualsCommand command(facade);
    executeCommand(command);
}

void MainWindow::onClearButtonClicked() {
    ClearCommand command(facade);
    executeCommand(command);
}

void MainWindow::onDeleteButtonClicked() {
    BackspaceCommand command(facade);
    executeCommand(command);
}

// пасхалка
void MainWindow::setupMonkeyAnimation() {
    monkeyMovie = new QMovie(":/res/monkey.gif", QByteArray(), this);
    monkeyMovie->setScaledSize(ui->monkeyLabel->contentsRect().size());
    ui->monkeyLabel->setMovie(monkeyMovie);
    monkeyMovie->start();
    ui->monkeyLabel->setVisible(width() > Constants::MonkeyVisibleMinWidth);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    ui->monkeyLabel->setVisible(width() > Constants::MonkeyVisibleMinWidth);
}
