#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T14:55:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InventoryProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inventorynew.cpp \
    dialoginputbutton.cpp \
    itemselection.cpp \
    logininfo.cpp \
    supplier.cpp \
    inventorylist.cpp \
    login.cpp \
    invlistinfo.cpp \
    loginglistwidget.cpp \
    dialog_adduser.cpp \
    dialog_addsupplier.cpp \
    categorybutton.cpp \
    database.cpp \
    orders.cpp

HEADERS  += mainwindow.h \
    inventorynew.h \
    dialoginputbutton.h \
    itemselection.h \
    logininfo.h \
    supplier.h \
    inventorylist.h \
    login.h \
    invlistinfo.h \
    loginglistwidget.h \
    dialog_adduser.h \
    dialog_addsupplier.h \
    categorybutton.h \
    database.h \
    orders.h

FORMS    += mainwindow.ui \
    inventorynew.ui \
    dialoginputbutton.ui \
    itemselection.ui \
    logininfo.ui \
    supplier.ui \
    inventorylist.ui \
    login.ui \
    invlistinfo.ui \
    loginglistwidget.ui \
    dialog_adduser.ui \
    dialog_addsupplier.ui \
    categorybutton.ui \
    orders.ui
