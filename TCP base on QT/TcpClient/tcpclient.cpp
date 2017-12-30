#include "tcpclient.h"

tcpClient::tcpClient(QObject *parent)
{
    tcpSocket=new QTcpSocket(this);
    newConnect();
}
void tcpClient::newConnect()
{


    tcpSocket->connectToHost("10.108.14.158",6000);
    qDebug()<<"this  is id"<<tcpSocket->socketDescriptor();
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataRecevied()));//两个信号需要有相同参数类型,一旦缓冲区有数据就会自动调用readdata（）
    //connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected())); //当有新连接时就调用slotConnected处理
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconencted()));

    sendClientStatus(clientEnter);
    qDebug()<<"hllow";
}

/*void tcpClient::readdata()
{
    QByteArray block;
    block=tcpSocket->readAll();
   MainWindow:: str =  QString::fromLocal8Bit(block);
    //qDebug()<<block;
    qDebug()<<MainWindow::str;

}*/
/*void tcpClient::sendClientIp_hostName()
{

    QString tempInfo =QHostInfo::localHostName(); //获取主机名
    QHostInfo info=QHostInfo::fromName(tempInfo);  //用主机名获取ip
    hostName=tempInfo;
    //ipAddress=QHostInfo::fromName(tempInfo).addresses();
    //qDebug()<<QHostInfo::fromName(tempInfo).addresses();
    foreach(QHostAddress address,info.addresses())  //撒选iPv4
    {
        if(address.protocol()==QAbstractSocket::IPv4Protocol)
        {
                ipAddress=address.toString();
        }
    }
       //获取ip和hostname完毕，下面用流方法法写入
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    out<<hostName<<ipAddress;    //读的时候回根据顺序读，这样就可以一起发过去并且分割了
    tcpSocket->write(data);
    qDebug()<<hostName;
    qDebug()<<ipAddress;
}*/

/*void tcpClient::slotConnected()
{
    type=clientEnter;  //当前为新客户加入
    qDebug()<<type;
}*/

void tcpClient::slotDisconencted()      //发送一个离开请求
{


    qDebug()<<"first";
    //获取ip和hostname完毕，下面用流方法法写入
}

void tcpClient::offLine()
{
    QString ip;
        QString tempInfo=QHostInfo::localHostName();
        QHostInfo info=QHostInfo::fromName(tempInfo);
        foreach(QHostAddress address,info.addresses())
        {
            if(address.protocol()==QAbstractSocket::IPv4Protocol)
                ip=address.toString();

        }
       sendClientStatus(clientLeave,ip); //在将要断开之前发送状态字给服务器 然后再断
       tcpSocket->disconnectFromHost();  //发出断开信号
       tcpSocket->waitForDisconnected();




        qDebug()<<"offline";

}

void tcpClient::sendClientStatus(MessageType msgtype, QString ip)
{
        /* QByteArray data;
         QDataStream out(&data,QIODevice::WriteOnly);
         qDebug()<<msgtype;*/
         switch(msgtype)
    {
         case clientEnter:
        {
             QByteArray data;
             QDataStream out(&data,QIODevice::WriteOnly);
             qDebug()<<msgtype;
          qDebug()<<"cliententer";
         QString tempInfo =QHostInfo::localHostName(); //获取主机名
         QHostInfo info=QHostInfo::fromName(tempInfo);  //用主机名获取ip
         hostName=tempInfo;
         //ipAddress=QHostInfo::fromName(tempInfo).addresses();
         //qDebug()<<QHostInfo::fromName(tempInfo).addresses();
         foreach(QHostAddress address,info.addresses())  //撒选iPv4
         {
             if(address.protocol()==QAbstractSocket::IPv4Protocol)
             {
                     ipAddress=address.toString();
             }
         }
         out<<msgtype<<ipAddress<<hostName;
         out.device()->seek(0);
         qDebug()<<hostName<<ipAddress<<msgtype;
         qDebug()<<data;
         tcpSocket->write(data); //如果是新连接消息就把客户端的信息写入 type用来告诉服务端是什么信息
         break;
       }
         case clientLeave:
        {

             QByteArray data;
             QDataStream out(&data,QIODevice::WriteOnly);
             qDebug()<<msgtype;
             out<<msgtype<<ip; //断开前先告诉服务端即将要断开
             out.device()->seek(0);
             tcpSocket->write(data);
             qDebug()<<data;

             break;
        }

    }
}
void tcpClient::dataRecevied()
{
   QDataStream in(tcpSocket);
   in>>status;
   if(status==5242947)
       in>>status;
   qDebug()<<"recie";

   qDebug()<<status;
   switch(status)
   {
        case clientEnter:
                   {

                    //第二次接到了状态没接到ip
                      in>>ipAddress>>hostName; //当有新客户端连接时，把自己的存在告诉服务器，服务器再次向全部客户端转发


                      emit updateClient(ipAddress,hostName,status);
                      break;
                   }
         case clientLeave:
                   {
                       in>>ipAddress;
                       qDebug()<<"删除ip"<<ipAddress;
                       emit updateClient(ipAddress,hostName,status);
                       break;
                   }
       case message:  //当接收到信息来时改变信息发送方那一行的颜色，需要接收发送的信息 还有一个clientnum 表示法给谁，然后交给update处理
                   {
                          in>>hostName>>msg>>clienNum;  //原地址hostname，目的窗口
                          qDebug()<<"coming num";
                          qDebug()<<clienNum;
                         // QString str=tcpSocket->readAll();

                          emit showMessage(hostName,msg,clienNum); //主机名，消息，对方的窗口号
                          break;
                   }

   }

}
void tcpClient::sendMessage(QString ipAdress,QString msg) //发送ip和msg过去给服务端


{
    QString hostname=QHostInfo::localHostName(); //用hostname 查找原地址窗口，用ip找目的窗口
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    out<<message<<ipAdress<<hostname<<msg;
    qDebug()<<"发给谁"<<ipAdress<<"谁发的"<<hostname;
    out.device()->seek(0);
    tcpSocket->waitForBytesWritten();
    tcpSocket->write(data);
    qDebug()<<msg;
    qDebug()<<"成功写入";

}
