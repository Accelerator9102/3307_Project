#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1600,900);

    setWindowTitle("Welcome!");

    this->setStyleSheet("background-color: pink;");

    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    MyPushButton *startbtn=new MyPushButton;
    startbtn->setParent(this);
    startbtn->setText("Start!");
    startbtn->move(300,700);

    MyPushButton *closebtn=new MyPushButton;
    closebtn->setText("Close!");
    closebtn->setParent(this);
    closebtn->move(1100,700);


    connect(closebtn,&MyPushButton::clicked,[=](){
        closebtn->zoom1();
        closebtn->zoom2();
        QTimer::singleShot(500,this,[=](){
           this->close();
        });

    });

    startGame = new StartGame;


    int count=0;
    connect(startbtn,&MyPushButton::clicked,[=](){
       startbtn->zoom1();
       startbtn->zoom2();
       QTimer::singleShot(500,this,[=](){
           this->hide();
           startGame->show();
       });


    });






}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_clicked()
{

}
