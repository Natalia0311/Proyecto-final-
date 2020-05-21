#-------------------------------------------------
#
# Project created by QtCreator 2020-05-04T17:38:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    inicio.cpp \
    registro.cpp \
    datos_usuario.cpp \
    datos_inicio.cpp \
    datos_registro.cpp \
    datos_paciente.cpp \
    registro_new.cpp


HEADERS += \
    basedatos.h \
    inicio.h \
    registro.h \
    datos_usuario.h \
    datos_inicio.h \
    datos_registro.h \
    datos_paciente.h \
    registro_new.h \


FORMS += \
    inicio.ui \
    registro.ui \
    registro_new.ui

QT += core sql

LIBS += \
        -lsqlite3

