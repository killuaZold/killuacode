#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QMouseEvent>
#include <QTextCharFormat>
#include<QFileDialog>
#include<QMessageBox>
#include"tcpclient.h"
#include <QColorDialog>
#define PADDING 4
enum Direction
{

    UP,
    DOWN,
    LEFT,
    RIGHT,
    LEFTTOP,
    LEFTBOTTOM,
    RIGHTBOTTOM,
    RIGHTTOP,
    NONE
};

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    tcpClient *temp;
    explicit MainWindow(QWidget *parent = 0);
        //   QList<QString>chatRecord; //以后修改有重大bug
     QString chatRecord1[20];
     QString chatRecord2[20];
     QString chatRecord3[20];
     void setAreaMovable(const QRect rt);
    ~MainWindow();
    static QString str;

private slots:
    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

    void on_ConnecttableWidget_doubleClicked(const QModelIndex &index);
    void saveMessagetoList(QString ,int);
     void showMessage(QString ,QString,int );

     void on_sendButton_clicked();

     void on_closeButton_clicked();

    // void on_fontComboBox_currentIndexChanged(const QString &arg1);
     void on_fontComboBox_currentFontChanged(QFont f);
     void on_fontsizecomboBox_currentIndexChanged(QString );
     void currentFormatChanged(const QTextCharFormat &format);

     void on_toolcolor_clicked();

     void on_toolclear_clicked();

     void on_toolblod_clicked(bool checked);

     void on_toolitalic_clicked(bool checked);

     void on_toolunderline_clicked(bool checked);

     void on_toolsave_clicked();

private:
    Ui::MainWindow *ui;
    void shoWLIstMessage(QString,int);
     bool saveFile(const QString& fileName);//保存聊天记录
    QString hostName;
    QString ipAdress;
    static int currentWindowsflag;
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
      bool m_bPressed;//鼠标按下标志（不分左右键）
      QPoint m_ptPress;//鼠标按下的初始位置
      QColor color;//颜色
    //void  sendMssage(int status);
protected slots:
    void updateClient(QString,QString,int);
signals:
     void sendMessage(QString, QString);
protected:
     void mousePressEvent(QMouseEvent *);
      void mouseMoveEvent(QMouseEvent *);
      void mouseReleaseEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H
