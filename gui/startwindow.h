#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    // button handlers for start window
    void onPlayClicked();
    void onExitClicked();

private:
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
