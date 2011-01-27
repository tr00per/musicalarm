#ifndef WAKEUPBOX_H
#define WAKEUPBOX_H

#include "build/ui_WakeupBox.h"

class WakeupBox : public QDialog {
    Q_OBJECT
public:
    WakeupBox(QWidget *parent = 0);

public slots:
    void accept();
    void reject();

private:
    Ui::WakeupBox ui;
    QString secret;
};

#endif // WAKEUPBOX_H
