#ifndef WAKEUPBOX_H
#define WAKEUPBOX_H

#include "build/ui_WakeupBox.h"

class WakeupBox : public QDialog {
    Q_OBJECT
public:
    WakeupBox(QWidget *parent = 0);

private:
    Ui::WakeupBox ui;
    QString secret;

    void resetPassword();

protected slots:
    void accept();
};

#endif // WAKEUPBOX_H
