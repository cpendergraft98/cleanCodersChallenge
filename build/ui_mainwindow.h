/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *botRight;
    QPushButton *midMid;
    QPushButton *topLeft;
    QPushButton *botLeft;
    QPushButton *botMid;
    QPushButton *topRight;
    QPushButton *midRight;
    QPushButton *midLeft;
    QPushButton *topMid;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuBoard;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1107, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        botRight = new QPushButton(centralwidget);
        botRight->setObjectName("botRight");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(botRight->sizePolicy().hasHeightForWidth());
        botRight->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(96);
        font.setBold(true);
        botRight->setFont(font);
        botRight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(botRight, 3, 2, 1, 1);

        midMid = new QPushButton(centralwidget);
        midMid->setObjectName("midMid");
        sizePolicy.setHeightForWidth(midMid->sizePolicy().hasHeightForWidth());
        midMid->setSizePolicy(sizePolicy);
        midMid->setFont(font);
        midMid->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(midMid, 2, 1, 1, 1);

        topLeft = new QPushButton(centralwidget);
        topLeft->setObjectName("topLeft");
        sizePolicy.setHeightForWidth(topLeft->sizePolicy().hasHeightForWidth());
        topLeft->setSizePolicy(sizePolicy);
        topLeft->setFont(font);
        topLeft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(topLeft, 1, 0, 1, 1);

        botLeft = new QPushButton(centralwidget);
        botLeft->setObjectName("botLeft");
        sizePolicy.setHeightForWidth(botLeft->sizePolicy().hasHeightForWidth());
        botLeft->setSizePolicy(sizePolicy);
        botLeft->setFont(font);
        botLeft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(botLeft, 3, 0, 1, 1);

        botMid = new QPushButton(centralwidget);
        botMid->setObjectName("botMid");
        sizePolicy.setHeightForWidth(botMid->sizePolicy().hasHeightForWidth());
        botMid->setSizePolicy(sizePolicy);
        botMid->setFont(font);
        botMid->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(botMid, 3, 1, 1, 1);

        topRight = new QPushButton(centralwidget);
        topRight->setObjectName("topRight");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topRight->sizePolicy().hasHeightForWidth());
        topRight->setSizePolicy(sizePolicy1);
        topRight->setFont(font);
        topRight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(topRight, 1, 2, 1, 1);

        midRight = new QPushButton(centralwidget);
        midRight->setObjectName("midRight");
        sizePolicy.setHeightForWidth(midRight->sizePolicy().hasHeightForWidth());
        midRight->setSizePolicy(sizePolicy);
        midRight->setFont(font);
        midRight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(midRight, 2, 2, 1, 1);

        midLeft = new QPushButton(centralwidget);
        midLeft->setObjectName("midLeft");
        sizePolicy.setHeightForWidth(midLeft->sizePolicy().hasHeightForWidth());
        midLeft->setSizePolicy(sizePolicy);
        midLeft->setFont(font);
        midLeft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(midLeft, 2, 0, 1, 1);

        topMid = new QPushButton(centralwidget);
        topMid->setObjectName("topMid");
        sizePolicy.setHeightForWidth(topMid->sizePolicy().hasHeightForWidth());
        topMid->setSizePolicy(sizePolicy);
        topMid->setFont(font);
        topMid->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA;  /* Normal */\n"
"    color: white;              /* Text color */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005f73;  /* Hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003f50;  /* Pressed color */\n"
"}"));

        gridLayout->addWidget(topMid, 1, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1107, 20));
        menuBoard = new QMenu(menubar);
        menuBoard->setObjectName("menuBoard");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBoard->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        botRight->setText(QString());
        midMid->setText(QString());
        topLeft->setText(QString());
        botLeft->setText(QString());
        botMid->setText(QString());
        topRight->setText(QString());
        midRight->setText(QString());
        midLeft->setText(QString());
        topMid->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuBoard->setTitle(QCoreApplication::translate("MainWindow", "Board", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
