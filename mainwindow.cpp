#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , facade()
    , commandManager(facade)
{
    ui->setupUi(this);
    connect(ui->digit0Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit1Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit2Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit3Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit4Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit5Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit6Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit7Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit8Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->digit9Button, &QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);

    connect(ui->plusButton, &QPushButton::clicked,this, &MainWindow::onOperatorButtonClicked);
    connect(ui->minusButton, &QPushButton::clicked,this, &MainWindow::onOperatorButtonClicked);
    connect(ui->multiplyButton, &QPushButton::clicked,this, &MainWindow::onOperatorButtonClicked);
    connect(ui->divideButton, &QPushButton::clicked,this, &MainWindow::onOperatorButtonClicked);

    connect(ui->sinButton, &QPushButton::clicked,this, &MainWindow::onFunctionButtonClicked);
    connect(ui->cosButton, &QPushButton::clicked,this, &MainWindow::onFunctionButtonClicked);
    connect(ui->tgButton, &QPushButton::clicked,this, &MainWindow::onFunctionButtonClicked);
    connect(ui->ctgButton, &QPushButton::clicked,this, &MainWindow::onFunctionButtonClicked);
    connect(ui->sqrtButton, &QPushButton::clicked,this, &MainWindow::onFunctionButtonClicked);

    connect(ui->dotButton, &QPushButton::clicked,this, &MainWindow::onDotButtonClicked);
    connect(ui->leftParenButton, &QPushButton::clicked,this, &MainWindow::onLeftParenButtonClicked);
    connect(ui->rightParenButton, &QPushButton::clicked,this, &MainWindow::onRightParenButtonClicked);
    connect(ui->equalsButton, &QPushButton::clicked,this, &MainWindow::onEqualsButtonClicked);
    connect(ui->clearButton, &QPushButton::clicked,this, &MainWindow::onClearButtonClicked);
    connect(ui->dellButton, &QPushButton::clicked,this, &MainWindow::onDellButtonClicked);
    connect(ui->undoButton, &QPushButton::clicked,this, &MainWindow::onUndoButtonClicked);
    connect(ui->redoButton, &QPushButton::clicked,this, &MainWindow::onRedoButtonClicked);
    connect(ui->memoryAddButton, &QPushButton::clicked,this, &MainWindow::onMemoryAddButtonClicked);
    connect(ui->memorySubButton, &QPushButton::clicked,this, &MainWindow::onMemorySubButtonClicked);
    connect(ui->memoryRecallButton, &QPushButton::clicked,this, &MainWindow::onMemoryRecallButtonClicked);
    connect(ui->memoryClearButton, &QPushButton::clicked,this, &MainWindow::onMemoryClearButtonClicked);
    connect(ui->inverseButton, &QPushButton::clicked,this, &MainWindow::onInverseButtonClicked);

    connect(ui->bestButton, &QPushButton::clicked,this, &MainWindow::onBestButtonClicked);
    refreshUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshUi() {
    ui->displayLineEdit->setText(QString::fromStdString(facade.getDisplayText()));
    ui->errorLabel->setText(QString::fromStdString(facade.getErrorText()));
}

void MainWindow::onDigitButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString text = button->text();
        if (!text.isEmpty()) {
            commandManager.executeCommand(std::make_unique<DigitCommand>(facade, text[0].toLatin1()));
            refreshUi();
        }
    }
}

void MainWindow::onOperatorButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString text = button->text();
        commandManager.executeCommand(std::make_unique<OperatorCommand>(facade, text.toStdString()));
        refreshUi();
    }
}

void MainWindow::onFunctionButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString text = button->text();
        commandManager.executeCommand(std::make_unique<FunctionCommand>(facade, text.toStdString()));
        refreshUi();
    }
}

void MainWindow::onDotButtonClicked() {
    commandManager.executeCommand(std::make_unique<DotCommand>(facade));
    refreshUi();
}

void MainWindow::onLeftParenButtonClicked() {
    commandManager.executeCommand(std::make_unique<LeftParenCommand>(facade));
    refreshUi();
}

void MainWindow::onRightParenButtonClicked() {
    commandManager.executeCommand(std::make_unique<RightParenCommand>(facade));
    refreshUi();
}

void MainWindow::onEqualsButtonClicked() {
    commandManager.executeCommand(std::make_unique<EqualsCommand>(facade));
    refreshUi();
}

void MainWindow::onClearButtonClicked() {
    commandManager.executeCommand(std::make_unique<ClearCommand>(facade));
    refreshUi();
}

void MainWindow::onDellButtonClicked() {
    commandManager.executeCommand(std::make_unique<BackspaceCommand>(facade));
    refreshUi();
}

void MainWindow::onUndoButtonClicked() {
    commandManager.undo();
    refreshUi();
}

void MainWindow::onRedoButtonClicked() {
    commandManager.redo();
    refreshUi();
}

void MainWindow::onMemoryAddButtonClicked() {
    commandManager.executeCommand(std::make_unique<MemoryAddCommand>(facade));
    refreshUi();
}

void MainWindow::onMemorySubButtonClicked() {
    commandManager.executeCommand(std::make_unique<MemorySubCommand>(facade));
    refreshUi();
}

void MainWindow::onMemoryRecallButtonClicked() {
    commandManager.executeCommand(std::make_unique<MemoryRecallCommand>(facade));
    refreshUi();
}

void MainWindow::onMemoryClearButtonClicked() {
    commandManager.executeCommand(std::make_unique<MemoryClearCommand>(facade));
    refreshUi();
}

void MainWindow::onInverseButtonClicked() {
    commandManager.executeCommand(std::make_unique<InverseCommand>(facade));
    refreshUi();
}

void MainWindow::onBestButtonClicked() {
    QString videoPath = QDir::toNativeSeparators("D:/video.mp4");
    QProcess *vlcProcess = new QProcess(this);
    ui->bestButton->setEnabled(false);
    connect(vlcProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this, vlcProcess]() {
                ui->bestButton->setEnabled(true);
                vlcProcess->deleteLater();
            });
    QString playerPath = "C:/Program Files (x86)/Windows Media Player/wmplayer.exe";
    vlcProcess->start(playerPath, QStringList() << videoPath << "/play");
    if (!vlcProcess->waitForStarted()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось запустить плеер");
        ui->bestButton->setEnabled(true);
    }
}