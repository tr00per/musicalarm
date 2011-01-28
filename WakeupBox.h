#ifndef WAKEUPBOX_H
#define WAKEUPBOX_H

#include "build/ui_WakeupBox.h"

class WakeupBox : public QDialog {
    Q_OBJECT
public:
    WakeupBox(QWidget *parent, int length, const QString & charString);

private:
    Ui::WakeupBox ui;
    QString secret;
    int len;
    QString chars;

    void resetPassword();

protected slots:
    void accept();
};

#endif // WAKEUPBOX_H
