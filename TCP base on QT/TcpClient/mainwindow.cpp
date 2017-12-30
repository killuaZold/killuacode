#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"tcpclient.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setWindowFlags(Qt::FramelessWindowHint);//无边框
      setAttribute(Qt::WA_TranslucentBackground);//背景透明
      temp=new tcpClient(this); //java的写法
      connect(temp,SIGNAL(updateClient(QString,QString,int)),this,SLOT(updateClient(QString,QString,int)));
      connect(temp,SIGNAL(showMessage(QString,QString,int)),this,SLOT(showMessage(QString,QString,int)));
      connect(this,SIGNAL(sendMessage(QString,QString)),temp,SLOT(sendMessage(QString,QString)));
      qDebug()<<"this is MainWindow";

      ui->textEdit->setFocusPolicy(Qt::StrongFocus);
      ui->textBrowser->setFocusPolicy(Qt::NoFocus);

      ui->textEdit->setFocus();
      ui->textEdit->installEventFilter(this);
      m_areaMovable = geometry();
      m_bPressed = false;
        qDebug()<<m_areaMovable;
   // for(int i=0;i<60;i++)
     //  chatRecord.append("-1"); //初始化一个链表
        for(int i=0;i<20;i++)
        {
            chatRecord1[i]="-1";
            chatRecord2[i]="-1";
            chatRecord3[i]="-1";
        }

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{

   temp=new tcpClient(this); //java的写法
   connect(temp,SIGNAL(updateClient(QString,QString,int)),this,SLOT(updateClient(QString,QString,int)));
   connect(temp,SIGNAL(showMessage(QString,QString,int)),this,SLOT(showMessage(QString,QString,int)));
   connect(this,SIGNAL(sendMessage(QString,QString)),temp,SLOT(sendMessage(QString,QString)));
   connect(ui->textEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(currentFormatChanged(const QTextCharFormat)));
   qDebug()<<"this is MainWindow";


}




void MainWindow::on_disconnectButton_clicked()
{
    temp->offLine();
    ui->ConnecttableWidget->setRowCount(0);
    ui->ConnecttableWidget->clearContents();
}

void MainWindow::updateClient(QString ipAddress,QString hostName,int status)
{
    switch(status)
    {
    case clientEnter:
                    {

                        qDebug()<<"添加ip比较哪一步"<<ipAddress;
                        bool IsEmpty=ui->ConnecttableWidget->findItems(ipAddress,Qt::MatchExactly).isEmpty();//如果没有匹配的ip地址，则添加
                        qDebug()<<IsEmpty;
                        if(IsEmpty)
                        {

                            QTableWidgetItem *host = new QTableWidgetItem(hostName);
                            QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);
                           // QTableWidgetItem *item = new QTableWidgetItem();
                           //item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                         //   ui->ConnecttableWidget->setItem(0,1,item);
                           // ui->ConnecttableWidget->setItem(0,2,item);

                            ui->ConnecttableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑

                            ui->ConnecttableWidget->insertRow(0);
                            ui->ConnecttableWidget->setItem(0,1,host);
                            ui->ConnecttableWidget->setItem(0,2,ip);
                        }
                        else
                             break;
                        break;
                    }
    case clientLeave:
                    {
                       for(int i=0;i<ui->ConnecttableWidget->rowCount();i++)
                       {
                          if(ui->ConnecttableWidget->item(i,2)->text()==ipAddress)
                          {
                              ui->ConnecttableWidget->removeRow(i);
                              break;
                          }
                       }
                       break;



    }
}
}



