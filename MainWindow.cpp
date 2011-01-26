#include "MainWindow.h"
#include "Sound.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), dreaming(false),
    timer(NULL), snd(NULL) {
    ui.setupUi(this);

    ui.dt->setMinimumDateTime(QDateTime::currentDateTime());
    ui.dt->setTime(QTime::currentTime().addSecs(60*15) );

    connect(ui.getFile, SIGNAL(clicked()), SLOT(selectFile()));
    connect(ui.startBtn, SIGNAL(clicked()), SLOT(start()));
}

MainWindow::~MainWindow() {
    if (timer != NULL) {
        timer->stop();
        delete timer;
    }

    if (snd != NULL) {
        delete snd;
    }
}

void MainWindow::start() {
    if (!dreaming) {
        if (snd != NULL) {
            if (timer == NULL) {
                timer = new QTimer();
                connect(timer, SIGNAL(timeout()), SLOT(updateTimer()));
            }

            totalTime = ui.dt->dateTime().toTime_t() - QDateTime::currentDateTime().toTime_t();
            timer->start(500);
            ui.startBtn->setText("Stop");
            dreaming = true;
        }
    }
    else {
        timer->stop();
        ui.startBtn->setText("Start");
        ui.counter->setText("000:00:00");
        dreaming = false;
    }
}

void MainWindow::selectFile() {
    //
}

const QString MainWindow::longNum(int num, int len) const {
    QString conv;
    conv.setNum(num);

    while (conv.length() < len) {
        conv = "0" + conv;
    }

    return conv;
}

void MainWindow::updateTimer() {
    int timeLeft = ui.dt->dateTime().toTime_t() - QDateTime::currentDateTime().toTime_t();
    int hours = timeLeft / 3600;
    int minsec = timeLeft % 3600;
    int min = minsec / 60;
    int sec = minsec % 60;

    ui.counter->setText(longNum(hours, 3) + ":" + longNum(min, 2) + ":" + longNum(sec, 2));
    ui.dreamProg->setValue(100 * (totalTime-timeLeft) / float(totalTime));

    if (timeLeft <= 0) {
        timer->stop();
        snd->play();
    }
}
