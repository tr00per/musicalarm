#include "WakeupBox.h"

#include <QThread>
#include <cstdlib>

WakeupBox::WakeupBox(QWidget *parent) :
    QDialog(parent) {
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
        ui.input->setText(("Wrong sequence."));
        sleep(3);
        resetPassword();
        ui.input->setText("");
        ui.input->setEnabled(true);
    }
}

void WakeupBox::resetPassword() {
    secret = "";

    while (secret.length() < 10) {
        secret += char((rand() % 27) + ((rand()%2 == 0)? 65:97));
    }

    ui.pasword->setText(secret);
}
