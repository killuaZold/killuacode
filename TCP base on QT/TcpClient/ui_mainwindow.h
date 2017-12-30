/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTableWidget *ConnecttableWidget;
    QPushButton *connectButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *closeButton;
    QPushButton *sendButton;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolblod;
    QToolButton *toolunderline;
    QToolButton *toolcolor;
    QToolButton *toolitalic;
    QToolButton *toolclear;
    QToolButton *toolfile;
    QToolButton *toolsave;
    QFontComboBox *fontComboBox;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *fontsizecomboBox;
    QPushButton *disconnectButton;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(841, 702);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/image/\350\203\214\346\231\257.png);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 70, 591, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(textBrowser);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(610, 70, 221, 591));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ConnecttableWidget = new QTableWidget(gridLayoutWidget);
        if (ConnecttableWidget->columnCount() < 3)
            ConnecttableWidget->setColumnCount(3);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/E-Mail.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(0, 0, 0, 0));
        __qtablewidgetitem->setIcon(icon);
        ConnecttableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/User.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setIcon(icon1);
        ConnecttableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ConnecttableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        ConnecttableWidget->setObjectName(QStringLiteral("ConnecttableWidget"));
        ConnecttableWidget->setStyleSheet(QString::fromUtf8("border-image: url(:/image/table\350\203\214\346\231\257.png);"));

        gridLayout->addWidget(ConnecttableWidget, 0, 0, 1, 1);

        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(120, 790, 529, 28));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 520, 591, 141));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(horizontalLayoutWidget_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(textEdit);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(380, 670, 211, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        closeButton = new QPushButton(horizontalLayoutWidget_3);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_4->addWidget(closeButton);

        sendButton = new QPushButton(horizontalLayoutWidget_3);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout_4->addWidget(sendButton);

        horizontalLayoutWidget_5 = new QWidget(centralWidget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 490, 591, 33));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolblod = new QToolButton(horizontalLayoutWidget_5);
        toolblod->setObjectName(QStringLiteral("toolblod"));
        toolblod->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\254\274\346\263\243.png);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolblod->setIcon(icon2);
        toolblod->setCheckable(true);

        horizontalLayout_2->addWidget(toolblod);

        toolunderline = new QToolButton(horizontalLayoutWidget_5);
        toolunderline->setObjectName(QStringLiteral("toolunderline"));
        toolunderline->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\254\274\346\263\243.png);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolunderline->setIcon(icon3);
        toolunderline->setCheckable(true);

        horizontalLayout_2->addWidget(toolunderline);

        toolcolor = new QToolButton(horizontalLayoutWidget_5);
        toolcolor->setObjectName(QStringLiteral("toolcolor"));
        toolcolor->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\254\274\346\263\243.png);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/textcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolcolor->setIcon(icon4);

        horizontalLayout_2->addWidget(toolcolor);

        toolitalic = new QToolButton(horizontalLayoutWidget_5);
        toolitalic->setObjectName(QStringLiteral("toolitalic"));
        toolitalic->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\254\274\346\263\243.png);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolitalic->setIcon(icon5);
        toolitalic->setCheckable(true);

        horizontalLayout_2->addWidget(toolitalic);

        toolclear = new QToolButton(horizontalLayoutWidget_5);
        toolclear->setObjectName(QStringLiteral("toolclear"));
        toolclear->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\254\274\346\263\243.png);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/Bin (empty).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolclear->setIcon(icon6);

        horizontalLayout_2->addWidget(toolclear);

        toolfile = new QToolButton(horizontalLayoutWidget_5);
        toolfile->setObjectName(QStringLiteral("toolfile"));
        toolfile->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\254\274\346\263\243.png);"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolfile->setIcon(icon7);

        horizontalLayout_2->addWidget(toolfile);

        toolsave = new QToolButton(horizontalLayoutWidget_5);
        toolsave->setObjectName(QStringLiteral("toolsave"));
        toolsave->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\254\274\346\263\243.png);"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/Floppy.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolsave->setIcon(icon8);

        horizontalLayout_2->addWidget(toolsave);

        fontComboBox = new QFontComboBox(horizontalLayoutWidget_5);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(fontComboBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        fontsizecomboBox = new QComboBox(horizontalLayoutWidget_5);
        fontsizecomboBox->setObjectName(QStringLiteral("fontsizecomboBox"));
        fontsizecomboBox->setEditable(true);

        horizontalLayout_7->addWidget(fontsizecomboBox);


        horizontalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        disconnectButton = new QPushButton(centralWidget);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));
        disconnectButton->setGeometry(QRect(120, 840, 531, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -1, 841, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/image/QQ\345\233\276\347\211\20720171227145613.png);"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        QTableWidgetItem *___qtablewidgetitem = ConnecttableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\266\210\346\201\257\346\217\220\347\244\272", 0));
        QTableWidgetItem *___qtablewidgetitem1 = ConnecttableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\344\270\273\346\234\272\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem2 = ConnecttableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "ip\345\234\260\345\235\200", 0));
        connectButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0));
        closeButton->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&C)", 0));
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201(&S)", 0));
        toolblod->setText(QApplication::translate("MainWindow", "...", 0));
        toolunderline->setText(QApplication::translate("MainWindow", "...", 0));
        toolcolor->setText(QApplication::translate("MainWindow", "...", 0));
        toolitalic->setText(QApplication::translate("MainWindow", "...", 0));
        toolclear->setText(QApplication::translate("MainWindow", "...", 0));
        toolfile->setText(QApplication::translate("MainWindow", "...", 0));
        toolsave->setText(QApplication::translate("MainWindow", "...", 0));
        fontsizecomboBox->clear();
        fontsizecomboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "11", 0)
         << QApplication::translate("MainWindow", "12", 0)
         << QApplication::translate("MainWindow", "13", 0)
         << QApplication::translate("MainWindow", "14", 0)
         << QApplication::translate("MainWindow", "15", 0)
         << QApplication::translate("MainWindow", "16", 0)
         << QApplication::translate("MainWindow", "17", 0)
         << QApplication::translate("MainWindow", "18", 0)
         << QApplication::translate("MainWindow", "19", 0)
         << QApplication::translate("MainWindow", "20", 0)
         << QApplication::translate("MainWindow", "21", 0)
         << QApplication::translate("MainWindow", "22", 0)
        );
        fontsizecomboBox->setCurrentText(QApplication::translate("MainWindow", "9", 0));
        disconnectButton->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", 0));
        label->setText(QApplication::translate("MainWindow", "                                  MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
