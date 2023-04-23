#ifndef MACUI_H
#define MACUI_H

#include "IPlatformUI.h"
#include <iostream>


using namespace std;

class CalcGroup {

public:
    CalcGroup() {}
    ~CalcGroup() {}

    QList<QPushButton*> buttonsList;
    QString Style;

    void addButton(QPushButton *button) {
        buttonsList.push_back(button);
    }

    void SetStyleSheet() {
        for (int i = 0; i < buttonsList.size(); i++) {
            buttonsList.at(i)->setStyleSheet(Style);
        }
    }

    void SetBackgroundColor(QString color) {
        Style += ("background-color: " + color + ";");
        SetStyleSheet();
    }

    void SetFontColor(QString color) {
        Style += ("color: " + color + ";");
        SetStyleSheet();
    }

    void SetBorderColor(QString color) {
        Style += ("border-color: " + color + ";");
        SetStyleSheet();
    }

    void SetBorderSize(QString borderSize) {
        Style += ("border-width: " + borderSize + "px;");
        SetStyleSheet();
    }
};

class MacUI : public IPlatformUI
{

private:
    CalcGroup *NumberButtons;
    CalcGroup *FunctionButtons;
    CalcGroup *OperatorButtons;
public:


    void SetSize(unordered_map<int, QWidget*> calcObjects) override  {
        int countHorizontalButtons = 7;
        int countVerticalButtons = 6;

        int windowWidth = calcObjects.at(CalcObjectsEnum::MainWindow)->width();
        int windowHeight = calcObjects.at(CalcObjectsEnum::MainWindow)->height();

        int width = windowWidth / countHorizontalButtons;
        int height = windowHeight / countVerticalButtons;

        int x, y;

        int edgeWidth = windowWidth% countHorizontalButtons + width;
        int edgeHeight = windowHeight % countVerticalButtons + height;

        QFont font = calcObjects.at(CalcObjectsEnum::LabelInput)->font();
        int size_text = (width + height ) / 4;
        font.setPointSize(size_text);
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setFont(font);


        calcObjects.at(CalcObjectsEnum::LabelInput)->setGeometry(x = 0, y = 0, windowWidth, height);

        calcObjects.at(ButtonX)->setGeometry(x = 0, y+=height, width, height);
        calcObjects.at(ButtonOpenBracket)->setGeometry(x+=calcObjects.at(ButtonX)->width(), y, width, height);
        calcObjects.at(ButtonCloseBracket)->setGeometry(x+=calcObjects.at(ButtonOpenBracket)->width(), y, width, height);
        calcObjects.at(ButtonAC)->setGeometry(x+=calcObjects.at(ButtonCloseBracket)->width(), y, width, height);
        calcObjects.at(ButtonGraph)->setGeometry(x+=calcObjects.at(ButtonAC)->width(), y, width * 2, height);
        calcObjects.at(ButtonDiv)->setGeometry(x+=calcObjects.at(ButtonGraph)->width(), y, edgeWidth, height);

        calcObjects.at(ButtonMod)->setGeometry(x = 0, y+=height, width, height);
        calcObjects.at(ButtonFactorial)->setGeometry(x+=calcObjects.at(ButtonMod)->width(), y, width, height);
        calcObjects.at(ButtonPow)->setGeometry(x+=calcObjects.at(ButtonFactorial)->width(), y, width, height);
        calcObjects.at(Button7)->setGeometry(x+=calcObjects.at(ButtonPow)->width(), y, width, height);
        calcObjects.at(Button8)->setGeometry(x+=calcObjects.at(Button7)->width(), y, width, height);
        calcObjects.at(Button9)->setGeometry(x+=calcObjects.at(Button8)->width(), y, width, height);
        calcObjects.at(ButtonMul)->setGeometry(x+=calcObjects.at(Button9)->width(), y, edgeWidth, height);

        calcObjects.at(ButtonLog)->setGeometry(x = 0, y+=height, width, height);
        calcObjects.at(ButtonLn)->setGeometry(x+=calcObjects.at(ButtonLog)->width(), y, width, height);
        calcObjects.at(ButtonSqrt)->setGeometry(x+=calcObjects.at(ButtonLn)->width(), y, width, height);
        calcObjects.at(Button4)->setGeometry(x+=calcObjects.at(ButtonSqrt)->width(), y, width, height);
        calcObjects.at(Button5)->setGeometry(x+=calcObjects.at(Button4)->width(), y, width, height);
        calcObjects.at(Button6)->setGeometry(x+=calcObjects.at(Button5)->width(), y, width, height);
        calcObjects.at(ButtonSub)->setGeometry(x+=calcObjects.at(Button6)->width(), y, edgeWidth, height);

        calcObjects.at(ButtonAsin)->setGeometry(x = 0, y+=height, width, height);
        calcObjects.at(ButtonAcos)->setGeometry(x+=calcObjects.at(ButtonAsin)->width(), y, width, height);
        calcObjects.at(ButtonAtan)->setGeometry(x+=calcObjects.at(ButtonAcos)->width(), y, width, height);
        calcObjects.at(Button1)->setGeometry(x+=calcObjects.at(ButtonAtan)->width(), y, width, height);
        calcObjects.at(Button2)->setGeometry(x+=calcObjects.at(Button1)->width(), y, width, height);
        calcObjects.at(Button3)->setGeometry(x+=calcObjects.at(Button2)->width(), y, width, height);
        calcObjects.at(ButtonSum)->setGeometry(x+=calcObjects.at(Button3)->width(), y, edgeWidth, height);

        calcObjects.at(ButtonSin)->setGeometry(x = 0, y+=height, width, edgeHeight);
        calcObjects.at(ButtonCos)->setGeometry(x+=calcObjects.at(ButtonSin)->width(), y, width, edgeHeight);
        calcObjects.at(ButtonTan)->setGeometry(x+=calcObjects.at(ButtonCos)->width(), y, width, edgeHeight);
        calcObjects.at(Button0)->setGeometry(x+=calcObjects.at(ButtonTan)->width(), y, width * 2, edgeHeight);
        calcObjects.at(ButtonDot)->setGeometry(x+=calcObjects.at(Button0)->width(), y, width, edgeHeight);
        calcObjects.at(ButtonResult)->setGeometry(x+=calcObjects.at(ButtonDot)->width(), y, edgeWidth, edgeHeight);
    }

