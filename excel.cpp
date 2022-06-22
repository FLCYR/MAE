#include "excel.h"
#include<QSize>
Excel::Excel()
{
}
bool Excel::saveData(QString filePath,const QVector<double>&x,const QVector<double>&y,QVector<QString>&val,QString unit,int rows)
{

     format.setFontSize(13);/*设置字体大小*/
     //format.setFontColor(QColor(Qt::red));/*文字为红色*/
     //format.setPatternBackgroundColor(QColor(152,251,152));/*北京颜色*/
     QXlsx::Format format1;
     QXlsx::Format format2;
     format1.setPatternBackgroundColor(QColor(200,0,0));
     format2.setPatternBackgroundColor(QColor(0,0,200));
//    format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);/*横向居中*/
//    format.setBorderStyle(QXlsx::Format::BorderDashDotDot);/*边框样式*/

    xlsx.write(1,1,"电流单位: "+unit);
    int maxIndex=std::distance(y.begin(),std::max_element(y.begin(),y.end()));
    int minIndex=std::distance(y.begin(),std::min_element(y.begin(),y.end()));

    int cols=y.size()/rows;
   // qDebug()<<"rows: "<<rows<<" cols: "<<cols;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
             if(maxIndex==rows*i+j)
             {
                 xlsx.write(i+5,j+1,QString::number(y[rows*i+j],'f',6),format1);
             }
             else if(minIndex==rows*i+j)
             {
                 xlsx.write(i+5,j+1,QString::number(y[rows*i+j],'f',6),format2);
             }
             else
                xlsx.write(i+5,j+1,QString::number(y[rows*i+j],'f',6));
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
             if(maxIndex==rows*i+j)
             {
                 xlsx.write(i+5,j+cols+2,QString::number(100*(y[rows*i+j]/y[maxIndex]),'f',3)+"%",format1);
             }
             else if(minIndex==rows*i+j)
             {
                 xlsx.write(i+5,j+cols+2,QString::number(100*(y[rows*i+j]/y[maxIndex]),'f',3)+"%",format2);
             }
             else
                xlsx.write(i+5,j+cols+2,QString::number(100*(y[rows*i+j]/y[maxIndex]),'f',3)+"%");
        }
    }

    xlsx.write(2,1,"标准差");
    xlsx.write(2,2,"相对标准差");
    xlsx.write(2,3,"平均值");
    xlsx.write(2,4,"最大值");
    xlsx.write(2,5,"最小值");

    for(int i=0;i<val.size();i++)
    {
        xlsx.write(3,i+1,val[i]);
    }

    return xlsx.saveAs(filePath);
}

bool Excel::saveDataU(QString filePath,const QVector<double> &x, const QVector<double> &y,QVector<QString>&val,QString unit)
{
    QXlsx::Format format1;
    QXlsx::Format format2;
    format1.setPatternBackgroundColor(Qt::red);
    format2.setPatternBackgroundColor(Qt::blue);
    int maxIndex=std::distance(y.begin(),std::max_element(y.begin(),y.end()));
    int minIndex=std::distance(y.begin(),std::min_element(y.begin(),y.end()));

    xlsx.write(1,1,"电流单位: "+unit);
    for(int i=0;i<x.size();i++)
    {
        if(maxIndex==i)
        {
            xlsx.write(i+4,1,x[i],format1);
            xlsx.write(i+4,2,QString::number(y[i],'f',6),format1);
        }
        else if(minIndex==i)
        {
            xlsx.write(i+4,1,x[i],format2);
            xlsx.write(i+4,2,QString::number(y[i],'f',6),format2);
        }
        else
        {
            xlsx.write(i+4,1,x[i]);
            xlsx.write(i+4,2,QString::number(y[i],'f',6));
        }
    }

    xlsx.write(2,1,"标准差");
    xlsx.write(2,2,"相对标准差");
    xlsx.write(2,3,"平均值");
    xlsx.write(2,4,"最大值");
    xlsx.write(2,5,"最小值");
    for(int i=0;i<val.size();i++)
    {
        xlsx.write(3,i+1,val[i]);
    }

    return xlsx.saveAs(filePath);

}
void Excel::example()
{

    //    QXlsx::Document xlsx;
    //    QXlsx::Format format1;/*设置该单元的样式*/
    //    format1.setFontColor(QColor(Qt::red));/*文字为红色*/
    //    format1.setPatternBackgroundColor(QColor(152,251,152));/*北京颜色*/
    //    format1.setFontSize(15);/*设置字体大小*/
    //    format1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);/*横向居中*/
    //    format1.setBorderStyle(QXlsx::Format::BorderDashDotDot);/*边框样式*/
    //    xlsx.write("A1", "Hello Qt!", format1);/*写入文字，应该刚才设置的样式*/
    //    xlsx.write(2, 1, 12345, format1);/*写入文字，应该刚才设置的样式*/
    //    QXlsx::Format format2;/*重新设置另一个单元的样式*/
    //    format2.setFontBold(true);/*设置加粗*/
    //    format2.setFontUnderline(QXlsx::Format::FontUnderlineDouble);/*下双划线*/
    //    format2.setFillPattern(QXlsx::Format::PatternLightUp);/*填充方式*/
    //    xlsx.write("A4", "=44+33", format2);/*写入文字，应该刚才设置的样式*/
    //    xlsx.write("C4", true, format2);
    //    if(!xlsx.selectSheet("ziv")){/*在当前打开的xlsx文件中，找一个名字为ziv的sheet*/
    //        xlsx.addSheet("ziv");//找不到的话就添加一个名为ziv的sheet
    //    }
    //    for (int i=10; i<20; ++i) {/*写入一串数字*/
    //        xlsx.write(i, 1, i*i*i);   //A10:A19
    //        xlsx.write(i, 2, i*i); //B10:B19
    //        xlsx.write(i, 3, i*i-1); //C10:C19
    //    }
    //    QXlsx::Chart *pieChart = xlsx.insertChart(3, 5, QSize(300, 300));/*在3行5列的位置插入一个图标*/
    //    pieChart->setChartType(QXlsx::Chart::CT_Pie);/*插入一个饼形图*/
    //    pieChart->addSeries(QXlsx::CellRange("A10:A19"));/*饼形图添加数据*/
    //    pieChart->addSeries(QXlsx::CellRange("B10:B19"));
    //    pieChart->addSeries(QXlsx::CellRange("C10:C19"));
    //    QXlsx::Chart *barChart = xlsx.insertChart(3, 13, QSize(300, 300));/*在3行13列的位置插入一个图标*/
    //    barChart->setChartType(QXlsx::Chart::CT_Bar);/*条形图*/
    //    barChart->addSeries(QXlsx::CellRange("A10:C19"));/*给条形图加入数据*/
    //    xlsx.saveAs("book1.xlsx");/*保存*/
    //    QXlsx::Document xlsx2("Book1.xlsx");/*复制book1到book2*/
    //    xlsx2.saveAs("Book2.xlsx");
}
