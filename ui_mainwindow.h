/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_pic;
    QAction *actionHelp;
    QAction *actionHelp_2;
    QAction *action_data;
    QAction *actionexcel;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_32;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_20;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_stage;
    QComboBox *comboBox_stage;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_current;
    QComboBox *comboBox_current;
    QPushButton *btn_connect;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_d_2;
    QLineEdit *centerx;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_area_2;
    QLineEdit *centery;
    QPushButton *setcenter;
    QPushButton *motorset;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_33;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_29;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_Sphere;
    QWidget *widget_value;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *table_value;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_d;
    QLineEdit *line_d;
    QHBoxLayout *horizontalLayout;
    QLabel *label_area;
    QLineEdit *line_area;
    QHBoxLayout *horizontalLayout_21;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_rows;
    QLineEdit *line_rows;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_cols;
    QLineEdit *line_cols;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_ok;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btn_up;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *btn_left;
    QPushButton *btn_home;
    QPushButton *btn_right;
    QPushButton *btn_down;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_cur_pos;
    QLineEdit *lineEdit_cur_pos;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_real_current;
    QLineEdit *lineEdit_real_current;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_step;
    QLineEdit *line_step;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_28;
    QPushButton *btn_auto;
    QPushButton *btn_stop;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_31;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_interval;
    QLineEdit *line_interval;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_number;
    QLineEdit *line_totalTime;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *btn_start;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_halt;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QCustomPlot *plot;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_min;
    QLineEdit *line_min;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_max;
    QLineEdit *line_max;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_avg;
    QLineEdit *line_avg;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_std;
    QLineEdit *line_std;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_re_std;
    QLineEdit *line_re_std;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_3;
    QMenu *menu;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1465, 904);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        action_pic = new QAction(MainWindow);
        action_pic->setObjectName(QString::fromUtf8("action_pic"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionHelp_2 = new QAction(MainWindow);
        actionHelp_2->setObjectName(QString::fromUtf8("actionHelp_2"));
        actionHelp_2->setIconVisibleInMenu(true);
        action_data = new QAction(MainWindow);
        action_data->setObjectName(QString::fromUtf8("action_data"));
        actionexcel = new QAction(MainWindow);
        actionexcel->setObjectName(QString::fromUtf8("actionexcel"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_12 = new QVBoxLayout(centralwidget);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_stage = new QLabel(groupBox);
        label_stage->setObjectName(QString::fromUtf8("label_stage"));

        horizontalLayout_19->addWidget(label_stage);

        comboBox_stage = new QComboBox(groupBox);
        comboBox_stage->setObjectName(QString::fromUtf8("comboBox_stage"));

        horizontalLayout_19->addWidget(comboBox_stage);


        verticalLayout->addLayout(horizontalLayout_19);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_current = new QLabel(groupBox);
        label_current->setObjectName(QString::fromUtf8("label_current"));

        horizontalLayout_18->addWidget(label_current);

        comboBox_current = new QComboBox(groupBox);
        comboBox_current->setObjectName(QString::fromUtf8("comboBox_current"));

        horizontalLayout_18->addWidget(comboBox_current);


        verticalLayout->addLayout(horizontalLayout_18);


        horizontalLayout_20->addLayout(verticalLayout);

        btn_connect = new QPushButton(groupBox);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));

        horizontalLayout_20->addWidget(btn_connect);


        gridLayout->addLayout(horizontalLayout_20, 0, 0, 1, 1);


        horizontalLayout_32->addWidget(groupBox);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_d_2 = new QLabel(centralwidget);
        label_d_2->setObjectName(QString::fromUtf8("label_d_2"));

        horizontalLayout_15->addWidget(label_d_2);

        centerx = new QLineEdit(centralwidget);
        centerx->setObjectName(QString::fromUtf8("centerx"));
        centerx->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_15->addWidget(centerx);


        verticalLayout_13->addLayout(horizontalLayout_15);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_area_2 = new QLabel(centralwidget);
        label_area_2->setObjectName(QString::fromUtf8("label_area_2"));

        horizontalLayout_17->addWidget(label_area_2);

        centery = new QLineEdit(centralwidget);
        centery->setObjectName(QString::fromUtf8("centery"));
        centery->setEnabled(true);
        centery->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_17->addWidget(centery);


        verticalLayout_13->addLayout(horizontalLayout_17);


        horizontalLayout_32->addLayout(verticalLayout_13);

        setcenter = new QPushButton(centralwidget);
        setcenter->setObjectName(QString::fromUtf8("setcenter"));

        horizontalLayout_32->addWidget(setcenter);

        motorset = new QPushButton(centralwidget);
        motorset->setObjectName(QString::fromUtf8("motorset"));

        horizontalLayout_32->addWidget(motorset);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_6);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/ico/leaf.png")));

        horizontalLayout_32->addWidget(label_2);


        verticalLayout_12->addLayout(horizontalLayout_32);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        verticalLayout_12->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

        verticalLayout_12->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        verticalLayout_12->addLayout(horizontalLayout_8);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShadow(QFrame::Sunken);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_Sphere = new QWidget(page);
        widget_Sphere->setObjectName(QString::fromUtf8("widget_Sphere"));
        widget_Sphere->setMinimumSize(QSize(255, 255));

        verticalLayout_8->addWidget(widget_Sphere);

        widget_value = new QWidget(page);
        widget_value->setObjectName(QString::fromUtf8("widget_value"));
        verticalLayout_7 = new QVBoxLayout(widget_value);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        table_value = new QTableWidget(widget_value);
        table_value->setObjectName(QString::fromUtf8("table_value"));
        table_value->setMaximumSize(QSize(500, 16777215));
        table_value->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        table_value->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        table_value->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        table_value->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        table_value->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        table_value->horizontalHeader()->setCascadingSectionResizes(true);

        verticalLayout_7->addWidget(table_value);


        verticalLayout_8->addWidget(widget_value);


        horizontalLayout_29->addLayout(verticalLayout_8);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_d = new QLabel(widget_2);
        label_d->setObjectName(QString::fromUtf8("label_d"));

        horizontalLayout_2->addWidget(label_d);

        line_d = new QLineEdit(widget_2);
        line_d->setObjectName(QString::fromUtf8("line_d"));
        line_d->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_2->addWidget(line_d);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_area = new QLabel(widget_2);
        label_area->setObjectName(QString::fromUtf8("label_area"));

        horizontalLayout->addWidget(label_area);

        line_area = new QLineEdit(widget_2);
        line_area->setObjectName(QString::fromUtf8("line_area"));
        line_area->setEnabled(false);
        line_area->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout->addWidget(line_area);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_rows = new QLabel(widget_2);
        label_rows->setObjectName(QString::fromUtf8("label_rows"));

        horizontalLayout_4->addWidget(label_rows);

        line_rows = new QLineEdit(widget_2);
        line_rows->setObjectName(QString::fromUtf8("line_rows"));
        line_rows->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_4->addWidget(line_rows);


        horizontalLayout_21->addLayout(horizontalLayout_4);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_cols = new QLabel(widget_2);
        label_cols->setObjectName(QString::fromUtf8("label_cols"));

        horizontalLayout_13->addWidget(label_cols);

        line_cols = new QLineEdit(widget_2);
        line_cols->setObjectName(QString::fromUtf8("line_cols"));
        line_cols->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_13->addWidget(line_cols);


        horizontalLayout_21->addLayout(horizontalLayout_13);


        verticalLayout_3->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer);

        btn_ok = new QPushButton(widget_2);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));

        horizontalLayout_22->addWidget(btn_ok);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_22);


        verticalLayout_9->addWidget(widget_2);

        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(500, 0));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btn_up = new QPushButton(widget);
        btn_up->setObjectName(QString::fromUtf8("btn_up"));
        btn_up->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/arrow_up.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_up->setIcon(icon);
        btn_up->setIconSize(QSize(32, 32));
        btn_up->setFlat(true);

        verticalLayout_4->addWidget(btn_up);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        btn_left = new QPushButton(widget);
        btn_left->setObjectName(QString::fromUtf8("btn_left"));
        btn_left->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/arrow_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_left->setIcon(icon1);
        btn_left->setIconSize(QSize(32, 32));
        btn_left->setFlat(true);

        horizontalLayout_24->addWidget(btn_left);

        btn_home = new QPushButton(widget);
        btn_home->setObjectName(QString::fromUtf8("btn_home"));
        btn_home->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/point_origin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_home->setIcon(icon2);
        btn_home->setIconSize(QSize(32, 32));
        btn_home->setFlat(true);

        horizontalLayout_24->addWidget(btn_home);

        btn_right = new QPushButton(widget);
        btn_right->setObjectName(QString::fromUtf8("btn_right"));
        btn_right->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ico/arrow_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_right->setIcon(icon3);
        btn_right->setIconSize(QSize(32, 32));
        btn_right->setFlat(true);

        horizontalLayout_24->addWidget(btn_right);


        verticalLayout_4->addLayout(horizontalLayout_24);

        btn_down = new QPushButton(widget);
        btn_down->setObjectName(QString::fromUtf8("btn_down"));
        btn_down->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ico/arrow_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_down->setIcon(icon4);
        btn_down->setIconSize(QSize(32, 32));
        btn_down->setFlat(true);

        verticalLayout_4->addWidget(btn_down);


        horizontalLayout_27->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_cur_pos = new QLabel(widget);
        label_cur_pos->setObjectName(QString::fromUtf8("label_cur_pos"));

        horizontalLayout_26->addWidget(label_cur_pos);

        lineEdit_cur_pos = new QLineEdit(widget);
        lineEdit_cur_pos->setObjectName(QString::fromUtf8("lineEdit_cur_pos"));
        lineEdit_cur_pos->setEnabled(false);
        lineEdit_cur_pos->setMaximumSize(QSize(200, 21));
        lineEdit_cur_pos->setReadOnly(true);

        horizontalLayout_26->addWidget(lineEdit_cur_pos);


        verticalLayout_5->addLayout(horizontalLayout_26);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_real_current = new QLabel(widget);
        label_real_current->setObjectName(QString::fromUtf8("label_real_current"));

        horizontalLayout_25->addWidget(label_real_current);

        lineEdit_real_current = new QLineEdit(widget);
        lineEdit_real_current->setObjectName(QString::fromUtf8("lineEdit_real_current"));
        lineEdit_real_current->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_real_current->sizePolicy().hasHeightForWidth());
        lineEdit_real_current->setSizePolicy(sizePolicy);
        lineEdit_real_current->setReadOnly(true);

        horizontalLayout_25->addWidget(lineEdit_real_current);


        verticalLayout_5->addLayout(horizontalLayout_25);


        horizontalLayout_27->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_27);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_step = new QLabel(widget);
        label_step->setObjectName(QString::fromUtf8("label_step"));
        label_step->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_23->addWidget(label_step);

        line_step = new QLineEdit(widget);
        line_step->setObjectName(QString::fromUtf8("line_step"));
        line_step->setMaximumSize(QSize(80, 16777215));
        line_step->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_23->addWidget(line_step);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_23);


        verticalLayout_9->addWidget(widget);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        btn_auto = new QPushButton(page);
        btn_auto->setObjectName(QString::fromUtf8("btn_auto"));
        btn_auto->setEnabled(false);
        btn_auto->setMaximumSize(QSize(150, 28));
        btn_auto->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_28->addWidget(btn_auto);

        btn_stop = new QPushButton(page);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setEnabled(false);
        btn_stop->setMaximumSize(QSize(150, 16777215));
        btn_stop->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_28->addWidget(btn_stop);


        verticalLayout_9->addLayout(horizontalLayout_28);


        horizontalLayout_29->addLayout(verticalLayout_9);


        gridLayout_2->addLayout(horizontalLayout_29, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        tableWidget = new QTableWidget(page_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAutoFillBackground(true);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setLineWidth(1);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setSortingEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);

        horizontalLayout_31->addWidget(tableWidget);

        horizontalSpacer_5 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_interval = new QLabel(page_2);
        label_interval->setObjectName(QString::fromUtf8("label_interval"));

        horizontalLayout_16->addWidget(label_interval);

        line_interval = new QLineEdit(page_2);
        line_interval->setObjectName(QString::fromUtf8("line_interval"));
        line_interval->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_16->addWidget(line_interval);


        verticalLayout_10->addLayout(horizontalLayout_16);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_number = new QLabel(page_2);
        label_number->setObjectName(QString::fromUtf8("label_number"));

        horizontalLayout_14->addWidget(label_number);

        line_totalTime = new QLineEdit(page_2);
        line_totalTime->setObjectName(QString::fromUtf8("line_totalTime"));
        line_totalTime->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_14->addWidget(line_totalTime);


        verticalLayout_10->addLayout(horizontalLayout_14);


        verticalLayout_11->addLayout(verticalLayout_10);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_11->addItem(verticalSpacer);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        btn_start = new QPushButton(page_2);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_30->addWidget(btn_start);

        horizontalSpacer_4 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_4);

        btn_halt = new QPushButton(page_2);
        btn_halt->setObjectName(QString::fromUtf8("btn_halt"));
        btn_halt->setEnabled(true);

        horizontalLayout_30->addWidget(btn_halt);


        verticalLayout_11->addLayout(horizontalLayout_30);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_2);


        horizontalLayout_31->addLayout(verticalLayout_11);


        gridLayout_3->addLayout(horizontalLayout_31, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        horizontalLayout_33->addWidget(stackedWidget);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_7);

        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setMinimumSize(QSize(550, 600));

        horizontalLayout_33->addWidget(plot);


        verticalLayout_12->addLayout(horizontalLayout_33);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_min = new QLabel(widget_3);
        label_min->setObjectName(QString::fromUtf8("label_min"));

        horizontalLayout_9->addWidget(label_min);

        line_min = new QLineEdit(widget_3);
        line_min->setObjectName(QString::fromUtf8("line_min"));
        line_min->setEnabled(false);
        line_min->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_9->addWidget(line_min);


        horizontalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_max = new QLabel(widget_3);
        label_max->setObjectName(QString::fromUtf8("label_max"));

        horizontalLayout_10->addWidget(label_max);

        line_max = new QLineEdit(widget_3);
        line_max->setObjectName(QString::fromUtf8("line_max"));
        line_max->setEnabled(false);
        line_max->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_10->addWidget(line_max);


        horizontalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_avg = new QLabel(widget_3);
        label_avg->setObjectName(QString::fromUtf8("label_avg"));

        horizontalLayout_11->addWidget(label_avg);

        line_avg = new QLineEdit(widget_3);
        line_avg->setObjectName(QString::fromUtf8("line_avg"));
        line_avg->setEnabled(false);
        line_avg->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_11->addWidget(line_avg);


        horizontalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_std = new QLabel(widget_3);
        label_std->setObjectName(QString::fromUtf8("label_std"));

        horizontalLayout_12->addWidget(label_std);

        line_std = new QLineEdit(widget_3);
        line_std->setObjectName(QString::fromUtf8("line_std"));
        line_std->setEnabled(false);
        line_std->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_12->addWidget(line_std);


        horizontalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_re_std = new QLabel(widget_3);
        label_re_std->setObjectName(QString::fromUtf8("label_re_std"));

        horizontalLayout_3->addWidget(label_re_std);

        line_re_std = new QLineEdit(widget_3);
        line_re_std->setObjectName(QString::fromUtf8("line_re_std"));
        line_re_std->setEnabled(false);
        line_re_std->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        horizontalLayout_3->addWidget(line_re_std);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_12->addWidget(widget_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1465, 26));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu->menuAction());
        menu_F->addAction(action_pic);
        menu_F->addAction(action_data);
        menu_3->addAction(actionHelp_2);
        menu->addAction(actionexcel);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_pic->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\350\260\261\345\233\276", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionHelp_2->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        action_data->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        actionexcel->setText(QCoreApplication::translate("MainWindow", "excel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        label_stage->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\247\273\345\217\260", nullptr));
        label_current->setText(QCoreApplication::translate("MainWindow", "6485", nullptr));
        btn_connect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        label_d_2->setText(QCoreApplication::translate("MainWindow", "\344\270\255\345\277\203\345\235\220\346\240\207(x)", nullptr));
        label_area_2->setText(QCoreApplication::translate("MainWindow", "\344\270\255\345\277\203\345\235\220\346\240\207\357\274\210y)", nullptr));
        setcenter->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        motorset->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\345\244\215\344\275\215", nullptr));
        label_2->setText(QString());
        label_d->setText(QCoreApplication::translate("MainWindow", "\347\247\257\345\210\206\347\220\203\347\233\264\345\276\204(mm)", nullptr));
        label_area->setText(QCoreApplication::translate("MainWindow", "\347\237\251\351\230\265\346\234\200\345\244\247\351\235\242\347\247\257(mm^2)", nullptr));
        label_rows->setText(QCoreApplication::translate("MainWindow", "rows", nullptr));
        label_cols->setText(QCoreApplication::translate("MainWindow", "cols", nullptr));
        btn_ok->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        btn_up->setText(QString());
        btn_home->setText(QString());
        btn_right->setText(QString());
        btn_down->setText(QString());
        label_cur_pos->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\344\275\215\347\275\256", nullptr));
        label_real_current->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\347\224\265\346\265\201(uA)", nullptr));
        label_step->setText(QCoreApplication::translate("MainWindow", "\346\255\245\351\225\277(mm)", nullptr));
        line_step->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn_auto->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250", nullptr));
        btn_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        label_interval->setText(QCoreApplication::translate("MainWindow", "\351\207\207\351\233\206\351\227\264\351\232\224(s)", nullptr));
        label_number->setText(QCoreApplication::translate("MainWindow", "\351\207\207\351\233\206\346\227\266\351\227\264(h)", nullptr));
        btn_start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        btn_halt->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        label_min->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\200\274(uA)", nullptr));
        label_max->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\200\274(uA)", nullptr));
        label_avg->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\235\207\345\200\274(uA)", nullptr));
        label_std->setText(QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206\345\267\256[%]", nullptr));
        label_re_std->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\257\271\346\240\207\345\207\206\345\267\256[%]", nullptr));
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
