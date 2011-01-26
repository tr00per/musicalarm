#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

class QTimer;
class Sound;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

protected:
    Ui::MainWindow ui;
    QTimer * timer;
    Sound * snd;

protected slots:
    void start();
    void selectFile();
};

#endif // MAINWINDOW_H
