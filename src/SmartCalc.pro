QT       -= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT += printsupport charts core5compat gui widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Services/calculation.c \
    Services/converter.c \
    Views/qcustomplot.cpp \
    main.cpp \
    Controllers/CalculatorController.cpp \
    Controllers/CreditCalcController.cpp \
    Controllers/DepositCalcController.cpp \
    Controllers/GraphController.cpp \
    Controllers/Validators/CreditCalcValidator.cpp \
    Controllers/Validators/DepositCalcValidator.cpp \
    Controllers/Validators/GraphValidator.cpp \
    Controllers/Validators/InfixNotationValidator.cpp \
    Models/CalculatorModel.cpp \
    Models/CreditCalcModel.cpp \
    Models/DepositCalcModel.cpp \
    Models/GraphModel.cpp \
    Services/Service.cpp \
    Views/CalculatorUI.cpp \
    Views/Calendar.cpp \
    Views/ChartView.cpp \
    Views/CreditCalculatorUI.cpp \
    Views/DepositCalculatorUI.cpp \
    Views/GraphUI.cpp \
    Views/Layout.cpp \
    Views/MacUI.cpp \
    Views/MainWindow.cpp \
    Views/View.cpp \
    Views/WinUI.cpp

HEADERS += \
    Controllers/CalculatorController.h \
    Controllers/CreditCalcController.h \
    Controllers/DepositCalcController.h \
    Controllers/GraphController.h \
    Controllers/Validators/CreditCalcValidator.h \
    Controllers/Validators/DepositCalcValidator.h \
    Controllers/Validators/GraphValidator.h \
    Controllers/Validators/InfixNotationValidator.h \
    Models/CalculatorModel.h \
    Models/CreditCalcModel.h \
    Models/DepositCalcModel.h \
    Models/GraphModel.h \
    Services/calc.h \
    Services/IO.h \
    Services/Service.h \
    Views/View.h \
    Views/CalculatorUI.h \
    Views/Calendar.h \
    Views/ChartView.h \
    Views/CreditCalculatorUI.h \
    Views/DepositCalculatorUI.h \
    Views/GraphUI.h \
    Views/IPlatformUI.h \
    Views/Widgets.h \
    Views/Layout.h \
    Views/MacUI.h \
    Views/WinUI.h \
    Views/MainWindow.h \
    Views/qcustomplot.h



TARGET = SmartCalc
DESTDIR = ../build
target.path = $$DESTDIR/$$TARGET
INSTALLS += target
OBJECTS_DIR = obj
MOC_DIR = moc
