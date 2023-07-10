QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrativo.cpp \
    editaluno.cpp \
    editprof.cpp \
    financeiro.cpp \
    fm_editaluno.cpp \
    fm_editprof.cpp \
    fm_principal.cpp \
    help.cpp \
    infos.cpp \
    main.cpp \
    mensalidades.cpp \
    newaluno.cpp \
    newprofessor.cpp \
    pagamentos.cpp \
    principal.cpp

HEADERS += \
    administrativo.h \
    editaluno.h \
    editprof.h \
    financeiro.h \
    fm_editaluno.h \
    fm_editprof.h \
    fm_principal.h \
    help.h \
    infos.h \
    mensalidades.h \
    newaluno.h \
    newprofessor.h \
    pagamentos.h \
    principal.h

FORMS += \
    administrativo.ui \
    editaluno.ui \
    editprof.ui \
    financeiro.ui \
    fm_editaluno.ui \
    fm_editprof.ui \
    fm_principal.ui \
    help.ui \
    infos.ui \
    mensalidades.ui \
    newaluno.ui \
    newprofessor.ui \
    pagamentos.ui \
    principal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
