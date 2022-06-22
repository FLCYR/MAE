#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setDirBtnEnabled(false);
    this->setWindowTitle("XYC");//标题
    this->setMouseTracking(true);//设置鼠标追踪
    currentTimer=new QTimer(this);//电流表定时读取数据
    autoTimer=new QTimer(this); //自动遍历中心定时器



    connect(autoTimer,&QTimer::timeout,this,&MainWindow::autoCheck); //自动遍历中心
    connect(currentTimer,&QTimer::timeout,this,&MainWindow::currentTimeOutFun); //定时读取电流
    connect(&ammeter,&Ammeter::completeRead,this,&MainWindow::readCurrent); //电流表
    connect(&stage,&MoveStage::completeAct,this,&MainWindow::readPosition);  //位移台
    connect(&portCheckTimer,&QTimer::timeout,this,&MainWindow::portCheck); //定时检测串口

    ui->widget_Sphere->installEventFilter(this);//子控件事件过滤器 在子控件绘图

    initParameters(); //初始化参数
    initTableWidget(); //初始化表格
    initToolBar(); //工具栏
    setAmmeterTable(); //电流表表格
    setPlotInfo(); //图表

    setLineEditInfo();//设置输入框属性
    setLineEditStyle(); //设置输入框样式
    setBtnStyle(); //设置按钮样式

    portCheckTimer.start(2000);
    getAllPortInfo();//获取串口信息
    //loadStyleQss(); //加载qss样式

}



MainWindow::~MainWindow()
{
    ammeter.portClose();
    stage.portClose();
    delete ui;
}

//获取所有串口信息
void MainWindow::getAllPortInfo()
{
    //获取所有可用的串口

    QList<QSerialPortInfo> allPortsInfo=QSerialPortInfo::availablePorts();
    QStringList serialPortNameList;
    if(ui->comboBox_stage->count()>=allPortsInfo.size())
        return;
    ui->comboBox_stage->clear();
    ui->comboBox_current->clear();
    for(auto item:allPortsInfo)
    {
        ui->comboBox_current->addItem(item.portName());
        ui->comboBox_stage->addItem(item.portName());
    }
}

void MainWindow::portCheck()
{
    if(isConnectOk)
    {
        portCheckTimer.stop();
        return;
    }

    getAllPortInfo();
}

//初始化参数
void MainWindow::initParameters()
{

    originFlag=true;
    centerFlag=true;
    center.rx()=67;
    center.ry()=30;
    unit="uA";
    isStop=true;
    range=1e6;
    isConnectOk=false; //设备连接成功标志
    isReadyMove=true;
    length=125.0;   //像素圆半径
    curStagePosX=0; //位移台初始位置
    curStagePosY=0;
    moveType=0;


    matixWidth=qSqrt(2)*length;//矩阵长度 √2r;

    cols=3;
    rows=3;
    cellH=matixWidth/rows;
    cellW=matixWidth/cols;

    step=5; //初始步长
    moveStep=0;
    pointNum=0;
    totalTime=0;
    count=0;
    iWidth=0;
    pointPos.rx()=length;
    pointPos.ry()=length;
}

//定时读取电流
void MainWindow::currentTimeOutFun()
{

    if(centerFlag)
    {
        totalTime-=(interval*1000);
        if(totalTime<=0)
            currentTimer->stop();
        ammeter.sendOrder("READ?\n");
    }

}

//稳定性 电流数据图表
void MainWindow::currentStableDataSet()
{
   int total=ui->tableWidget->rowCount();
   ui->tableWidget->insertRow(total);
   ui->tableWidget->setItem(count,0,new QTableWidgetItem(QString("%1").arg(count+1)));
   ui->tableWidget->setItem(count,1,new QTableWidgetItem(QString("%1").arg(interval*(count+1))));
   ui->tableWidget->setItem(count,2,new QTableWidgetItem(QString("%1").arg(dcCurrent)));

   plotVectorX.append((count+1)*interval);
   plotVectorY.append(dcCurrent);
   double maxValue=*std::max_element(plotVectorY.begin(),plotVectorY.end());
   double minValue=*std::min_element(plotVectorY.begin(),plotVectorY.end());
   ui->plot->yAxis->setRange(minValue,maxValue);
   ui->plot->graph(0)->setData(plotVectorX,plotVectorY);
   ui->plot->replot();
   calcuateValue();
   count++;
}


