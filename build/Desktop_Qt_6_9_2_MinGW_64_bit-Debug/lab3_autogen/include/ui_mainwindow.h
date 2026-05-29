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
#include <QtWidgets/QApplication>
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
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *displayLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *memoryAddButton;
    QPushButton *memorySubButton;
    QPushButton *memoryRecallButton;
    QPushButton *memoryClearButton;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *sinButton;
    QPushButton *cosButton;
    QPushButton *sqrtButton;
    QPushButton *inverseButton;
    QPushButton *leftParenButton;
    QPushButton *rightParenButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *tgButton;
    QPushButton *ctgButton;
    QPushButton *minusButton;
    QPushButton *plusButton;
    QPushButton *multiplyButton;
    QPushButton *divideButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *digit1Button;
    QPushButton *digit2Button;
    QPushButton *digit3Button;
    QPushButton *dellButton;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *digit4Button;
    QPushButton *digit5Button;
    QPushButton *digit6Button;
    QPushButton *clearButton;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *digit7Button;
    QPushButton *digit8Button;
    QPushButton *digit9Button;
    QPushButton *bestButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *digit0Button;
    QPushButton *dotButton;
    QPushButton *equalsButton;
    QLabel *errorLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(469, 372);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"        background-color: #1e1e1e;\n"
"    }\n"
"    QLineEdit {\n"
"        background-color: #252526;\n"
"        color: white;\n"
"        border: none;\n"
"        font-size: 24px;\n"
"    }\n"
"QPushButton {\n"
"    background-color: #2b2b2b;\n"
"    color: #e0e0e0;\n"
"    border: 2px solid #3f3f3f;\n"
"    border-radius: 15px; /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #3d3d3d;\n"
"    border: 2px solid #505050;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1a1a1a;\n"
"    border: 2px solid #00ff88;\n"
"    color: #00ff88;\n"
"}\n"
"QPushButton:hover {\n"
"    border: 1px solid #00ffcc; \n"
"    background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, \n"
"                                      stop:0 #444444, stop:0.5 #3d5a5a, stop:1 #2b2b2b);\n"
"}\n"
"QPushButton {\n"
"    /* \320\236\321\201\320\275\320\276"
                        "\320\262\320\275\320\276\320\271 \321\204\320\276\320\275 \321\201 \320\273\320\265\320\263\320\272\320\270\320\274 \321\200\320\260\320\264\320\270\320\260\320\273\321\214\320\275\321\213\320\274 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\276\320\274 (\321\206\320\265\320\275\321\202\321\200 \321\201\320\262\320\265\321\202\320\273\320\265\320\265 \320\272\321\200\320\260\320\265\320\262) */\n"
"    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.8, fx:0.5, fy:0.5, \n"
"                                      stop:0 #3d3d3d, stop:1 #252525);\n"
"    \n"
"    /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \321\201\320\264\320\265\320\273\320\260\320\265\320\274 \321\207\321\203\321\202\321\214 \321\217\321\200\321\207\320\265, \321\207\321\202\320\276\320\261\321\213 \320\276\320\275 \"\321\201\320\262\320\265\321\202\320\270\320\273\321\201\321\217\" */\n"
"    color: #00ffcc; \n"
"    \n"
"    /* \320\257\321\200\320\272\320"
                        "\260\321\217 \321\200\320\260\320\274\320\272\320\260 \321\201\320\276\320\267\320\264\320\260\320\265\321\202 \321\215\321\204\321\204\320\265\320\272\321\202 \321\201\320\262\320\265\321\207\320\265\320\275\320\270\321\217 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 */\n"
