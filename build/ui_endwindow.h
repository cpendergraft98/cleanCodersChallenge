/********************************************************************************
** Form generated from reading UI file 'endwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDWINDOW_H
#define UI_ENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EndWindow
{
public:
    QPushButton *replay;
    QPushButton *exit;
    QLabel *label;

    void setupUi(QDialog *EndWindow)
    {
        if (EndWindow->objectName().isEmpty())
            EndWindow->setObjectName("EndWindow");
        EndWindow->resize(400, 300);
        replay = new QPushButton(EndWindow);
        replay->setObjectName("replay");
        replay->setGeometry(QRect(60, 140, 271, 71));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        replay->setFont(font);
        replay->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        exit = new QPushButton(EndWindow);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(60, 220, 271, 71));
        exit->setFont(font);
        exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(EndWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 251, 101));
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(EndWindow);

        QMetaObject::connectSlotsByName(EndWindow);
    } // setupUi

    void retranslateUi(QDialog *EndWindow)
    {
        EndWindow->setWindowTitle(QCoreApplication::translate("EndWindow", "Dialog", nullptr));
        replay->setText(QCoreApplication::translate("EndWindow", "I want to try again!", nullptr));
        exit->setText(QCoreApplication::translate("EndWindow", "I've had enough!", nullptr));
        label->setText(QCoreApplication::translate("EndWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndWindow: public Ui_EndWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDWINDOW_H
