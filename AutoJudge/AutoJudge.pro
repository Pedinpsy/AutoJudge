#-------------------------------------------------
#
# Project created by QtCreator 2017-07-02T17:32:39
#
#-------------------------------------------------

QT       += core gui
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoJudge
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        paineldecontrole.cpp \
    formlogin.cpp \
    questoes.cpp \
    bancodedados.cpp \
    responderquestoes.cpp \
    cadastrarquestao.cpp \
    formselecionarquestao.cpp \
    formmostrarrespostas.cpp

HEADERS  += paineldecontrole.h \
    formlogin.h \
    formcadastrarquestao.h \
    questoes.h \
    bancodedados.h \
    responderquestoes.h \
    formselecionarquestao.h \
    formmostrarrespostas.h

FORMS    += paineldecontrole.ui \
    formlogin.ui \
    formcadastrarquestao.ui \
    responderquestoes.ui \
    formselecionarquestao.ui \
    formmostrarrespostas.ui
