#ifndef EXCEL_H
#define EXCEL_H

#include"xlsxdocument.h"
#include"xlsxformat.h"
#include"xlsxcellrange.h"
#include"xlsxchart.h"

class Excel
{
public:
    Excel();
    void example();
    bool saveData(QString filePath,const QVector<double>&x,const QVector<double>&y,QVector<QString>&val,QString unit,int rows);//保存数据
    bool saveDataU(QString filePath,const QVector<double>&x,const QVector<double>&y,QVector<QString>&val,QString unit);
private:

    QXlsx::Document xlsx; //xlsx对象
    QXlsx::Format format;  //单元的样式
};

#endif // EXCEL_H
