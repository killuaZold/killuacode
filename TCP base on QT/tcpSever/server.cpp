#include"server.h"
Server::Server(QObject *parent,int port):QTcpServer(parent) //带有默认值参数的函数，在实现的时候，参数上是不能有值的。
{    qDebug("第二部执行server的监听服务");
     listen(QHostAddress::Any,port);//监听
     getServerIp(); //开启服务就设置ip
     getServerHostName(); //开启服务就设置主机名.



}

void Server::incomingConnection(int socketDescriptor)
{
    qDebug()<<"第三步执行连接服务，分发socket,";
    /*  当监听到有新的连接到来时，由QTcpServer调用该函数，这不同于使用nextPendingConnection
     * 首先创建一个套接字实例
     * 修改把socketiD修改
     * 再把该套接字放入List中*/
    Tcpclientsocket *tcpclientsocket=new Tcpclientsocket(this);//一旦调用就创建
    tcpclientsocket->setSocketDescriptor(socketDescriptor); /*socketDescriptor就是客户端的socketip
                                                              我猜的
                                                              然后把这个ip给tcpclientsocket
                                                              在把它存起来
                                                                       */

    tcpClientSocketList.append(tcpclientsocket);

   // qDebug()<<"ipaddress:"<<tcpclientsocket->peerAddress().toString();
    //qDebug()<<"serverip"<<tcpclientsocket->localAddress().toString();
    connect(tcpclientsocket,SIGNAL(updateClient(QString,QString,int)),this,SLOT(updateClient(QString,QString,int)));//每次新用户连接都要updatewindow
    connect(tcpclientsocket,SIGNAL(clientOnLine(QString,QString)),this,SLOT(clientOnLine(QString,QString)));
    connect(tcpclientsocket,SIGNAL(clientOffLine(int)),this,SLOT(clientOffLine(int)));
    connect(tcpclientsocket,SIGNAL(sendMessage(QString,QString,QString)),this,SLOT(sendMessage(QString,QString,QString)));



}

void Server::getServerIp()
{
    QString tempInfo =QHostInfo::localHostName(); //获取主机名
    QHostInfo info=QHostInfo::fromName(tempInfo);  //用主机名获取ip
    //ipAddress=QHostInfo::fromName(tempInfo).addresses();
    //qDebug()<<QHostInfo::fromName(tempInfo).addresses();
    foreach(QHostAddress address,info.addresses())  //撒选iPv4
    {
        if(address.protocol()==QAbstractSocket::IPv4Protocol)
        {
                ipAddress=address.toString();
                //qDebug()<<ipAddress;
        }
    }
}
void Server::getServerHostName()
{
    hostName=QHostInfo::localHostName();
}
void Server::updateClient(QString ipAddress, QString hostName,int status) /*只用来更新显示的ip地址，所以每次
                                                                    都获取LIST里的最新一条记录，但是不在这里实现
                                                                    这里只发信号，而是在客户端处理程序里实现，
                                                                    然后这里发出更新信号告诉主窗口更新*/
{

    emit updateServer(ipAddress,hostName,status); //发送信号并携带着 客户端的ip地址和主机名，这里要处理一下获取客户端的主机名和ip地址
}
/*void Server::slotDisconnected(int descriptor)

{
    qDebug()<<"do it";
    qDebug()<<descriptor;

    for(int i=0;i<tcpClientSocketList.count();i++)
    {
       QTcpSocket *item=tcpClientSocketList.at(i);

        qDebug()<<item->socketDescriptor();
        if(item->socketDescriptor()==descriptor)  //把要删除的id和list里的id进行比较
        {
            qDebug()<<"delete";
            tcpClientSocketList.removeAt(i);
            ClientIpList.removeAt(i);
            ClientHostNameList.removeAt(i);
            qDebug()<<ClientIpList.at(i);
            deleteClinet=i;
            clientOffLine();  //一旦断开就向所有客户端广播

            return;
        }
    }
    return;
}*/
/*void Server::clientOffLine()
{

    for(int i=0;i<tcpClientSocketList.count();i++)
    {

        QTcpSocket*item =tcpClientSocketList.at(i);
        QByteArray data;
        QDataStream out(&data,QIODevice::WriteOnly);
        out<<clientLeave<<deleteClinet;
        item->write(data);

  }
}*/
void Server::clientOnLine(QString ipAddress,QString hostName)  //循环把所有服务端所有在线的连接告诉客户端
{
    qDebug()<<"把ip告诉别的客户端"<<ipAddress;
    ClientIpList.append(ipAddress);  //把新用户的ip和hostname记录下来
    ClientHostNameList.append(hostName);

    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        qDebug()<<"已存ip"<<ClientIpList.at(i);
        QTcpSocket*item =tcpClientSocketList.at(i);
        QByteArray data;
        QDataStream out(&data,QIODevice::WriteOnly);
        for(int j=0;j<ClientIpList.count();j++)
        {

            out<<clientEnter<<ClientIpList.at(j)<<ClientHostNameList.at(j);

            out.device()->seek(0);
            qDebug()<<ClientIpList.at(j);//把服务端所有信息告诉客户端
             item->write(data);

            item->waitForBytesWritten();
        }
    }
}
  /*  QByteArray data;                                //临时写入测试
    QDataStream out(&data,QIODevice::WriteOnly);
    out<<message<<"sadas"<<1;
    QString str=QString::fromLocal8Bit(data);
    qDebug()<<str;
    qDebug()<<"write";

    QTcpSocket*item =tcpClientSocketList.at(0);
    qDebug()<<"临时消息id"<<item->socketDescriptor();
    qDebug()<<data;

   if(item->write(data)==-1)
   {
       qDebug()<<"写入失败";
   }
*/