    MacUI() {}

    void SetupCalculatorUI(unordered_map<int, QWidget*> calcObjects) override {
        calcObjects.at(CalcObjectsEnum::MainWindow)->setMinimumSize(420, 360);

        NumberButtons = new CalcGroup;
        for (int i = Button0; i <= ButtonDot; i++)
            NumberButtons->addButton(static_cast<QPushButton*>(calcObjects.at(i)));

        NumberButtons->SetBackgroundColor("rgb(89, 89, 89)");
        NumberButtons->SetBorderColor("pink");
        NumberButtons->SetBorderSize("30");


        FunctionButtons = new CalcGroup;
        for (int i = ButtonSin; i <= ButtonSqrt; i++)
            FunctionButtons->addButton(static_cast<QPushButton*>(calcObjects.at(i)));
        FunctionButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonMod)));
        FunctionButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonFactorial)));
        FunctionButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonPow)));
        FunctionButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonX)));
        FunctionButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonOpenBracket)));
        FunctionButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonCloseBracket)));

        FunctionButtons->SetBackgroundColor("rgb(56, 56, 56)");
        FunctionButtons->SetBorderColor("rgb(34, 34, 34)");


        OperatorButtons = new CalcGroup;
        for (int i = ButtonSum; i <= ButtonDiv; i++)
            OperatorButtons->addButton(static_cast<QPushButton*>(calcObjects.at(i)));
        OperatorButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonAC)));
        OperatorButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonGraph)));
        OperatorButtons->addButton(static_cast<QPushButton*>(calcObjects.at(ButtonResult)));

        OperatorButtons->SetBackgroundColor("rgb(226, 153, 57)");
        OperatorButtons->SetBorderColor("rgb(34, 34, 34)");


        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setAlignment(Qt::AlignCenter | Qt::AlignRight);
        calcObjects.at(CalcObjectsEnum::LabelInput)->setStyleSheet("background-color: black");
    }
    void SetupGraphUI() override {
        cout << "BEBRA" << endl;
    }
    void SetupCreditCalculatorUI() override {
        cout << "BEBRA" << endl;
    }
    void SetupDepositCalculatorUI() override {
        cout << "BEBRA" << endl;
    }

private slots:

};

#endif // MACUI_H
