#include "startgame.h"
#include "ui_startgame.h"
#include <QLabel>
#include <QRadioButton>
#include <QButtonGroup>
#include <QTimer>
StartGame::StartGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
    this->setFixedSize(1600,900);
    this->setWindowTitle("Playing Game!");
    this->setStyleSheet("background-color: pink;");




    QMenuBar * bar = menuBar();

    setMenuBar(bar);

    QMenu * startMenu = bar->addMenu("Options");

    QAction * quitAction=startMenu->addAction("Quit");

    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    QButtonGroup *group1;
    group1 = new QButtonGroup(this);
    group1->addButton(ui->button1,0);
    group1->addButton(ui->button2,1);
    group1->addButton(ui->button3,2);
    group1->addButton(ui->button4,3);
    ui->button1->setChecked(true);







    nextbtn = new MyPushButton();
    nextbtn->setText("Next!");
    nextbtn->move(300,700);
    nextbtn->setParent(this);

    connect(this->nextbtn,&MyPushButton::clicked,[=](){

        this->nextbtn->zoom1();
        this->nextbtn->zoom1();
        QTimer::singleShot(1000,this,[=](){
            this->close();
        });
        StartGame * startGame = new StartGame();
        startGame->show();

    });

}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::nextQuestion(){

}
