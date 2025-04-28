/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QPushButton *play;
    QPushButton *exit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(400, 300);
        play = new QPushButton(StartWindow);
        play->setObjectName("play");
        play->setGeometry(QRect(40, 120, 311, 61));
        QFont font;
        font.setPointSize(16);
        play->setFont(font);
        exit = new QPushButton(StartWindow);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(40, 210, 311, 61));
        exit->setFont(font);
        label = new QLabel(StartWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 311, 51));
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(StartWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 311, 51));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "Dialog", nullptr));
        play->setText(QCoreApplication::translate("StartWindow", "Yes!", nullptr));
        exit->setText(QCoreApplication::translate("StartWindow", "No!", nullptr));
        label->setText(QCoreApplication::translate("StartWindow", "Are you ready to play", nullptr));
        label_2->setText(QCoreApplication::translate("StartWindow", "UBEATABLE TIC-TAC-TOE?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
