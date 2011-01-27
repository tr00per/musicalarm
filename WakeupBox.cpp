#include "WakeupBox.h"

WakeupBox::WakeupBox(QWidget *parent) :
    QDialog(parent), secret() {
    ui.setupUi(this);

    while (secret.length() < 10) {
        //
    }
}

void WakeupBox::accept() {
    //
}

void WakeupBox::reject() {
    //
}