//计算各种数值
void MainWindow::calcuateValue()
{

    QVector<double>temp;
    if(ui->stackedWidget->currentIndex()==0)
    {
        temp=plotY;
    }
    else
    {
       temp=plotVectorY;
    }

    double sum=std::accumulate(temp.begin(),temp.end(),0.0);//总和
    double mean=sum/temp.size();//均值
    double maxValue=*std::max_element(temp.begin(),temp.end());//最大值
    double minValue=*std::min_element(temp.begin(),temp.end());//最小值
    double accum=0.0;
    std::for_each(temp.begin(),temp.end(),[&](const double d)
    {
        accum+=(d-mean)*(d-mean);
    });

    double stdev=sqrt(accum/(temp.size()-1));//标准差
    double reStdev=stdev/mean;//相对标准差

    ui->line_std->setText(QString::number(stdev,'f',6));
    ui->line_re_std->setText(QString::number(reStdev,'f',6));
    ui->line_avg->setText(QString::number(mean,'f',6));
    ui->line_max->setText(QString::number(maxValue,'f',6));
    ui->line_min->setText(QString::number(minValue,'f',6));


    /*
    ui->line_re_std->setText(QString("%1").arg(reStdev*100));
    ui->line_std->setText(QString("%1").arg(stdev*100));
    ui->line_min->setText(QString("%1").arg(minValue));
    ui->line_max->setText(QString("%1").arg(maxValue));
    ui->line_avg->setText(QString("%1").arg(mean));
    */
}

//加载qss样式文件
void MainWindow::loadStyleQss()
{
    QFile file(":/css/style.qss");
    //QFile file(":/../../Qt开发资料/QSS-master/QSS-master/MacOS.qss");
    file.open(QIODevice::ReadOnly);
    QTextStream text(&file);
    QString styleSheet=text.readAll();
    this->setStyleSheet(styleSheet);
    file.close();
}

//stackWidget 页面切换
void MainWindow::switchPageOne()
{
    currentTimer->stop();
    clearCalcValue();
    ui->stackedWidget->setCurrentIndex(0);
    ui->plot->xAxis->setLabel("点数");
    ui->plot->xAxis->setRange(1,100);
    ui->plot->yAxis->setRange(0.01,1);
    ui->plot->replot();
}
//stackWidget 页面切换
void MainWindow::switchPageTwo()
{

    clearCalcValue();
    ui->btn_stop->setEnabled(false);
    ui->stackedWidget->setCurrentIndex(1);
    ui->plot->xAxis->setLabel("时间(ms)");
    ui->plot->replot();
}

//设置表格属性
void MainWindow::initTableWidget()
{

    QStringList headers;
    ui->tableWidget->setColumnCount(3);//设置列数
    headers<<"序号"<<"时间"<<"数据";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑表格
    //ui->tableWidget->horizontalHeader()->setHidden(true);//隐藏表头
    ui->tableWidget->verticalHeader()->setHidden(true);//隐藏表头
    ui->tableWidget->resizeRowsToContents();//内容自适应
    ui->tableWidget->resizeColumnsToContents();

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    // 选中行颜色
    //ui->tableWidget->setStyleSheet("selection-background-color: red");
    // 行背景色
    //ui->tableWidget->setStyleSheet("QTableWidget{background-color:#F0F0F0}");

    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:#f0f0f0;}");
    ui->tableWidget->setStyleSheet("background-color:#F0F0F0;");
    //tableProcess();

}

//显示电流值的表格
void MainWindow::setAmmeterTable()
{

    ui->table_value->setColumnCount(2);
    QStringList headerLabel;
    headerLabel<<"位置"<<"数据";
    ui->table_value->setHorizontalHeaderLabels(headerLabel);
    ui->table_value->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑

    //ui->table_value->horizontalHeader()->setHidden(true);
    ui->table_value->verticalHeader()->setHidden(true);


    //ui->table_value->horizontalHeader()->setStretchLastSection(true);
    /*设置表格是否充满，即行末不留空*/
    ui->table_value->horizontalHeader()->setStretchLastSection(true);

    //ui->table_value->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->table_value->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_value->resizeRowsToContents();//内容自适应
    ui->table_value->resizeColumnsToContents();
    ui->table_value->setStyleSheet("background-color:#f0f0f0");
    ui->table_value->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:#f0f0f0;}");
}

