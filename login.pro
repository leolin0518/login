#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T16:52:48
#
#-------------------------------------------------

QT       += core gui sql
QT       += widgets

TARGET = login
TEMPLATE = app

RC_FILE = myapp.rc


SOURCES += main.cpp\
        login.cpp \
    exam.cpp \
    passwdedit.cpp \
    register.cpp \
    systemtrayicon.cpp

HEADERS  += login.h \
    exam.h \
    passwdedit.h \
    register.h \
    systemtrayicon.h

FORMS    += login.ui \
    exam.ui \
    passwdedit.ui \
    register.ui

RESOURCES += \
    myqrc.qrc \
    lang.qrc \
    qss.qrc

TRANSLATIONS+=cn.ts\
              en.ts
