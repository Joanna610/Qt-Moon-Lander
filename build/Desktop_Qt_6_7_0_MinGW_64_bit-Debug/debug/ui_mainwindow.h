/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Tab1;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_8;
    QLabel *x;
    QListWidget *X_value;
    QHBoxLayout *horizontalLayout_9;
    QLabel *y;
    QListWidget *Y_value;
    QHBoxLayout *horizontalLayout_10;
    QLabel *z;
    QListWidget *Z_value;
    QListWidget *listWidget_4;
    QLabel *label;
    QComboBox *PortChoice;
    QPushButton *openPort;
    QPushButton *closePort;
    QListWidget *angle_xy;
    QListWidget *angle_xz;
    QListWidget *angle_yz;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *TurnOnEngine;
    QPushButton *TurnOffEngine;
    QLabel *label_4;
    QWidget *Tab2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QChartView *chartView_x;
    QChartView *chartView_y;
    QChartView *chartView_z;
    QLabel *german;
    QLabel *english;
    QLabel *dott;
    QLabel *connection;
    QLabel *cosmos;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(635, 10, 351, 630));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);
        Tab1 = new QWidget();
        Tab1->setObjectName("Tab1");
        horizontalLayoutWidget_5 = new QWidget(Tab1);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(20, 310, 311, 31));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        x = new QLabel(horizontalLayoutWidget_5);
        x->setObjectName("x");

        horizontalLayout_8->addWidget(x);

        X_value = new QListWidget(horizontalLayoutWidget_5);
        X_value->setObjectName("X_value");
        X_value->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_8->addWidget(X_value);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        y = new QLabel(horizontalLayoutWidget_5);
        y->setObjectName("y");

        horizontalLayout_9->addWidget(y);

        Y_value = new QListWidget(horizontalLayoutWidget_5);
        Y_value->setObjectName("Y_value");

        horizontalLayout_9->addWidget(Y_value);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        z = new QLabel(horizontalLayoutWidget_5);
        z->setObjectName("z");

        horizontalLayout_10->addWidget(z);

        Z_value = new QListWidget(horizontalLayoutWidget_5);
        Z_value->setObjectName("Z_value");

        horizontalLayout_10->addWidget(Z_value);


        horizontalLayout_9->addLayout(horizontalLayout_10);


        horizontalLayout_8->addLayout(horizontalLayout_9);


        horizontalLayout_11->addLayout(horizontalLayout_8);

        listWidget_4 = new QListWidget(Tab1);
        listWidget_4->setObjectName("listWidget_4");
        listWidget_4->setGeometry(QRect(15, 11, 321, 251));
        label = new QLabel(Tab1);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 350, 121, 21));
        PortChoice = new QComboBox(Tab1);
        PortChoice->setObjectName("PortChoice");
        PortChoice->setGeometry(QRect(20, 270, 131, 31));
        PortChoice->setIconSize(QSize(16, 16));
        openPort = new QPushButton(Tab1);
        openPort->setObjectName("openPort");
        openPort->setGeometry(QRect(160, 270, 81, 31));
        closePort = new QPushButton(Tab1);
        closePort->setObjectName("closePort");
        closePort->setGeometry(QRect(250, 270, 81, 31));
        angle_xy = new QListWidget(Tab1);
        angle_xy->setObjectName("angle_xy");
        angle_xy->setGeometry(QRect(220, 350, 111, 21));
        angle_xz = new QListWidget(Tab1);
        angle_xz->setObjectName("angle_xz");
        angle_xz->setGeometry(QRect(220, 380, 111, 21));
        angle_yz = new QListWidget(Tab1);
        angle_yz->setObjectName("angle_yz");
        angle_yz->setGeometry(QRect(220, 410, 111, 21));
        label_2 = new QLabel(Tab1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 380, 121, 21));
        label_3 = new QLabel(Tab1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 410, 121, 21));
        horizontalLayoutWidget = new QWidget(Tab1);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 530, 311, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        TurnOnEngine = new QPushButton(horizontalLayoutWidget);
        TurnOnEngine->setObjectName("TurnOnEngine");

        horizontalLayout->addWidget(TurnOnEngine);

        TurnOffEngine = new QPushButton(horizontalLayoutWidget);
        TurnOffEngine->setObjectName("TurnOffEngine");

        horizontalLayout->addWidget(TurnOffEngine);

        label_4 = new QLabel(Tab1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 510, 61, 21));
        tabWidget->addTab(Tab1, QString());
        Tab2 = new QWidget();
        Tab2->setObjectName("Tab2");
        verticalLayoutWidget = new QWidget(Tab2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 9, 331, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chartView_x = new QChartView(verticalLayoutWidget);
        chartView_x->setObjectName("chartView_x");

        verticalLayout->addWidget(chartView_x);

        chartView_y = new QChartView(verticalLayoutWidget);
        chartView_y->setObjectName("chartView_y");

        verticalLayout->addWidget(chartView_y);

        chartView_z = new QChartView(verticalLayoutWidget);
        chartView_z->setObjectName("chartView_z");

        verticalLayout->addWidget(chartView_z);

        tabWidget->addTab(Tab2, QString());
        german = new QLabel(centralwidget);
        german->setObjectName("german");
        german->setGeometry(QRect(960, 660, 63, 20));
        english = new QLabel(centralwidget);
        english->setObjectName("english");
        english->setGeometry(QRect(930, 660, 63, 20));
        dott = new QLabel(centralwidget);
        dott->setObjectName("dott");
        dott->setGeometry(QRect(0, 650, 63, 20));
        connection = new QLabel(centralwidget);
        connection->setObjectName("connection");
        connection->setGeometry(QRect(50, 650, 63, 20));
        cosmos = new QLabel(centralwidget);
        cosmos->setObjectName("cosmos");
        cosmos->setGeometry(QRect(10, 10, 630, 630));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        x->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        y->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        z->setText(QCoreApplication::translate("MainWindow", "Z:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ctan angle( X, Y )", nullptr));
        openPort->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        closePort->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ctan angle ( X, Z )", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ctan angle ( Y, Z )", nullptr));
        TurnOnEngine->setText(QCoreApplication::translate("MainWindow", "Turn on", nullptr));
        TurnOffEngine->setText(QCoreApplication::translate("MainWindow", "Turn off", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "ENGINES", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab1), QCoreApplication::translate("MainWindow", "Data", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab2), QCoreApplication::translate("MainWindow", "Graphs", nullptr));
        german->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        english->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        dott->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        connection->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        cosmos->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
