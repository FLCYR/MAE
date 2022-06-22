#ifndef MOVESTAGE_H
#define MOVESTAGE_H

#include<QSerialPort>
#include<QDebug>
#include<QThread>
#include"ammeter.h"

class MoveStage:public QObject
{
    Q_OBJECT
public:
      int type;
public:
    MoveStage();
    ~MoveStage();
    bool initPort(QString portName);//初始化串口
    void moveToXY(int distance,int axis,int moveType); //移动
    void reset();
    void otherAction(int type);// 其它命令
    void receiveInfo();//接收位移台发送过来的信息
    void portClose()
    {
        if(port.isOpen())
        {
            port.close();
        }

    }
private:
    int count;
    QSerialPort port; //串口对象
    QByteArray infoArr; //接收位移台发送过来的信息
    //bool isReady;//上一次移动是否完成

signals:
    void completeAct(QByteArray dataArr);
};

#endif // MOVESTAGE_H
