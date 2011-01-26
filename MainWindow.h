#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "build/ui_MainWindow.h"

class QTimer;
class Sound;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

protected:
    bool dreaming;
    QTimer * timer;
    Sound * snd;
    Ui::MainWindow ui;
    int totalTime;

    const QString longNum(int num, int len) const;

public slots:
    void start();
    void selectFile();
    void updateTimer();
};

#endif // MAINWINDOW_H
