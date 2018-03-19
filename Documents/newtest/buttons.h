#ifndef BUTTONS_H
#define BUTTONS_H

#include <QtWidgets>
class Buttons : public QWidget
{
public:
    Buttons(QWidget *parent = 0 );
    ~Buttons();
private:
    QPushButton *checkbutton, *firstbutton, *secondbutton;
};


#endif // BUTTONS_H
