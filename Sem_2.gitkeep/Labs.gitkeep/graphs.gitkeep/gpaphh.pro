QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addedge.cpp \
    addnode.cpp \
    graph.cpp \
main.cpp \
    mainwindow.cpp
mainwindow.cpp

 graph.cpp
 addnode.cpp
 addedge.cpp


HEADERS += \
    addedge.h \
    addnode.h \
    graph.h \
    mainwindow.h
    graph.h
    addnode.h
    addedge.h

FORMS += \
    addedge.ui \
    addnode.ui \
    mainwindow.ui
    addnode.ui
    addedge.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
