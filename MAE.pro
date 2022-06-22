QT       += core gui

#画图表
QT      +=printsupport

#串口通信
QT      +=serialport

#excel文件
TARGET=MAE

include(D:\xlsx\qtxlsx.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ammeter.cpp \
    excel.cpp \
    main.cpp \
    mainwindow.cpp \
    movestage.cpp \
    qcustomplot.cpp

HEADERS += \
    ammeter.h \
    excel.h \
    mainwindow.h \
    movestage.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui
#ICO
RC_ICONS=leaf-ico.ico

UI_DIR=./tmp/ui
MOC_DIR=./tmp/moc
OBJECTS_DIR=./tmp/obj
RCC_DIR=./tmp/rcc



msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc \
    qss.qrc
