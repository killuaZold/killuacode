#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"server.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_startButton_clicked();
    void updateServer(QString,QString,int);  //一打开服务器就把server发出的updateServer信号交给 mainwindow的updateserver处理

private:
    Ui::MainWindow *ui;
    Server *server;
signals:


};

#endif // MAINWINDOW_H
