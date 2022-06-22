#ifndef SERIALPORT_H
#define SERIALPORT_H

#include<QSerialPort>
#include<QSerialPortInfo>
#include<QDebug>
#include<QObject>
class Ammeter:public QObject
{
    Q_OBJECT
public:

    Ammeter();
    ~Ammeter();

    bool initPort(QString portName);
    void receiveInfo();//读取电流
    void initMeansure(); //电流表测量初始化
    void quickMeansure();//快速测量,将数据存放在电流表缓冲区
    void setRange(int type);
    void portClose()
    {
        if(port.isOpen())
        {
            port.close();
        }
    }
signals:
    void completeRead(double dcCurrent);
public slots:
    void sendOrder(QString order);//发送命令给电流表
private:
    QSerialPort port;
    QByteArray infoArr;
    bool isOk;

};

#endif // SERIALPORT_H
