#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    ~MyPushButton();


    void zoom1();
    void zoom2();

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