void MainWindow::on_ConnecttableWidget_doubleClicked(const QModelIndex &index)
{

   // QString ipAdress=ui->ConnecttableWidget->item(index.row(),2)->text();//获得该行的ip地址
    hostName=ui->ConnecttableWidget->item(index.row(),1)->text();//获得主机名
    ipAdress=ui->ConnecttableWidget->item(index.row(),2)->text();
    int num=ui->ConnecttableWidget->currentRow(); //获得点击第几个窗口

    qDebug()<<"第几个窗口"<<num;
    ui->textBrowser->clear();
    currentWindowsflag=num; //改变窗口
    shoWLIstMessage(hostName,num);  //查看别的窗口的信息，一次全部输出，这时候如果有该窗口的信息，会直接显示，如果别的信息则调用save·
    qDebug()<<"双击";


}
void MainWindow::saveMessagetoList(QString msg, int num)//如果现在的窗口为接收窗口则直接显示，否则调用savemessage
{
     QTableWidgetItem *getMessage = new QTableWidgetItem("有新消息");
     ui->ConnecttableWidget->setItem(num,0,getMessage);
   /*if(num==0)          //不同的客户端存到链表的不同部分，
   {
      for(int i=0;i<20;i++)
          if(chatRecord.at(i)=="-1")
             {

              chatRecord.insert(i,msg);
              qDebug()<<"链表的位置"<<chatRecord.at(i);
              qDebug()<<"链表的下一个位置"<<chatRecord.at(i+1);
              break;
           }

   }
   else if(num==1)
       for(int i=20;i<40;i++)
           if(chatRecord.at(i)=="-1")
           {
               chatRecord.insert(i,msg);
               qDebug()<<"链表的位置"<<chatRecord.at(i);
               qDebug()<<"链表的下一个位置"<<chatRecord.at(i+1);
               break;
           }
   else if(num==2)
               for(int i=40;i<60;i++)
                   if(chatRecord.at(i)=="-1")
                     {

                       chatRecord.insert(i,msg);
                       break;
                   }*/
    if(num==0)
    {
        qDebug()<<msg;
        //qDebug()<<chatRecord1[i];
        for(int i=0;i<20;i++)
        {
            if(chatRecord1[i]=="-1")
            {
                chatRecord1[i]=msg;
                qDebug()<<i<<"存入多少次";
                break;
            }
        }
    }
    else if(num==1)
    {
        for(int i=0;i<20;i++)
        {
            if(chatRecord2[i]=="-1")
            {
                chatRecord2[i]=msg;
                break;
            }
        }
    }

    else if(num==2)
    {
        for(int i=0;i<20;i++)
        {
            if(chatRecord3[i]=="-1")
            {
                chatRecord3[i]=msg;
                break;
            }
        }
    }

}
void MainWindow::showMessage(QString name, QString msg ,int num)
{
    //ui->ConnecttableWidget->item(num,0)->setBackgroundColor(QBrush(QColor(255, 0, 0)));



    qDebug()<<currentWindowsflag;
    qDebug()<<num;    //当前窗口与发来信息的窗口
    if(num==currentWindowsflag)     //发送信息的窗口和当前窗口时否相同
    {
        QString time=QDateTime::currentDateTime().toString("yyy-MM-dd hh:mm:ss" );
        ui->textBrowser->setTextColor(Qt::blue);
        ui->textBrowser->setCurrentFont(QFont("Time New Roman",12));
              //如果是第一个发过来的信息直接显示
         ui->textBrowser->append("[ "+name+" ]"+time);
         ui->textBrowser->append(msg);


    }
    else

        saveMessagetoList(msg,num);   //如果在当前窗口时别的窗口来了消息，就会存到链表里

      /*  QString time=QDateTime::currentDateTime().toString("yyy-MM-dd hh:mm:ss" );
        ui->textBrowser->setTextColor(Qt::blue);
        ui->textBrowser->setCurrentFont(QFont("Time New Roman",12));
              //如果是第一个发过来的信息直接显示
        if(num==0)
        {
            for(int i=0;i<20;i++)
                if(chatRecord.at(i)=="-1")
                    continue;
                else
                  {  ui->textBrowser->append("[ "+name+" ]"+time);
                     ui->textBrowser->append(chatRecord.at(i));
                     chatRecord.insert(i,"-1");

                  }
        }
       else if(num==1)
        {
            for(int i=20;i<40;i++)
                if(chatRecord.at(i)=="-1")
                    continue;
                else
                  {  ui->textBrowser->append("[ "+name+" ]"+time);
                     ui->textBrowser->append(chatRecord.at(i));
                     chatRecord.insert(i,"-1");

                  }
        }
        else if(num==2)
         {
             for(int i=40;i<60;i++)
                 if(chatRecord.at(i)=="-1")
                     continue;
                 else
                   {  ui->textBrowser->append("[ "+name+" ]"+time);
                      ui->textBrowser->append(chatRecord.at(i));
                      chatRecord.insert(i,"-1");

                   }
         }
    }
    */


}
void MainWindow::shoWLIstMessage(QString name,int num)
{
    ui->label->setText("                                   "+name);
    QString time=QDateTime::currentDateTime().toString("yy-MM-dd hh:mm:ss" );
    ui->textBrowser->setTextColor(Qt::blue);
    ui->textBrowser->setCurrentFont(QFont("Time New Roman",9));
    QTableWidgetItem *getMessage = new QTableWidgetItem("  ");
    ui->ConnecttableWidget->setItem(num,0,getMessage);
    qDebug()<<"LIST输出的多少次";
    qDebug()<<num;
    qDebug()<<chatRecord1[0];
          //如果是第一个发过来的信息直接显示
  /*  if(num==0)
    {
        QString str="-1";
        for(int i=0;i<20;i++)
        {
            qDebug()<<str;
            qDebug()<<chatRecord.at(i);

            if(chatRecord.at(i)=="-1")
               {

              break;
             }
            else
              {
                ui->textBrowser->append("[ "+name+" ]"+time);
                                 ui->textBrowser->append(chatRecord.at(i));
                                  qDebug()<<i<<"i是多少";
                                  qDebug()<<"链表内容是什么"<<chatRecord.at(i);
                                  qDebug()<<"链表下一个位置内容"<<chatRecord.at(i+1);
                                  chatRecord.insert(i,"-1");
                                 qDebug()<<"链表输出了多少次";
              }
        }

    }
   else if(num==1)
    {
        for(int i=20;i<40;i++)
        {
            if(chatRecord.at(i)=="-1")
                continue;
            else
              {  ui->textBrowser->append("[ "+name+" ]"+time);
                 ui->textBrowser->append(chatRecord.at(i));
                 chatRecord.insert(i,"-1");

              }
        }
    }
    else if(num==2)
     {
         for(int i=40;i<60;i++)
         {
             if(chatRecord.at(i)=="-1")
                 continue;
             else
               {  ui->textBrowser->append("[ "+name+" ]"+time);
                  ui->textBrowser->append(chatRecord.at(i));
                  chatRecord.insert(i,"-1");

               }
         }
     }
    return;*/

    if(num==0)
    {
        for(int i=0;i<20;i++)
        {
            if(chatRecord1[i]!="-1")
            {
                qDebug()<<chatRecord1[i];
                ui->textBrowser->append("[ "+name+" ]"+time);
                 ui->textBrowser->append(chatRecord1[i]);
                 chatRecord1[i]="-1";
                  qDebug()<<i<<"i是多少";
                  /* qDebug()<<"链表内容是什么"<<chatRecord.at(i);
                                  qDebug()<<"链表下一个位置内容"<<chatRecord.at(i+1);
                                  chatRecord.insert(i,"-1");
                                 qDebug()<<"链表输出了多少次";*/
            }
        }
    }
    else if(num==1)
    {
        for(int i=0;i<20;i++)
        {
            if(chatRecord2[i]!="-1")
            {
                ui->textBrowser->append("[ "+name+" ]"+time);
                 ui->textBrowser->append(chatRecord2[i]);
                 chatRecord2[i]="-1";
                  qDebug()<<i<<"i是多少";
                  /* qDebug()<<"链表内容是什么"<<chatRecord.at(i);
                                  qDebug()<<"链表下一个位置内容"<<chatRecord.at(i+1);
                                  chatRecord.insert(i,"-1");
                                 qDebug()<<"链表输出了多少次";*/
            }
        }
    }
    else if(num==2)
    {
        for(int i=0;i<20;i++)
        {
            if(chatRecord3[i]!="-1")
            {
                ui->textBrowser->append("[ "+name+" ]"+time);
                 ui->textBrowser->append(chatRecord3[i]);
                 chatRecord3[i]="-1";
                  qDebug()<<i<<"i是多少";
                  /* qDebug()<<"链表内容是什么"<<chatRecord.at(i);
                                  qDebug()<<"链表下一个位置内容"<<chatRecord.at(i+1);
                                  chatRecord.insert(i,"-1");
                                 qDebug()<<"链表输出了多少次";*/
            }
        }
    }
}


