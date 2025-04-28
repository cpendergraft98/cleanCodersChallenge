#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class EndWindow;
}

class EndWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EndWindow(QWidget *parent = nullptr, MainWindow *mainWindow = nullptr, char terminalState = '_');
    ~EndWindow();

private slots:
    // button handlers
    void onReplayClicked();
    void onExitClicked();

private:
    Ui::EndWindow *ui;
    MainWindow *m_mainWindow;
    char m_terminalState;
};

#endif // ENDWINDOW_H
