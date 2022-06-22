#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QPainter>
#include<QPaintEvent>
#include<QtMath>
#include<QMap>
#include<QFileDialog>
#include<QMessageBox>
#include<QAction>
#include<QThread>
#include "qcustomplot.h"
#include"ammeter.h"
#include"movestage.h"
#include"excel.h"


enum MOVETYPE{FORWARD=1,BACK=2,ABSMOVE=3};
enum AXIS{XAXIS=1,YAXIS=2};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    void setUnit();
    void drawSphere();
    void setPlotInfo(); //设置坐标轴的一些属性

    void initToolBar();//初始化工具栏
    void drawTableValue();//画表格
    void initTableWidget();
    void setAmmeterTable();
    void switchPageOne();
    void switchPageTwo();


    void setUniformTableData(); //设置坐标数据
    void setLineEditInfo();//设置输入框属性

    void loadStyleQss();//加载qss文件
    void initParameters();
    void calcuateValue();//计算各种数值
    void clearCalcValue();//清除计算数值
    void autoCheck();  //自动遍历
    void setDirBtnEnabled(bool flag);
    void getAllPortInfo();
    void stageMove(int distance,int type);
public slots:
    //读取SerialPort类发送过来的电流
    void readCurrent(double current);
    void readPosition(QByteArray position);

    void portCheck();//串口检测
protected:
    //void paintEvent(QPaintEvent*event);
    bool eventFilter(QObject*obj,QEvent*event);

private slots:
    void on_btn_down_clicked();

    void on_btn_left_clicked();

    void on_btn_home_clicked();


    void on_btn_ok_clicked();


    void on_btn_up_clicked();

    void on_btn_right_clicked();

    void on_btn_auto_clicked();

    void on_btn_start_clicked();

    void on_btn_stop_clicked();

    void on_btn_halt_clicked();

    //void on_btn_d_set_clicked();

    void on_action_pic_triggered();

    //void on_comboBox_current_highlighted(int index);

    void on_btn_connect_clicked();



    void on_actionexcel_triggered();

    void on_action_data_triggered();

    void on_motorset_clicked();

    void on_setcenter_clicked();

protected:

    void currentTimeOutFun();//测试稳定性 定时器
    void currentStableDataSet();//设置电流表格的数据
    void setBtnStyle();//设置按钮样式
    void setLineEditStyle();//设置输入框的样式
protected:
    QVector<double> plotVectorX; //x,y轴坐标数据
    QVector<double> plotVectorY; //稳定性图表

    QVector<double> plotX;
    QVector<double> plotY;//均匀性 图表数据
private:
    Ui::MainWindow *ui;

    MoveStage stage; //位移台
    Ammeter ammeter; //电流表
    QThread thread;//线程对象
    QPointF pointPos;
    QPointF center; //中心位置
    double radius;//积分球半径
    double iWidth;//积分球矩阵宽度
    int pointNum;  //采集的点数
    bool originFlag;
    bool centerFlag;
    int rows;
    int cols; //矩阵行列


    int moveType;//移动类型
    int step; //步长
    double moveStep; //每一步的像素
    double matixWidth;// 矩阵的宽度
    double radtio;// 像素系数
    double length;// 圆的半径
    double cellW; //单元格宽
    double cellH; //单元格高
    double _cellW;  //
    double _cellH;
    int currentRow;
    int currentCol;
    int mask;
        //当前
    int totalNum;//采集点数
    double totalTime;//采集时间
    double interval; //采集间隔
    int count; //当前采集点数


    double curStagePosX;//当前位移台位置
    double curStagePosY;

    bool isConnectOk;//串口连接是否成
    bool stageOk{false};
    bool ammeterOk{false};
protected:
    double dcCurrent;
    double range;
    QString unit; //单位
    QTimer*currentTimer;
    QTimer*autoTimer; //自动遍历定时器
    QTimer portCheckTimer;//串口检测
    bool isReadyMove;//是否可以进行下一次移动
    bool isReadyRead;//是否可以进行下一次读取
    bool isStop;
};
#endif // MAINWINDOW_H
