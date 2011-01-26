/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed Jan 26 13:31:42 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *counter;
    QProgressBar *dreamProg;
    QLabel *dreamLabel;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *musicSrc;
    QPushButton *start;
    QToolButton *getFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(342, 214);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        counter = new QLabel(centralWidget);
        counter->setObjectName(QString::fromUtf8("counter"));
        counter->setGeometry(QRect(0, 80, 342, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        counter->setFont(font);
        counter->setAlignment(Qt::AlignCenter);
        dreamProg = new QProgressBar(centralWidget);
        dreamProg->setObjectName(QString::fromUtf8("dreamProg"));
        dreamProg->setGeometry(QRect(80, 172, 251, 31));
        dreamProg->setValue(0);
        dreamProg->setTextVisible(true);
        dreamLabel = new QLabel(centralWidget);
        dreamLabel->setObjectName(QString::fromUtf8("dreamLabel"));
        dreamLabel->setGeometry(QRect(10, 180, 59, 17));
        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(180, 10, 151, 27));
        dateTimeEdit->setDateTime(QDateTime(QDate(2011, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setDate(QDate(2011, 1, 1));
        dateTimeEdit->setDisplayFormat(QString::fromUtf8("yyyy-MM-dd HH:mm"));
        musicSrc = new QLineEdit(centralWidget);
        musicSrc->setObjectName(QString::fromUtf8("musicSrc"));
        musicSrc->setGeometry(QRect(10, 50, 281, 27));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(10, 10, 111, 28));
        getFile = new QToolButton(centralWidget);
        getFile->setObjectName(QString::fromUtf8("getFile"));
        getFile->setGeometry(QRect(300, 50, 27, 27));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(start, SIGNAL(clicked()), MainWindow, SLOT(start()));
        QObject::connect(getFile, SIGNAL(clicked()), MainWindow, SLOT(selectFile()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MusicAlarm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "Wake me up before you go go...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        counter->setText(QApplication::translate("MainWindow", "000:00:00", 0, QApplication::UnicodeUTF8));
        dreamLabel->setText(QApplication::translate("MainWindow", "Dream", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        getFile->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