"    border: 1px solid #008877; \n"
"    border-radius: 12px;\n"
"    \n"
"    /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213, \321\207\321\202\320\276\320\261\321\213 \321\202\320\265\320\272\321\201\321\202 \320\275\320\265 \320\277\321\200\320\270\320\273\320\270\320\277\320\260\320\273 \320\272 \320\272\321\200\320\260\321\217\320\274 */\n"
"    padding: 5px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        displayLineEdit = new QLineEdit(centralwidget);
        displayLineEdit->setObjectName("displayLineEdit");
        sizePolicy.setHeightForWidth(displayLineEdit->sizePolicy().hasHeightForWidth());
        displayLineEdit->setSizePolicy(sizePolicy);
        displayLineEdit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        displayLineEdit->setReadOnly(true);

        verticalLayout_2->addWidget(displayLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        memoryAddButton = new QPushButton(centralwidget);
        memoryAddButton->setObjectName("memoryAddButton");
        sizePolicy.setHeightForWidth(memoryAddButton->sizePolicy().hasHeightForWidth());
        memoryAddButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(memoryAddButton);

        memorySubButton = new QPushButton(centralwidget);
        memorySubButton->setObjectName("memorySubButton");
        sizePolicy.setHeightForWidth(memorySubButton->sizePolicy().hasHeightForWidth());
        memorySubButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(memorySubButton);

        memoryRecallButton = new QPushButton(centralwidget);
        memoryRecallButton->setObjectName("memoryRecallButton");
        sizePolicy.setHeightForWidth(memoryRecallButton->sizePolicy().hasHeightForWidth());
        memoryRecallButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(memoryRecallButton);

        memoryClearButton = new QPushButton(centralwidget);
        memoryClearButton->setObjectName("memoryClearButton");
        sizePolicy.setHeightForWidth(memoryClearButton->sizePolicy().hasHeightForWidth());
        memoryClearButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(memoryClearButton);

        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName("undoButton");
        sizePolicy.setHeightForWidth(undoButton->sizePolicy().hasHeightForWidth());
        undoButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(undoButton);

        redoButton = new QPushButton(centralwidget);
        redoButton->setObjectName("redoButton");
        sizePolicy.setHeightForWidth(redoButton->sizePolicy().hasHeightForWidth());
        redoButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(redoButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        sinButton = new QPushButton(centralwidget);
        sinButton->setObjectName("sinButton");
        sizePolicy.setHeightForWidth(sinButton->sizePolicy().hasHeightForWidth());
        sinButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(sinButton);

        cosButton = new QPushButton(centralwidget);
        cosButton->setObjectName("cosButton");
        sizePolicy.setHeightForWidth(cosButton->sizePolicy().hasHeightForWidth());
        cosButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(cosButton);

        sqrtButton = new QPushButton(centralwidget);
        sqrtButton->setObjectName("sqrtButton");
        sizePolicy.setHeightForWidth(sqrtButton->sizePolicy().hasHeightForWidth());
        sqrtButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(sqrtButton);

        inverseButton = new QPushButton(centralwidget);
        inverseButton->setObjectName("inverseButton");
        sizePolicy.setHeightForWidth(inverseButton->sizePolicy().hasHeightForWidth());
        inverseButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(inverseButton);

        leftParenButton = new QPushButton(centralwidget);
        leftParenButton->setObjectName("leftParenButton");
        sizePolicy.setHeightForWidth(leftParenButton->sizePolicy().hasHeightForWidth());
        leftParenButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(leftParenButton);

        rightParenButton = new QPushButton(centralwidget);
        rightParenButton->setObjectName("rightParenButton");
        sizePolicy.setHeightForWidth(rightParenButton->sizePolicy().hasHeightForWidth());
        rightParenButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(rightParenButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        tgButton = new QPushButton(centralwidget);
        tgButton->setObjectName("tgButton");
        sizePolicy.setHeightForWidth(tgButton->sizePolicy().hasHeightForWidth());
        tgButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(tgButton);

        ctgButton = new QPushButton(centralwidget);
        ctgButton->setObjectName("ctgButton");
        sizePolicy.setHeightForWidth(ctgButton->sizePolicy().hasHeightForWidth());
        ctgButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(ctgButton);

        minusButton = new QPushButton(centralwidget);
        minusButton->setObjectName("minusButton");
        sizePolicy.setHeightForWidth(minusButton->sizePolicy().hasHeightForWidth());
        minusButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(minusButton);

        plusButton = new QPushButton(centralwidget);
        plusButton->setObjectName("plusButton");
        sizePolicy.setHeightForWidth(plusButton->sizePolicy().hasHeightForWidth());
        plusButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(plusButton);

        multiplyButton = new QPushButton(centralwidget);
        multiplyButton->setObjectName("multiplyButton");
        sizePolicy.setHeightForWidth(multiplyButton->sizePolicy().hasHeightForWidth());
        multiplyButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(multiplyButton);

        divideButton = new QPushButton(centralwidget);
        divideButton->setObjectName("divideButton");
        sizePolicy.setHeightForWidth(divideButton->sizePolicy().hasHeightForWidth());
        divideButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(divideButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        digit1Button = new QPushButton(centralwidget);
        digit1Button->setObjectName("digit1Button");
        sizePolicy.setHeightForWidth(digit1Button->sizePolicy().hasHeightForWidth());
        digit1Button->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(digit1Button);

        digit2Button = new QPushButton(centralwidget);
        digit2Button->setObjectName("digit2Button");
        sizePolicy.setHeightForWidth(digit2Button->sizePolicy().hasHeightForWidth());
        digit2Button->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(digit2Button);

        digit3Button = new QPushButton(centralwidget);
        digit3Button->setObjectName("digit3Button");
        sizePolicy.setHeightForWidth(digit3Button->sizePolicy().hasHeightForWidth());
        digit3Button->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(digit3Button);

        dellButton = new QPushButton(centralwidget);
        dellButton->setObjectName("dellButton");
        sizePolicy.setHeightForWidth(dellButton->sizePolicy().hasHeightForWidth());
        dellButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(dellButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        digit4Button = new QPushButton(centralwidget);
        digit4Button->setObjectName("digit4Button");
        sizePolicy.setHeightForWidth(digit4Button->sizePolicy().hasHeightForWidth());
        digit4Button->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(digit4Button);

        digit5Button = new QPushButton(centralwidget);
        digit5Button->setObjectName("digit5Button");
        sizePolicy.setHeightForWidth(digit5Button->sizePolicy().hasHeightForWidth());
        digit5Button->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(digit5Button);

        digit6Button = new QPushButton(centralwidget);
        digit6Button->setObjectName("digit6Button");
        sizePolicy.setHeightForWidth(digit6Button->sizePolicy().hasHeightForWidth());
        digit6Button->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(digit6Button);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(clearButton);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        digit7Button = new QPushButton(centralwidget);
        digit7Button->setObjectName("digit7Button");
        sizePolicy.setHeightForWidth(digit7Button->sizePolicy().hasHeightForWidth());
        digit7Button->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(digit7Button);

        digit8Button = new QPushButton(centralwidget);
        digit8Button->setObjectName("digit8Button");
        sizePolicy.setHeightForWidth(digit8Button->sizePolicy().hasHeightForWidth());
        digit8Button->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(digit8Button);

        digit9Button = new QPushButton(centralwidget);
        digit9Button->setObjectName("digit9Button");
        sizePolicy.setHeightForWidth(digit9Button->sizePolicy().hasHeightForWidth());
        digit9Button->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(digit9Button);

        bestButton = new QPushButton(centralwidget);
        bestButton->setObjectName("bestButton");
        sizePolicy.setHeightForWidth(bestButton->sizePolicy().hasHeightForWidth());
        bestButton->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(bestButton);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        digit0Button = new QPushButton(centralwidget);
        digit0Button->setObjectName("digit0Button");
        sizePolicy.setHeightForWidth(digit0Button->sizePolicy().hasHeightForWidth());
        digit0Button->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(digit0Button);

        dotButton = new QPushButton(centralwidget);
        dotButton->setObjectName("dotButton");
        sizePolicy.setHeightForWidth(dotButton->sizePolicy().hasHeightForWidth());
        dotButton->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(dotButton);

        equalsButton = new QPushButton(centralwidget);
        equalsButton->setObjectName("equalsButton");
        sizePolicy.setHeightForWidth(equalsButton->sizePolicy().hasHeightForWidth());
        equalsButton->setSizePolicy(sizePolicy);
        equalsButton->setMinimumSize(QSize(217, 0));

        horizontalLayout_4->addWidget(equalsButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        sizePolicy.setHeightForWidth(errorLabel->sizePolicy().hasHeightForWidth());
        errorLabel->setSizePolicy(sizePolicy);
        errorLabel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(11);
        errorLabel->setFont(font);
        errorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        errorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(errorLabel);


        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        memoryAddButton->setText(QCoreApplication::translate("MainWindow", "M+", nullptr));
        memorySubButton->setText(QCoreApplication::translate("MainWindow", "M-", nullptr));
        memoryRecallButton->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
        memoryClearButton->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo  ", nullptr));
        redoButton->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        sinButton->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        cosButton->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        sqrtButton->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        inverseButton->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        leftParenButton->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        rightParenButton->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        tgButton->setText(QCoreApplication::translate("MainWindow", "tg", nullptr));
        ctgButton->setText(QCoreApplication::translate("MainWindow", "ctg", nullptr));
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        plusButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        multiplyButton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        divideButton->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        digit1Button->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        digit2Button->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        digit3Button->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        dellButton->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        digit4Button->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        digit5Button->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        digit6Button->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        digit7Button->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        digit8Button->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        digit9Button->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        bestButton->setText(QCoreApplication::translate("MainWindow", "\320\226\320\274\320\270", nullptr));
        digit0Button->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        dotButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        equalsButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
