#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H
/*该类用户处理List里的Socket */
#include <QObject>
#include<QTcpSocket>
#include <QDataStream>
#include<QtNetwork>
enum MessageType{clientLeave,clientEnter,serverLeave,serverEnter,message}; //状态字
class Tcpclientsocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Tcpclientsocket(QObject *parent = 0);


signals:
    void updateClient(QString,QString,int); //第一步当有新的 tcpclientsocket创建时 就发出该信号 让server.h处理
    //void disconnected(int);//  断开连接信号，发送将要断开的socket id
    void clientOnLine(QString,QString);
    void clientOffLine(int);//
    void sendMessage(QString,QString,QString);

protected slots:
    void dataReveived(); //接收信息发出更新信号
    void slotDisconnected();// 告诉服务端有客户端断开连接
private:
    int  status; //   状态码
    int socketdescriptor; //将要断开的socketid

    QString ipAddress;
    QString hostName;
    QString msg;

};

#endif // TCPCLIENTSOCKET_H
