#include "ammeter.h"
#include <Windows.h>
Ammeter::Ammeter()
{

}

Ammeter::~Ammeter()
{


}

//电流表6485初始化
bool Ammeter::initPort(QString portName)
{
    if(port.isOpen())
    {
        port.clear();
        port.close();
    }
    port.setPortName(portName);
    if(!port.open(QIODevice::ReadWrite))
    {
        qDebug()<<"Open Ammeter port fail";
        return  false;
    }
    port.setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);
    port.setDataBits(QSerialPort::Data8);
    port.setFlowControl(QSerialPort::NoFlowControl);
    port.setParity(QSerialPort::NoParity);
    port.setStopBits(QSerialPort::OneStop);
    connect(&port,&QSerialPort::readyRead,this,&Ammeter::receiveInfo); //接收信息
    initMeansure();//测量初始化
    return true;
}

//接收电流表信息
void Ammeter::receiveInfo()
{
    QByteArray buf=port.readAll();
    infoArr.append(buf);
    if(infoArr.contains('\r')||infoArr.contains('\n'))
    {
        qDebug()<<"Ammeter info: "<<infoArr;
        emit completeRead(infoArr.trimmed().toDouble());
        infoArr.clear();
    }
}


/*
 *
 * *RST ' 将 6485 型 /6487 型返回 GPIB 默认值。
    SYST:ZCH ON ' 激活零点检查。
    RANG 2e-9 ' 选择 2nA 量程。
    INIT ' 触发读数用作零点校正。
    SYST:ZCOR:ACQ ' 将选取的最后一个读数作为零点校正值。
    SYST:ZCOR ON ' 进行零点校正。
    RANG:AUTO ON ' 激活自动量程。
    SYST:ZCH OFF ' 中止调零。
    READ? ' 触发并返回一个读数。
*/

//电流表初始化
void Ammeter::initMeansure()
{
    port.write("*CLS\n");
    port.write("*RST\n");
    port.write("FORM:ELEM READ\n");
    port.write("SYST:ZCH ON\n");
    port.write("RANG 2e-9\n");    //2nA量程有用于零点校准
    port.write("INIT\n");
    //Sleep(300);
    port.write("SYST:ZCOR:ACQ\n");
    port.write("SYST:ZCOR ON\n");
    port.write("RANG:AUTO ON\n");
    port.write("SYST:ZCH OFF\n");
}
/*  *RST ' 使 6485 型 /6487 型返回 RST 默认值。
    TRIG:DEL 0 ' 设置触发延迟时间为 0 秒。
    TRIG:COUN 2000 ' 设置触发次数为 2000。
    NPLC .01 ' 设置积分率为 0.01 PLC。
    RANG .002 ' 使用 2mA 量程。
    SYST:ZCH OFF ' 关闭 Zero Check。
    SYST:AZER:STAT OFF ' 关闭自动清零。
    DISP:ENAB OFF ' 关闭显示器。
    *CLS ' 清除状态寄存器。
    TRAC:POIN 2000 ' 设置缓冲区大小为 2000。
    TRAC:CLE ' 清除缓冲区。
    TRAC:FEED:CONT NEXT ' 设置存储控制从下一个读数开始。
    STAT:MEAS:ENAB 512 ' 激活缓冲区充满测试事件。
    *SRE 1 ' 激活缓冲区完满测试事件的 SRQ。
    *OPC? ' 操作完毕查询。
    ' （同步完成的命令。）
    读回 *opc?的结果
    INIT ' 开始测试并存储读数。
    ' 等待 GPIB SRQ 线为真。
    DISP:ENAB ON ' 将显示器再打开。
    TRAC:DATA? ' 从缓冲区检索数据读回测试结果
 */
void Ammeter::quickMeansure()
{

    port.write("*RST\n");
    port.write("FORM:ELEM READ\n");
    port.write("TRIG:DEL 1\n");
    port.write("TRIG:COUN 10\n"); //触发次数
    port.write("NPLC .01\n");
    port.write("RANG .002\n");
    port.write("SYST:ZCH OFF\n");
    port.write("SYST:AZER:STAT:OFF\n");
    port.write("*CLS\n");
    port.write("TRAC:POIN 10\n");//缓冲区大小
    port.write("TRAC:CLE\n");
    port.write("TRAC:FEED:CONT NEXT\n");

    port.write("SYST:MEAS:ENAB 512\n");
    port.write("*SRE 1\n");
    port.write("*OPC?\n");
    port.write("INIT\n");
    port.write("TRAC:DATA?\n");
}
//向电流表发送信息
void Ammeter::sendOrder(QString order)
{
   port.write(order.toUtf8());
}
void Ammeter::setRange(int type)
{
    switch (type)
    {
    case 0:
        port.write("RANG 2e-3\n");
        break;
    case 1:
         port.write("RANG 2e-2\n");
        break;
    case 2:
         port.write("RANG 2e-6\n");
        break;
    case 3:
         port.write("RANG 2e-5\n");
        break;
    case 4:
         port.write("RANG 2e-4\n");
        break;
    case 5:
         port.write("RANG 2e-9\n");
        break;
    case 6:
         port.write("RANG 2e-8\n");
        break;
    case 7:
         port.write("RANG 2e-7\n");
        break;
    default:
        break;
    }


}

