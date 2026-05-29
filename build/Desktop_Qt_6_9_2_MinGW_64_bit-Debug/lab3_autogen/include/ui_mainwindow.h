/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *inputLayout;
    QLabel *monkeyLabel;
    QLineEdit *displayLineEdit;
    QLabel *errorLabel;
    QGridLayout *buttonLayout;
    QPushButton *digit2Button;
    QPushButton *deleteButton;
    QPushButton *digit3Button;
    QPushButton *divideButton;
    QPushButton *clearButton;
    QPushButton *dotButton;
    QPushButton *multiplyButton;
    QPushButton *digit7Button;
    QPushButton *leftParenButton;
    QPushButton *digit9Button;
    QPushButton *digit1Button;
    QPushButton *digit6Button;
    QPushButton *minusButton;
    QPushButton *digit8Button;
    QPushButton *equalsButton;
    QPushButton *digit4Button;
    QPushButton *plusButton;
    QPushButton *digit5Button;
    QPushButton *digit0Button;
    QPushButton *rightParenButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 700);
        MainWindow->setMinimumSize(QSize(400, 580));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/calc.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow, QWidget {\n"
"    background-color: #101010;\n"
"    color: #ffffff;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 12pt;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #101010;\n"
"    color: #ffffff;\n"
"    border: 1px solid #303030;\n"
"    border-radius: 6px;\n"
"    padding: 14px;\n"
"    font-size: 28pt;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #2b2b2b;\n"
"    color: #ffffff;\n"
"    border: 1px solid #3a3a3a;\n"
"    border-radius: 5px;\n"
"    min-height: 48px;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #333333;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f1f1f;\n"
"}\n"
"\n"
"QPushButton#equalsButton {\n"
"    background-color: #2d6bd6;\n"
"    border-color: #3478ee;\n"
"    font-size: 14pt;\n"
"}\n"
"\n"
"QPushButton#equalsButton:hover {\n"
"    background-color: #3578eb;\n"
"}\n"
"\n"
"QLabel#errorLabel {\n"
"    color: #ff5c5c;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLabel#monkeyLabel {\n"
" "
                        "   background-color: #101010;\n"
"    border: 1px solid #303030;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(12);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(24, 24, 24, 24);
        inputLayout = new QHBoxLayout();
        inputLayout->setSpacing(10);
        inputLayout->setObjectName("inputLayout");
        monkeyLabel = new QLabel(centralwidget);
        monkeyLabel->setObjectName("monkeyLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monkeyLabel->sizePolicy().hasHeightForWidth());
        monkeyLabel->setSizePolicy(sizePolicy);
        monkeyLabel->setScaledContents(true);
        monkeyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        inputLayout->addWidget(monkeyLabel);

        displayLineEdit = new QLineEdit(centralwidget);
        displayLineEdit->setObjectName("displayLineEdit");
        sizePolicy.setHeightForWidth(displayLineEdit->sizePolicy().hasHeightForWidth());
        displayLineEdit->setSizePolicy(sizePolicy);
        displayLineEdit->setMinimumSize(QSize(0, 132));
        displayLineEdit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        displayLineEdit->setReadOnly(true);

        inputLayout->addWidget(displayLineEdit);

        inputLayout->setStretch(0, 1);
        inputLayout->setStretch(1, 2);

        mainLayout->addLayout(inputLayout);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(errorLabel->sizePolicy().hasHeightForWidth());
        errorLabel->setSizePolicy(sizePolicy1);
        errorLabel->setMinimumSize(QSize(0, 24));
        errorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(errorLabel);

        buttonLayout = new QGridLayout();
        buttonLayout->setSpacing(10);
        buttonLayout->setObjectName("buttonLayout");
        digit2Button = new QPushButton(centralwidget);
        digit2Button->setObjectName("digit2Button");

        buttonLayout->addWidget(digit2Button, 3, 1, 1, 1);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");

        buttonLayout->addWidget(deleteButton, 0, 3, 1, 1);

        digit3Button = new QPushButton(centralwidget);
        digit3Button->setObjectName("digit3Button");

        buttonLayout->addWidget(digit3Button, 3, 2, 1, 1);

        divideButton = new QPushButton(centralwidget);
        divideButton->setObjectName("divideButton");

        buttonLayout->addWidget(divideButton, 1, 3, 1, 1);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        buttonLayout->addWidget(clearButton, 0, 2, 1, 1);

        dotButton = new QPushButton(centralwidget);
        dotButton->setObjectName("dotButton");

        buttonLayout->addWidget(dotButton, 4, 2, 1, 1);

        multiplyButton = new QPushButton(centralwidget);
        multiplyButton->setObjectName("multiplyButton");

        buttonLayout->addWidget(multiplyButton, 2, 3, 1, 1);

        digit7Button = new QPushButton(centralwidget);
        digit7Button->setObjectName("digit7Button");

        buttonLayout->addWidget(digit7Button, 1, 0, 1, 1);

        leftParenButton = new QPushButton(centralwidget);
        leftParenButton->setObjectName("leftParenButton");

        buttonLayout->addWidget(leftParenButton, 0, 0, 1, 1);

        digit9Button = new QPushButton(centralwidget);
        digit9Button->setObjectName("digit9Button");

        buttonLayout->addWidget(digit9Button, 1, 2, 1, 1);

        digit1Button = new QPushButton(centralwidget);
        digit1Button->setObjectName("digit1Button");

        buttonLayout->addWidget(digit1Button, 3, 0, 1, 1);

        digit6Button = new QPushButton(centralwidget);
        digit6Button->setObjectName("digit6Button");

        buttonLayout->addWidget(digit6Button, 2, 2, 1, 1);

        minusButton = new QPushButton(centralwidget);
        minusButton->setObjectName("minusButton");

        buttonLayout->addWidget(minusButton, 3, 3, 1, 1);

        digit8Button = new QPushButton(centralwidget);
        digit8Button->setObjectName("digit8Button");

        buttonLayout->addWidget(digit8Button, 1, 1, 1, 1);

        equalsButton = new QPushButton(centralwidget);
        equalsButton->setObjectName("equalsButton");
        equalsButton->setMinimumSize(QSize(0, 50));

        buttonLayout->addWidget(equalsButton, 5, 0, 1, 4);

        digit4Button = new QPushButton(centralwidget);
        digit4Button->setObjectName("digit4Button");

        buttonLayout->addWidget(digit4Button, 2, 0, 1, 1);

        plusButton = new QPushButton(centralwidget);
        plusButton->setObjectName("plusButton");

        buttonLayout->addWidget(plusButton, 4, 3, 1, 1);

        digit5Button = new QPushButton(centralwidget);
        digit5Button->setObjectName("digit5Button");

        buttonLayout->addWidget(digit5Button, 2, 1, 1, 1);

        digit0Button = new QPushButton(centralwidget);
        digit0Button->setObjectName("digit0Button");

        buttonLayout->addWidget(digit0Button, 4, 0, 1, 2);

        rightParenButton = new QPushButton(centralwidget);
        rightParenButton->setObjectName("rightParenButton");

        buttonLayout->addWidget(rightParenButton, 0, 1, 1, 1);


        mainLayout->addLayout(buttonLayout);

        mainLayout->setStretch(0, 1);
        mainLayout->setStretch(2, 2);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        monkeyLabel->setText(QString());
        errorLabel->setText(QString());
        digit2Button->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        digit3Button->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        divideButton->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        dotButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        multiplyButton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        digit7Button->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        leftParenButton->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        digit9Button->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        digit1Button->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        digit6Button->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        digit8Button->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        equalsButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        digit4Button->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        plusButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        digit5Button->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        digit0Button->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rightParenButton->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
