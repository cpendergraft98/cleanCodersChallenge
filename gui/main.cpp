#include <QApplication>
#include "startwindow.h"

int main(int argc, char** argv)
{
    // build the app
    QApplication app(argc, argv);
    
    // build the start window
    StartWindow *startWindow = new StartWindow();

    // display the start window
    startWindow->show();

    return app.exec();
}
