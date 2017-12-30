#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked() //启动服务设置服务器名，服务器ip地址
{
    qDebug()<<"第一步执行点击按钮开启服务";
    server=new Server(this,6000);
    connect(server,SIGNAL(updateServer(QString,QString,int)),this,SLOT(updateServer(QString,QString,int)));//最后一步把server发出的信号交给updateserver处理
    ui->iplabel->setText(Server::ipAddress);
    ui->hostlabel->setText(Server::hostName);

}
void MainWindow::updateServer(QString ipAddress, QString hostName,int status) //更新显示
{
    qDebug()<<status;
    if(status==clientEnter) //如果状态字是有新人加入则执行
    {
         bool IsEmpty=ui->messagetableWidget->findItems(ipAddress,Qt::MatchExactly).isEmpty();//如果没有匹配的ip地址，则添加
         if(IsEmpty)
         {
             QTableWidgetItem *host = new QTableWidgetItem(hostName);
             QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);
             ui->messagetableWidget->insertRow(0);
             ui->messagetableWidget->setItem(0,1,host);
             ui->messagetableWidget->setItem(0,2,ip);
             ui->numClientlabel->setText(tr("%1").arg(ui->messagetableWidget->rowCount()));//在线人数

         }
         else
             return;
    }
    else if(status==clientLeave)  //有人离开
    {

        ui->messagetableWidget->removeRow(Server::deleteClinet);
        ui->numClientlabel->setText(tr("%1").arg(ui->messagetableWidget->rowCount()));// 在次显示在线人数
    }

}