//工具栏设置
void MainWindow::initToolBar()
{
    //新增QAction

    QString itemName="均匀性";
    QAction*itemUnform=new QAction("均匀性",this);
    QAction*itemStable=new QAction(tr("稳定性"),this);
    connect(itemUnform,&QAction::triggered,this,&MainWindow::switchPageOne);
    connect(itemStable,&QAction::triggered,this,&MainWindow::switchPageTwo);
    //给QAction加icon图标
    itemUnform->setIcon(QIcon(":/ico/table.ico"));
    itemStable->setIcon(QIcon(":/ico/wave.ico"));
    //把QAction和工具栏关联
    ui->toolBar->addAction(itemUnform);
    ui->toolBar->addAction(itemStable);
}


//事件过滤  在子控件上绘图
bool MainWindow::eventFilter(QObject*obj,QEvent*event)
{
    if(obj==ui->widget_Sphere&&event->type()==QEvent::Paint)
    {
        drawSphere();
        return true;
    }
    //控件是否在鼠标下
//    else if(obj==ui->plot&&event->type()==QEvent::MouseButtonPress)
//    {

//        if(ui->plot->underMouse())
//        {

//        }
//    }
    return QMainWindow::eventFilter(obj,event);
}
//画圆和内接矩形
void MainWindow::drawSphere()
{

    QPainter p(ui->widget_Sphere);
    p.setPen(Qt::black);
    p.drawEllipse(0,0,length*2,length*2);
    double x=length-(qSqrt(2)/2.0*length);
    qreal w=matixWidth;
    QPen pen(QBrush(QColor(0,0,255)),3);
    p.setPen(pen);
    //画测试点
    p.drawPoint(pointPos.x(),pointPos.y());
    p.setPen(Qt::black);
    double xSpace=(matixWidth)/rows;
    double ySpace=(matixWidth)/cols;


    for(int i=0;i<=rows;i++)
    {
        //(x,x)
        qreal pointX=xSpace*i;
        p.drawLine(QLineF(x,x+pointX,x+w,x+pointX));
    }
    for(int i=0;i<=cols;i++)
    {
        qreal pointY=ySpace*i;
        p.drawLine(QLineF(x+pointY,x,x+pointY,x+w));
    }
}

void MainWindow::setUniformTableData()
{
    ui->plot->graph(0)->setData(plotX,plotY);
}
//坐标轴信息
void MainWindow::setPlotInfo()
{


    ui->plot->setInteractions(QCP::iRangeDrag |
                              QCP::iSelectLegend | QCP::iSelectPlottables);


    //坐标轴名字
    ui->plot->xAxis->setLabel("点数");
    ui->plot->yAxis->setLabel("电流(mA)");

    //坐标轴名称颜色和字体大小
    ui->plot->xAxis->setLabelColor(QColor(0,0,255));
    ui->plot->xAxis->setLabelFont(QFont("宋体",13));
    ui->plot->yAxis->setLabelColor(QColor(0,0,255));
    ui->plot->yAxis->setLabelFont(QFont("宋体",13));

    //ui->plot->legend->setVisible(true); //图列
   // ui->plot->xAxis->setVisible(true);
    //设置范围
    ui->plot->xAxis->setRange(1,30);
    ui->plot->yAxis->setRange(0.0001,0.01);



    //设置坐标背景颜色
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(240, 240, 240));//渐变
    plotGradient.setColorAt(1, QColor(210, 210, 210));
    ui->plot->setBackground(plotGradient);

    ui->plot->addGraph();//添加一条曲线

}

//设置输入框限制
void MainWindow::setLineEditInfo()
{

    QRegExp rx("[0-9]*");//正则表达式 只能输入整数
    QRegExpValidator*reg=new QRegExpValidator(rx,this);

    ui->line_d->setValidator(reg);
    ui->line_step->setValidator(reg);

    ui->line_cols->setValidator(reg);
    ui->line_rows->setValidator(reg);
}

