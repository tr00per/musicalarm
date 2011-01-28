#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "build/ui_MainWindow.h"

class QTimer;
class QSettings;
class Sound;
class WakeupBox;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget * parent = 0);
    virtual ~MainWindow();

protected:
    QSettings * conf;
    bool dreaming;
    QTimer * timer;
    Sound * snd;
    WakeupBox * wb;
    Ui::MainWindow ui;
    int totalTime;

    const QString longNum(int num, int len) const;

public slots:
    void start();
    void selectFile();
    void updateTimer();
    void selectHistory(int which);
};

#endif // MAINWINDOW_H
