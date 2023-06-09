QT       -= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += printsupport
QT += charts
QT += core5compat
QT += gui

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controllers/Validate/CloseBracketValidate.cpp \
    Controllers/Validate/DotValidate.cpp \
    Controllers/Validate/FactorialValidate.cpp \
    Controllers/Validate/FunctionValidate.cpp \
    Controllers/Validate/NumberValidate.cpp \
    Controllers/Validate/OpenBracketValidate.cpp \
    Controllers/Validate/OperatorValidate.cpp \
    Controllers/Validate/ResultValidate.cpp \
    Controllers/Validate/UnaryOperatorValidate.cpp \
    Controllers/Validate/Validator.cpp \
    Controllers/Validate/xValidate.cpp \
    Models/calculation.c \
    Models/converter.c \
    Models/credit_calc.c \
    Views/qcustomplot.cpp \
    main.cpp

HEADERS += \
    Controllers/CalculatorController.h \
    Controllers/Controller.h \
    Controllers/CreditCalcController.h \
    Controllers/DepositCalcController.h \
    Controllers/GraphController.h \
    Controllers/Validate/Validate.h \
    Models/CalculatorModel.h \
    Models/CreditCalcModel.h \
    Models/DepositCalcModel.h \
    Models/GraphModel.h \
    Models/Model.h \
    Models/calc.h \
    Views/Calculator.h \
    Views/CalculatorUI.h \
    Views/ChartView.h \
    Views/CreditCalculatorUI.h \
    Views/DepositCalculatorUI.h \
    Views/GraphUI.h \
    Views/IPlatformUI.h \
    Views/IWidgets.h \
    Views/Layout.h \
    Views/MacUI.h \
    Views/WinUI.h \
    Views/mainwindow.h \
    Views/qcustomplot.h


DESTDIR += ../build/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
