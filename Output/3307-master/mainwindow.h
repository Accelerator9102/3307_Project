#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "startgame.h"
#include "mypushbutton.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    StartGame * startGame = NULL;

private slots:
    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
