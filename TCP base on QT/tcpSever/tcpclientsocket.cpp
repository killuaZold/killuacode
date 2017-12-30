#include "tcpclientsocket.h"

Tcpclientsocket::Tcpclientsocket(QObject *parent)
{
  qDebug()<<"第四步创建处理客户端实例，监听接收接收消息和断开消息信号";
  connect(this,SIGNAL(readyRead()),this,SLOT(dataReveived())); //当缓冲区有数据来时就读
  connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));//连接信号，当有断开信息时，交给自定义函数处理

}
void Tcpclientsocket::dataReveived() //到时候用状态字来判断这个是什么样的信号
{ 

    QDataStream in(this);
    in>>status; //接收状态字 确定做什么动作
    //in.device()->seek(0);
    qDebug()<<status<<"做什么";
    switch(status)
    {
            case clientEnter:       //一旦有新客户端进入要告诉别的客户端 有新客户端来临,转到server.cpp里操作利用list里的socket
                           {
                               in>>ipAddress>>hostName;
                               //qDebug()<<ipAddress;
                               //qDebug()<<hostName;

                               emit clientOnLine(ipAddress,hostName);
                               emit updateClient(ipAddress,hostName,status);
                               //emit sendMessage(ipAddress,"hello");
                               qDebug()<<"send";
                               break;
                           }

            case clientLeave:           //一旦有新客户端离开要是别的客户端 有客户端离开
                           {
                             //  in>>socketDescriptor; //获取将要删除的id
                               in>>ipAddress;  //将要删除的ip  方便告诉别的客户端
                               qDebug()<<this->socketDescriptor();
                               qDebug()<<"将要删除的";
                               socketdescriptor=this->socketDescriptor(); //该链接的id
                               emit clientOffLine(socketdescriptor);//因为是已经断开了才会触发这个信号，当然获取不到socketid啦
                               emit updateClient(ipAddress,hostName,status);

                               break;
                           }
            case message:          //接收客户端传来的num
           {
             in>>ipAddress>>hostName>>msg;  //
             emit sendMessage(ipAddress,hostName,msg);   //消息转发
             break;
    }

    }


}
/*void Tcpclientsocket::slotDisconnected()   //在list中删除该记录
{

   qDebug()<<"disconnected";
}
*/
