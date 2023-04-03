QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += printsupport


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controllers/Controller.cpp \
    Controllers/Validate/CloseBracketValidate.cpp \
    Controllers/Validate/DotValidate.cpp \
    Controllers/Validate/FactorialValidate.cpp \
    Controllers/Validate/FunctionValidate.cpp \
    Controllers/Validate/NumberValidate.cpp \
    Controllers/Validate/OpenBracketValidate.cpp \
    Controllers/Validate/OperatorValidate.cpp \
    Controllers/Validate/ResultValidate.cpp \
    Controllers/Validate/Validator.cpp \
    Controllers/Validate/xValidate.cpp \
    Models/calculation.c \
    Models/converter.c \
    Models/credit_calc.c \
    Views/mainwindow.cpp \
    Views/qcustomplot.cpp \
    main.cpp

HEADERS += \
    Controllers/Controller.h \
    Controllers/Graph/Graph.h \
    Controllers/Validate/Validate.h \
    Models/Model.h \
    Models/calc.h \
    Views/IWindow.h \
    Views/mainwindow.h \
    Views/qcustomplot.h

FORMS += \
    Views/mainwindow.ui \
    Views/WinWindow.ui

DESTDIR += ../build/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
