#include "Views/mainwindow.h"
#include "Views/GraphUI.h"
#include <QMainWindow>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), cSlots(new CalcSlots), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_close_bracket, SIGNAL(clicked()), cSlots, SLOT(SetCloseBracket()));
    connect(ui->pushButton_open_bracket, SIGNAL(clicked()), cSlots, SLOT(SetOpenBracket()));

    connect(ui->pushButton_0, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_1, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_2, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_3, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_4, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_5, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_6, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_7, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_8, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
    connect(ui->pushButton_9, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));

    connect(ui->pushButton_dot, SIGNAL(clicked()), cSlots, SLOT(SetDot()));
    connect(ui->pushButton_x, SIGNAL(clicked()), cSlots, SLOT(SetX()));

    connect(ui->pushButton_factorial, SIGNAL(clicked()), cSlots, SLOT(SetFactorial()));

    connect(ui->pushButton_sum, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
    connect(ui->pushButton_div, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
    connect(ui->pushButton_log, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));

    connect(ui->pushButton_AC, SIGNAL(clicked()), cSlots, SLOT(ClearAll()));

   connect(ui->pushButton_eq, SIGNAL(clicked()), cSlots, SLOT(Equal()));
   connect(ui->pushButton_grafik, SIGNAL(clicked()), cSlots, SLOT(DrawGraph()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
