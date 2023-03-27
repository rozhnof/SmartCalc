#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SmartCalc.h"

#include <QMainWindow>
#include "qcustomplot.h"
#include <QApplication>
#include <QLabel>
#include "ui_mainwindow.h"
#include <string>
#include <string.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void FormatOutput(int status, string str_input, QString button_text);
    char* FromQStringToCharArray(QString qstr_input);


private:
    Ui::MainWindow *ui;


private slots:
    void SetNumber();
    void SetOperator();
    void SetOperatorMod();
    void SetDot();
    void SetOpenBracket();
    void SetCloseBracket();
    void SetX();
    void SetFunction();
    void ClearAll();
    void Clear();
    void Equal();
    void DrawGraph();
    void CreditResult();
};



class Controller {

};





class IValidate {
public:
    virtual int Validate(string _str) = 0;
};





class NumberValidate : public IValidate {
public:

    int Validate(string _str) override {
        int status = 1;
        int current_elem = _str.size() - 1;
        int last_elem = current_elem - 1;

        if (_str[last_elem] == 'x'){
            status = 0;
        } else if (_str[last_elem] == '!') {
            status = 0;
        } else if (_str[last_elem] == ')') {
            status = 0;
        } else if (_str[last_elem] == 'd') {
            status = 1;
        } else if (_str[last_elem] == '0' && last_elem == 0) {
            status = 2;
            _str[last_elem] = _str[current_elem];
            _str[current_elem] = '\0';
        } else if ((IsOperator(_str[last_elem-1]) || _str[last_elem-1] == '(') && _str[last_elem] == '0') {
            _str[last_elem] = _str[current_elem];
            _str[current_elem] = '\0';
            status = 2;
        }

        return status;
    }
};





class Validator {
public:
    IValidate* alg;
    Validator(IValidate* rule) {
        alg = rule;
    }

    int Validate(string input) {
        return alg->Validate(input);
    }
};


#endif // MAINWINDOW_H
