#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include<QTcpSocket>
#include <QHostInfo>
#include<QDataStream>
enum MessageType{clientLeave,clientEnter,serverLeave,serverEnter,message}; //状态字
class tcpClient : public QObject
{
    Q_OBJECT
public:
    explicit tcpClient(QObject *parent = 0);
    void  newConnect();//建立连接
    void offLine(); //处理客户端断开连接
     QString ipAddress;
     QString hostName;
     QString  msg;
     int clienNum;
     int  status;

signals:
     void readMessage();
     void updateClient(QString,QString,int);
     void saveMessagetoList(QString,int);
     void showMessage(QString ,QString,int );
private:
    QTcpSocket *tcpSocket;
public slots:
  // void slotConnected();
   void slotDisconencted();
   void sendMessage(QString ,QString);

protected:
   void sendClientStatus(MessageType msgtype,QString ip="");  //带有消息类型和发送给客户端的ip
protected slots:
   void dataRecevied();
};

#endif // TCPCLIENT_H
