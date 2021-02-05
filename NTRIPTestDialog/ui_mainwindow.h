/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon Feb 7 14:39:15 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *tbDataFeed;
    QPushButton *pbConnect;
    QPushButton *pbQuit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *leHostIP;
    QLineEdit *leHostPort;
    QLineEdit *leUserid;
    QLineEdit *lePassword;
    QLineEdit *leMount;
    QLineEdit *leTimeout;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelIP;
    QLabel *labelPort;
    QLabel *labelID;
    QLabel *labelPW;
    QLabel *labelMountPt;
    QLabel *labelTimeout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(692, 527);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tbDataFeed = new QTextBrowser(centralWidget);
        tbDataFeed->setObjectName(QString::fromUtf8("tbDataFeed"));
        tbDataFeed->setGeometry(QRect(10, 210, 671, 211));
        pbConnect = new QPushButton(centralWidget);
        pbConnect->setObjectName(QString::fromUtf8("pbConnect"));
        pbConnect->setGeometry(QRect(10, 430, 91, 31));
        pbQuit = new QPushButton(centralWidget);
        pbQuit->setObjectName(QString::fromUtf8("pbQuit"));
        pbQuit->setGeometry(QRect(580, 430, 101, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 10, 129, 188));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        leHostIP = new QLineEdit(layoutWidget);
        leHostIP->setObjectName(QString::fromUtf8("leHostIP"));

        verticalLayout->addWidget(leHostIP);

        leHostPort = new QLineEdit(layoutWidget);
        leHostPort->setObjectName(QString::fromUtf8("leHostPort"));

        verticalLayout->addWidget(leHostPort);

        leUserid = new QLineEdit(layoutWidget);
        leUserid->setObjectName(QString::fromUtf8("leUserid"));

        verticalLayout->addWidget(leUserid);

        lePassword = new QLineEdit(layoutWidget);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));

        verticalLayout->addWidget(lePassword);

        leMount = new QLineEdit(layoutWidget);
        leMount->setObjectName(QString::fromUtf8("leMount"));

        verticalLayout->addWidget(leMount);

        leTimeout = new QLineEdit(layoutWidget);
        leTimeout->setObjectName(QString::fromUtf8("leTimeout"));

        verticalLayout->addWidget(leTimeout);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 101, 191));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelIP = new QLabel(layoutWidget1);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelIP->setFont(font);
        labelIP->setFrameShape(QFrame::Panel);
        labelIP->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(labelIP);

        labelPort = new QLabel(layoutWidget1);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setFont(font);
        labelPort->setFrameShape(QFrame::Panel);
        labelPort->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(labelPort);

        labelID = new QLabel(layoutWidget1);
        labelID->setObjectName(QString::fromUtf8("labelID"));
        labelID->setFont(font);
        labelID->setFrameShape(QFrame::Panel);
        labelID->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(labelID);

        labelPW = new QLabel(layoutWidget1);
        labelPW->setObjectName(QString::fromUtf8("labelPW"));
        labelPW->setFont(font);
        labelPW->setFrameShape(QFrame::Panel);
        labelPW->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(labelPW);

        labelMountPt = new QLabel(layoutWidget1);
        labelMountPt->setObjectName(QString::fromUtf8("labelMountPt"));
        labelMountPt->setFont(font);
        labelMountPt->setFrameShape(QFrame::Panel);
        labelMountPt->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(labelMountPt);

        labelTimeout = new QLabel(layoutWidget1);
        labelTimeout->setObjectName(QString::fromUtf8("labelTimeout"));
        labelTimeout->setFont(font);
        labelTimeout->setFrameShape(QFrame::Panel);
        labelTimeout->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(labelTimeout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 692, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(leHostIP, leHostPort);
        QWidget::setTabOrder(leHostPort, leUserid);
        QWidget::setTabOrder(leUserid, lePassword);
        QWidget::setTabOrder(lePassword, leMount);
        QWidget::setTabOrder(leMount, leTimeout);
        QWidget::setTabOrder(leTimeout, pbConnect);
        QWidget::setTabOrder(pbConnect, pbQuit);
        QWidget::setTabOrder(pbQuit, tbDataFeed);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pbConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        pbQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        labelIP->setText(QApplication::translate("MainWindow", "Host IP:", 0, QApplication::UnicodeUTF8));
        labelPort->setText(QApplication::translate("MainWindow", "Host Port:", 0, QApplication::UnicodeUTF8));
        labelID->setText(QApplication::translate("MainWindow", "Userid:", 0, QApplication::UnicodeUTF8));
        labelPW->setText(QApplication::translate("MainWindow", "Password:", 0, QApplication::UnicodeUTF8));
        labelMountPt->setText(QApplication::translate("MainWindow", "Mount Point:", 0, QApplication::UnicodeUTF8));
        labelTimeout->setText(QApplication::translate("MainWindow", "Timeout:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
