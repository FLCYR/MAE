#include "movestage.h"

MoveStage::MoveStage()
{

    type=1;//移动类型
    count=0;
}
MoveStage::~MoveStage()
{
}
//初始化串口
bool MoveStage::initPort(QString portName)
{
    //如果串口已经打开
    if(port.isOpen())
    {
       port.clear();
       port.close();
    }
    port.setPortName(portName);
    if(!port.open(QIODevice::ReadWrite))
    {
        qDebug()<<"open move stage com failure";
        return false;
    }
    //设置波特率 数据位 流式控制 校验位 停止位
    port.setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
    port.setDataBits(QSerialPort::Data8);
    port.setParity(QSerialPort::NoParity);
    port.setStopBits(QSerialPort::OneStop);
    //串口接收信息槽函数
    connect(&port,&QSerialPort::readyRead,this,&MoveStage::receiveInfo);
    return true;
}
//发送移动命令,1-x轴，2-y轴，3-z轴
void MoveStage::moveToXY(int distance, int axis,int moveType)
{
    char arr[8];
    arr[0]=0x55;
    arr[1]=0x06;
    arr[2]=axis;
    arr[3]=moveType;
    arr[4]=distance>>8;
    arr[5]=distance&0xff;
    arr[6]=0x07;
    arr[7]=0xAA;
    port.write(arr,8);
}

//type: 4 停止 5 复位 6读x坐标 7 读y坐标
void MoveStage::otherAction(int type)
{

    char arr[5];
    arr[0]=0x55;
    arr[1]=0x06;
    arr[2]=type;
    arr[3]=0x05;
    arr[4]=0xAA;
    port.write(arr);
}
//接收位移台发送过来的信息
void MoveStage::receiveInfo()
{
    QByteArray temp=port.readAll();
    infoArr.append(temp);
    if(infoArr.size()>=8)
    {
        emit completeAct(infoArr);
        infoArr.clear();
    }
}

void MoveStage::reset()
{
    char buf[8]={0x55,0x06,0x03,0x00,0x00,0x00,0x07,0xaa};
    port.write(buf,8);
}