void Server::clientOffLine(int descriptor)
{

    QString tempdeleteclientip;//正真删除的ip
   int count=0;
    qDebug()<<descriptor;

    for(int i=0;i<tcpClientSocketList.count();i++)  //删除套接字
    {
       QTcpSocket *item=tcpClientSocketList.at(i);

        qDebug()<<item->socketDescriptor();
        if(item->socketDescriptor()==descriptor)  //把要删除的id和list里的id进行比较
        {
            qDebug()<<"删除谁"<<descriptor;
            qDebug()<<tcpClientSocketList.count();
           // tempdeleteclientip=tcpClientSocketList.count()
            count=tcpClientSocketList.count();
            tcpClientSocketList.removeAt(i);
            tempdeleteclientip=ClientIpList.at(i);
            ClientIpList.removeAt(i);

            ClientHostNameList.removeAt(i);     //因为存储的方向刚好和显示的方向相反，因为删除第一个，应该在显示里删除最后一个


            deleteClinet=(count-1)-i;
            qDebug()<<"删除窗口"<<deleteClinet;
            qDebug()<<"删除ip"<<tempdeleteclientip;
        }
    }
    for(int i=0;i<tcpClientSocketList.count();i++)   //如有用户广播下线
    {


        QTcpSocket *item=tcpClientSocketList.at(i);
        QByteArray data;
        QDataStream out(&data,QIODevice::WriteOnly);
        qDebug()<<clientLeave<<"下线信号";
        qDebug()<<i<<"告诉谁"<<item->socketDescriptor();

        out<<clientLeave<<tempdeleteclientip;
        out.device()->seek(0);

        item->write(data);

        item->waitForBytesWritten();
    }
    return;
}
void Server::sendMessage(QString ipAdress, QString hostName,QString msg )  //用hostname找原窗口，ipaddress找目的窗口
{
     int clientnum=0;
     qDebug()<<hostName;
     QString clientHost;
     qDebug()<<"数据个数"<<ClientHostNameList.count();
     for(int i=0;i<ClientHostNameList.count();i++)  //找到原地址窗口
    {
        if(hostName==ClientHostNameList.at(i))
           {  clientnum=(ClientHostNameList.count()-1)-i;// 下标从0开始  但是总数有两个
            qDebug()<<"找到相同的窗口"<<i;
            break;
            }
    }
    for(int i=0;i<tcpClientSocketList.count();i++)        //找到目的地址套接字
    {
        QTcpSocket *item=tcpClientSocketList.at(i);
        if(ipAdress==ClientIpList.at(i))      //目的ip
        {
            QByteArray data;
            QDataStream out(&data,QIODevice::WriteOnly);

            clientHost=ClientHostNameList.at(i);          //目的hostname
            out<<message<<hostName<<msg<<clientnum; //转发 原地址hostName，目的窗口第几个
              qDebug()<<"原地址窗口"<<clientnum<<"发给谁"<<clientHost;
              out.device()->seek(0);                       //等到真正写入的时候才再次写,等待前面的写完
              item->write(data);
              item->waitForBytesWritten();
              break;

        }

    }
}
QString  Server::hostName=0;
QString Server::ipAddress=0;
int Server::deleteClinet=0;