int MainWindow::currentWindowsflag=0;

void MainWindow::on_sendButton_clicked()
{
    QString msg=ui->textEdit->toPlainText();
    QString time=QDateTime::currentDateTime().toString("yy-MM-dd hh:mm:ss");
    QString name=QHostInfo::localHostName();
    ui->textBrowser->setTextColor(Qt::darkGreen);
    ui->textBrowser->setCurrentFont(QFont("Time New Roman",9));
    ui->textBrowser->append("                                     [ "+name+" ]"+time);
    ui->textBrowser->append("                                     "+ui->textEdit->toPlainText());
    ui->textEdit->clear();
    qDebug()<<"发给谁"<<ipAdress;
    emit sendMessage(ipAdress,msg);

}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
  //鼠标左键
  if(e->button() == Qt::LeftButton)
  {
  m_ptPress = e->pos();
  qDebug() << pos() << e->pos() << m_ptPress;
  m_bPressed = m_areaMovable.contains(m_ptPress);
  }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
  if(m_bPressed)
  {
  qDebug() << pos() << e->pos() << m_ptPress;
  move(pos() + e->pos() - m_ptPress);
  }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
  m_bPressed = false;
}

//设置鼠标按下的区域
void MainWindow::setAreaMovable(const QRect rt)
{
  if(m_areaMovable != rt)
  {
  m_areaMovable = rt;
  }
}

