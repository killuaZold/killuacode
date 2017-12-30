#ifndef SERVER_H
#define SERVER_H
#include<QtNetwork/QTcpServer>
#include<QObject>
#include"tcpclientsocket.h"
#include<QDebug>


class Server:public QTcpServer
{ Q_OBJECT  //只有加入这个才能使用宏机制
public:
    Server(QObject *parent,int port=0);   //修改了原有的构造函数
    QList<Tcpclientsocket*>tcpClientSocketList;  //存放套接字ID的链表
    QList<QString>ClientIpList;  //保存所有ip
    QList<QString>ClientHostNameList; //保存所有hostname
    static QString ipAddress; //获取ip地址
    static QString hostName;
    static int deleteClinet; //将删除的用户
    //void sendMessge();
protected:
    void incomingConnection(int socketDescriptor);//重写虚函数，检测到外来TCP请求时会自动调用
public slots:
    void clientOnLine(QString,QString);
    void clientOffLine(int);
    void updateClient(QString,QString,int);  //处理tcpclientsocket的信号，发出updateserver信号告诉mainwindow更新窗口 第二部
   // void slotDisconnected(int);//断开处理函数
    void sendMessage(QString,QString,QString);
private:
    void getServerIp(); //设置服务器ip
    void getServerHostName(); //设置服务器主机名
   // void clientOffLine();//  更新所有客户机，在server.cpp  监听到断开信号和连接信号的时候操作

signals:
    void updateServer(QString,QString,int); //发出更新信号告诉mainwindow

};

#endif // SERVER_H
