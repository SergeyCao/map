#include "buttons.h"
#include <QtWidgets>

Buttons::Buttons(QWidget *parent):
    QWidget(parent)
{
    firstbutton->setText("出发点");
    firstbutton->setGeometry(QRect(20, 20, 80, 40));
    secondbutton->setText("目的地");
    secondbutton->setGeometry(QRect(120, 40, 80, 40));
    checkbutton->setText("确认");
    checkbutton->setGeometry(QRect(100, 100, 80, 40));
}
Buttons::~Buttons() {

}