//回到中心点
void MainWindow::on_btn_home_clicked()
{

    setDirBtnEnabled(false);
    moveType=0;
    pointPos.rx()=length;
    pointPos.ry()=length;
    centerFlag=false;
    stage.moveToXY(center.x()*10,XAXIS,ABSMOVE);

}


void MainWindow::setDirBtnEnabled(bool flag)
{
    ui->btn_up->setEnabled(flag);
    ui->btn_down->setEnabled(flag);
    ui->btn_left->setEnabled(flag);
    ui->btn_right->setEnabled(flag);
    ui->btn_home->setEnabled(flag);
}
//前进
void MainWindow::on_btn_down_clicked()
{

    setDirBtnEnabled(false);
    moveType=0;
    step=ui->line_step->text().toInt();
    pointPos.ry()+=(step*radtio);
    stage.moveToXY(step*10,YAXIS,FORWARD);
}

//x 后退
void MainWindow::on_btn_left_clicked()
{
    setDirBtnEnabled(false);
    moveType=0;
    step=ui->line_step->text().toInt();
    pointPos.rx()-=(step*radtio);
    stage.moveToXY(step*10,XAXIS,BACK);

}
//y 后退
void MainWindow::on_btn_up_clicked()
{

    setDirBtnEnabled(false);
    moveType=0;
    step=ui->line_step->text().toInt();
    pointPos.ry()-=(step*radtio);
    stage.moveToXY(step*10,YAXIS,BACK);
}

//x 前进
void MainWindow::on_btn_right_clicked()
{
    setDirBtnEnabled(false);
    moveType=0;
    step=ui->line_step->text().toInt();
    pointPos.rx()+=(step*radtio);
    stage.moveToXY(step*10,XAXIS,FORWARD);
}
//处理发送过来电流
void MainWindow::readCurrent(double current)
{

      qDebug()<<"current: "<<current;
      dcCurrent=1e6*current;    //A to uA


    if(ui->stackedWidget->currentIndex()==0)
    {
        if(moveType==1)
        {
            pointNum++;
            plotX.append(pointNum);
            plotY.append(dcCurrent);
            double maxValue=*std::max_element(plotY.begin(),plotY.end());
            double minValue=*std::min_element(plotY.begin(),plotY.end());
            ui->plot->yAxis->setRange(minValue,2*maxValue);
            ui->plot->xAxis->setRange(0,pointNum+10);
            ui->plot->graph(0)->setData(plotX,plotY);
            ui->plot->replot();
            int totalRow=ui->table_value->rowCount();
            ui->table_value->insertRow(totalRow);
            ui->table_value->setItem(totalRow,0,new QTableWidgetItem(QString("%1").arg(totalRow+1)));
            ui->table_value->setItem(totalRow,1,new QTableWidgetItem(QString("%1").arg(dcCurrent)));
            calcuateValue();
            autoCheck();
        }
        else
        {
            setDirBtnEnabled(true);
        }
         ui->lineEdit_real_current->setText(QString("%1").arg(dcCurrent));
         ui->lineEdit_cur_pos->setText(QString("%1,%2").arg( curStagePosX).arg( curStagePosY));

    }
    else
    {
       currentStableDataSet();
    }

}

//处理位移台信息
void MainWindow::readPosition(QByteArray position)
{
    qDebug()<<"hex: "<<position.toHex(' ');
    unsigned char * res=(unsigned char*)position.data();
    if(res[2]==0x01)
    {
        curStagePosX=((res[4]<<8)|res[5])/10.0;
        qDebug()<<"x-curPos: "<< curStagePosX;
    }
    else if(res[2]==0x02)
    {
        curStagePosY=((res[4]<<8)|res[5])/10.0;
        qDebug()<<"y-curPos: "<< curStagePosY;
    }

    if(!centerFlag)
    {
        stage.moveToXY(center.y()*10,YAXIS,ABSMOVE);
        centerFlag=true;
        return;
    }
    if(!originFlag)   //移动到开始位置
    {
        stage.moveToXY(curStagePosY*10,YAXIS,ABSMOVE);
        originFlag=true;
    }
    else
    {
        update();
        ammeter.sendOrder("READ?\n");
    }

}
//矩阵移动
void MainWindow::autoCheck()
{
    if(isStop)
    {
        return;
    }

    currentCol++;
    if(currentCol>cols)
    {
        currentRow++;
        if(currentRow>rows)
        {
            ui->btn_auto->setEnabled(true);
            ui->btn_stop->setEnabled(false);
            setDirBtnEnabled(true);
            isStop=true;
            return;
        }
        pointPos.ry()+=cellH;
        mask=-mask;
        currentCol=1;
        stage.moveToXY(_cellH*10,YAXIS,FORWARD);
    }
    else
    {
         pointPos.rx()+=(cellW*mask);
         stage.moveToXY(_cellW*10,XAXIS,mask<0?BACK:FORWARD);
    }
}

