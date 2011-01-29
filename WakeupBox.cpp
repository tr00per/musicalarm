#include "WakeupBox.h"

#include <QTimer>
#include <cstdlib>

WakeupBox::WakeupBox(QWidget *parent, int length, const QString & charString) :
    QDialog(parent), len(length),
    chars(charString) {
    ui.setupUi(this);
    setFixedSize(337, 110);

    resetPassword();

    connect(ui.buttons, SIGNAL(accepted()), this, SLOT(accept()));
}

void WakeupBox::accept() {
    if (ui.input->text() == secret) {
        close();
    }
    else {
        ui.input->setEnabled(false);
        ui.input->setText(tr("Wrong sequence."));
        QTimer::singleShot(3000, this, SLOT(reenable()));
    }
}

void WakeupBox::reenable() {
    resetPassword();
    ui.input->setText("");
    ui.input->setEnabled(true);
}

void WakeupBox::resetPassword() {
    secret = "";

    while (secret.length() < len) {
        secret += chars[ rand() % chars.length() ];
    }

    ui.pasword->setText(secret);
}
