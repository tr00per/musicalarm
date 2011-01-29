#include "MainWindow.h"

#include <QApplication>
#include <QTextCodec>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    a.setOrganizationName("tr00per");
    a.setApplicationName("MusicAlarm");
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();
    return a.exec();
}