//自动遍历每一个单元格的中心
void MainWindow::on_btn_auto_clicked()
{
    if(!isConnectOk)
    {
        QMessageBox::warning(this,"ERROR","请连接设备");
        return;
    }

    mask=1;
    moveType=1;
    pointNum=0;
    currentCol=1;
    currentRow=1;
    pointPos.rx()=length-cellW*qFloor(cols/2);
    pointPos.ry()=length-cellH*qFloor(rows/2);
    curStagePosX=center.x()-_cellW*qFloor(cols/2);
    curStagePosY=center.y()-_cellH*qFloor(rows/2);
    setDirBtnEnabled(false);
    originFlag=false;
    isStop=false;
    plotX.clear();
    plotY.clear();
    ui->table_value->clearContents(); //清除数据
    ui->table_value->setRowCount(0);
    ui->table_value->clearFocus();
    stage.moveToXY(curStagePosX*10,XAXIS,ABSMOVE); //移动左上角

}


//稳定性采集 开始按钮
void MainWindow::on_btn_start_clicked()
{
    //TODO:需要修改，可能均匀性尚未结束
    if(!isConnectOk)
    {
        QMessageBox::warning(this,"ERROR","请连接设备");
        return;
    }
    if(!isStop)
    {
        QMessageBox::warning(this,"ERROR","设备运行中");
        return;
    }
    interval=ui->line_interval->text().toDouble();
    totalTime=ui->line_totalTime->text().toDouble()*3600*1000;

    if(totalTime==0||interval==0)
    {
        QMessageBox::warning(this,"ERROR","请输入正确数值");
        return;
    }


    if(interval*1000<500)
    {
        QMessageBox::warning(this,"ERROR","间隔时间太短,请重新设置");
        return;
    }
    count=0;
    ui->tableWidget->clearContents(); //清除数据
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearFocus();
    plotVectorX.clear();
    plotVectorY.clear();
    ui->plot->graph(0)->setData(plotVectorX,plotVectorY);//重绘
    ui->plot->xAxis->setRange(0,totalTime);
    ui->plot->replot();
    on_btn_home_clicked();  //移动到中心位置
    moveType=1;
    currentTimer->start(qFloor(interval*1000));
    ui->btn_start->setEnabled(false);
    ui->btn_halt->setEnabled(true);
    isStop=false;
}

//稳定性采集 暂停
void MainWindow::on_btn_halt_clicked()
{

    currentTimer->stop();
    ui->btn_start->setEnabled(true);
    ui->btn_halt->setEnabled(false);
    isStop=true;
}
//设置按钮样式
void MainWindow::setBtnStyle()
{

    ui->btn_home->setObjectName("Dir-Btn");
    ui->btn_left->setObjectName("Dir-Btn");
    ui->btn_right->setObjectName("Dir-Btn");
    ui->btn_down->setObjectName("Dir-Btn");
    ui->btn_up->setObjectName("Dir-Btn");
}
//输入框样式
void MainWindow::setLineEditStyle()
{
    ui->line_rows->setProperty("class","input");
    ui->line_cols->setProperty("class","input");
    ui->line_d->setProperty("class","input");
}
//均匀性 暂停按钮
void MainWindow::on_btn_stop_clicked()
{
    ui->btn_stop->setEnabled(false);
    ui->btn_auto->setEnabled(true);
    isStop=true;
}