void MainWindow::on_closeButton_clicked()
{
    temp->offLine();
    ui->ConnecttableWidget->setRowCount(0);
    ui->ConnecttableWidget->clearContents();
    close();
}

void MainWindow:: on_fontComboBox_currentFontChanged(QFont f)
{
    ui->textEdit->setCurrentFont(f);
    ui->textEdit->setFocus();
}
void MainWindow::on_fontsizecomboBox_currentIndexChanged(QString size)
{
   ui->textEdit->setFontPointSize(size.toDouble());
   ui->textEdit->setFocus();
}
void MainWindow::currentFormatChanged(const QTextCharFormat &format)
{
    ui->fontComboBox->setCurrentFont(format.font());

    if(format.fontPointSize()<9)  //����������С��������Ϊ������С������Ϊ9
        ui->fontsizecomboBox->setCurrentIndex(3); //����ʾ12
    else ui->fontsizecomboBox->setCurrentIndex(
            ui->fontsizecomboBox->findText(QString::number(format.fontPointSize())));

    ui->toolblod->setChecked(format.font().bold());
    ui->toolitalic->setChecked(format.font().italic());
    ui->toolunderline->setChecked(format.font().underline());
    color = format.foreground().color();
}




void MainWindow::on_toolcolor_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
        ui->textEdit->setFocus();
    }
}



void MainWindow::on_toolclear_clicked()
{
    ui->textBrowser->clear();
}

void MainWindow::on_toolblod_clicked(bool checked)
{

    if(checked)
       ui->textEdit->setFontWeight(QFont::Bold);
    else
        ui->textEdit->setFontWeight(QFont::Normal);
    ui->textEdit->setFocus();
}

void MainWindow::on_toolitalic_clicked(bool checked)
{
    ui->textEdit->setFontItalic(checked);
    ui->textEdit->setFocus();
}

void MainWindow::on_toolunderline_clicked(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
    ui->textEdit->setFocus();
}

void MainWindow::on_toolsave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),tr("未命名"),tr("txt(*.txt);;All File(*.*)"));
    if(!fileName.isEmpty())
        saveFile(fileName);
}
bool MainWindow::saveFile(const QString &fileName)//???????
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))

    {
        QMessageBox::warning(this,tr("???????"),
        tr("?????????? %1:\n %2").arg(fileName)
        .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << ui->textBrowser->toPlainText();

    return true;
}
