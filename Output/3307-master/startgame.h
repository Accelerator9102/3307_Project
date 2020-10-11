#ifndef STARTGAME_H
#define STARTGAME_H

#include <QMainWindow>
#include "mypushbutton.h"
namespace Ui {
class StartGame;
}

class StartGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = nullptr);
    ~StartGame();
    MyPushButton *nextbtn = nullptr;
    void nextQuestion();
private:
    Ui::StartGame *ui;
};

#endif // STARTGAME_H