//设置矩阵行列和直径
void MainWindow::on_btn_ok_clicked()
{

    rows=ui->line_rows->text().toInt();
    cols=ui->line_cols->text().toInt();
    double diameter=ui->line_d->text().toDouble();

    if(diameter==0||rows==0||cols==0)
    {
        rows=3;
        cols=3;
        QMessageBox::warning(this,"ERROR","请输入信息");
        return;
    }
    double area=diameter*diameter;
    radius=diameter/2;
    iWidth=sqrt(2)*radius;
    curStagePosX=0;
    curStagePosY=0;

    ui->line_area->setText(QString("%1").arg(area));
    cellW=matixWidth/cols;
    cellH=matixWidth/rows;
    _cellW=iWidth/cols;
    _cellH=iWidth/rows;
    pointPos.rx()=length-cellW*qFloor(cols/2);
    pointPos.ry()=length-cellH*qFloor(rows/2);
    qDebug()<<"r: "<<radius<<" _cellW: "<<_cellW<<" _cellH"<<_cellH;
    radtio=matixWidth/iWidth;
    ui->btn_auto->setEnabled(true);
    update();
}


//清除计算的lineEdit值
void MainWindow::clearCalcValue()
{

    ui->line_std->clear();
    ui->line_avg->clear();
    ui->line_max->clear();
    ui->line_min->clear();
    ui->line_re_std->clear();
}
//保存谱图
void MainWindow::on_action_pic_triggered()
{
    QString fileName=QFileDialog::getSaveFileName(this,"保存截图","./","pic(*.png)");
    if(fileName.isEmpty())
        return;
    QScreen*screen=QGuiApplication::primaryScreen();
    QPixmap pix=screen->grabWindow(ui->plot->winId());//控件id
    bool flag=pix.save(fileName);
    if(flag)
    {
        QMessageBox::information(this,"保存图片","保存成功");
    }
}

//判断设备是否连接成功
void MainWindow::on_btn_connect_clicked()
{

//    if(!stageOk)
//    {
//        if(!stage.initPort(ui->comboBox_stage->currentText()))
//        {
//            QMessageBox::warning(this,"ERROR","位移台设备连接失败,请重新选择连接");
//            stageOk=false;
//            return;
//        }
//        stageOk=true;
//    }

    if(!ammeterOk)
    {
        if(!ammeter.initPort(ui->comboBox_current->currentText()))
        {
            QMessageBox::warning(this,"ERROR","6485连接失败,请重新选择连接");
            ammeterOk=false;
            return;
        }
        ammeterOk=true;
    }
    QMessageBox::warning(this,"SUCCESS","设备连接成功");
    setDirBtnEnabled(true);
    isConnectOk=true;
}


void MainWindow::stageMove(int distance, int type)
{
}
void MainWindow::setUnit()
{

    ui->label_avg->setText("平均值("+unit+")");
    ui->label_min->setText("最小值("+unit+")");
    ui->label_max->setText("最大值("+unit+")");
    ui->plot->yAxis->setLabel("电流("+unit+")");
    ui->plot->replot();
}
//设置量程

//保存excel表格
void MainWindow::on_actionexcel_triggered()
{

    QString fileName=QFileDialog::getSaveFileName(this,"保存数据","./","excel(*.xlsx)");
    if(fileName.isEmpty())
        return;
    QVector<QString>val;
    val.append(ui->line_std->text());
    val.append(ui->line_re_std->text());
    val.append(ui->line_avg->text());
    val.append(ui->line_max->text());
    val.append(ui->line_min->text());

    if(ui->stackedWidget->currentIndex()==0)
    {

        Excel excel;
        excel.saveData(fileName,plotX,plotY,val,unit,rows);
    }
    else
    {
        Excel excel;
        excel.saveDataU(fileName,plotVectorX,plotVectorY,val,unit);
    }
}

void MainWindow::on_action_data_triggered()
{

}

//复位
void MainWindow::on_motorset_clicked()
{
    stage.reset();
}
//设置中心位置
void MainWindow::on_setcenter_clicked()
{
    center.rx()=ui->centerx->text().toInt();
    center.ry()=ui->centery->text().toInt();
}

