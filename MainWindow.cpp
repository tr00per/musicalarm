#include "MainWindow.h"
#include "Sound.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), timer(NULL) {
    ui.setupUi(this);
}

MainWindow::~MainWindow() {
    if (timer != NULL) {
        timer->stop();
        delete timer;
    }
}

void MainWindow::start() {
    //
}

void MainWindow::selectFile() {
    //
}
