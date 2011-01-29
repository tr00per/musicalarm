#include "MainWindow.h"
#include "Sound.h"
#include "WakeupBox.h"

#include <QTimer>
#include <QSettings>
#include <QFileDialog>
#include <QStringListModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), conf(new QSettings(this)),
    dreaming(false), timer(NULL), snd(NULL) {
    ui.setupUi(this);
    setFixedSize(342, 214);

    QDateTime now(QDate::currentDate(),
                  QTime(QTime::currentTime().hour(), QTime::currentTime().minute()+15, 0, 0));
    ui.dt->setDateTime(now);
    ui.dt->setMinimumDateTime(QDateTime::currentDateTime());
    ui.dt->setCurrentSection(QDateTimeEdit::HourSection);

    int maxHistory = conf->value("history/max", 5).toInt();
    for (int i = 0; i < maxHistory; ++i) {
        QString hist = conf->value("history/" + QString::number(i), QString()).toString();
        if (hist == "") {
            break;
        }
        ui.musicSrc->insertItem(0, hist, hist);
    }
    ui.musicSrc->setCurrentIndex(-1);

    int wbLen = conf->value("wakeup/length", 10).toInt();
    QString wbChars = conf->value("wakeup/chars",
                                  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ").toString();

    wb = new WakeupBox(this, wbLen, wbChars);

    connect(ui.getFile, SIGNAL(clicked()), SLOT(selectFile()));
    connect(ui.startBtn, SIGNAL(clicked()), SLOT(start()));
    connect(ui.musicSrc, SIGNAL(currentIndexChanged(int)), SLOT(selectHistory(int)));
}

MainWindow::~MainWindow() {
    if (timer != NULL) {
        timer->stop();
        delete timer;
    }

    if (snd != NULL) {
        delete snd;
    }

    int maxHistory = conf->value("history/max", 5).toInt();
    for (int i = 0; i < maxHistory && i < ui.musicSrc->count(); ++i) {
        conf->setValue("history/" + QString::number(i), ui.musicSrc->itemText(i));
    }
    conf->setValue("history/max", maxHistory);
    conf->setValue("wakeup/length", conf->value("wakeup/length", 10).toInt());
    conf->setValue("wakeup/chars", conf->value("wakeup/chars",
                   "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ").toString());
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
            ui.startBtn->setText(tr("Stop"));
            ui.getFile->setEnabled(false);
            ui.musicSrc->setEnabled(false);
            ui.dt->setEnabled(false);
            dreaming = true;
        }
    }
    else {
        timer->stop();
        ui.startBtn->setText(tr("Start"));
        ui.getFile->setEnabled(true);
        ui.musicSrc->setEnabled(true);
        ui.dt->setEnabled(true);
        ui.counter->setText("000:00:00");
        dreaming = false;
    }
}

void MainWindow::selectFile() {
    QFileDialog fd(this, tr("Select music for the alarm..."));
    fd.setFileMode(QFileDialog::ExistingFile);

    QStringList files;
    if (fd.exec()) {
        files = fd.selectedFiles();

        const QString & file = files.at(0);
        ui.musicSrc->insertItem(0, file, file);
        ui.musicSrc->setCurrentIndex(0);
    }
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
    int timeLeft = QDateTime::currentDateTime().secsTo( ui.dt->dateTime() );
    int hours = static_cast<int>( floor(timeLeft / 3600.0) );
    int minsec = timeLeft % 3600;
    int min = static_cast<int>( floor(minsec / 60.0) );
    int sec = minsec % 60;

    ui.counter->setText(longNum(hours, 3) + ":" + longNum(min, 2) + ":" + longNum(sec, 2));
    ui.dreamProg->setValue(100 * (totalTime-timeLeft) / float(totalTime));

    if (timeLeft <= 0) {
        start();
        ui.dreamProg->setValue(100);
        snd->play();
        wb->show();
    }
}

void MainWindow::selectHistory(int which) {
    if (which == -1) {
        return;
    }

    QString filename = ui.musicSrc->itemText(which);

    if (!QFile::exists(filename)) {
        ui.musicSrc->removeItem(which);
        ui.musicSrc->setCurrentIndex(-1);
        QMessageBox::information(this, tr("Wrong file!"),
                                 tr("File ") + filename + tr(" does not exist!"));
        return;
    }

    if (snd != NULL) {
        delete snd;
    }
    snd = new Sound(filename);
}
