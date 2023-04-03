#include "Views/mainwindow.h"



MainWindow::MainWindow(ISystem *views): ui(new Ui::MainWindow)
{
    QWidget *parent;
    views->SetParent(this, parent);

    ui->setupUi(this);
    ui->input->setAlignment(Qt::AlignRight | Qt:: AlignCenter);

    connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this, SLOT(SetCloseBracket()));
    connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this, SLOT(SetOpenBracket()));

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(SetNumber()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(SetNumber()));

    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(SetDot()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(SetX()));

    connect(ui->pushButton_factorial, SIGNAL(clicked()), this, SLOT(SetFactorial()));

    connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(SetOperator()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(SetOperator()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(SetOperator()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(SetOperator()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(SetOperator()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(SetOperator()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(SetFunction()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(SetFunction()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(SetFunction()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(SetFunction()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(SetFunction()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(SetFunction()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(SetFunction()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(SetFunction()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(SetFunction()));

    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(ClearAll()));

   connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(Equal()));
   connect(ui->pushButton_grafik, SIGNAL(clicked()), this, SLOT(DrawGraph()));
}

void MainWindow::SetNumber()
{

}

void MainWindow::SetOperator()
{

}

void MainWindow::SetFactorial()
{

}

void MainWindow::SetDot()
{

}

void MainWindow::SetOpenBracket()
{

}

void MainWindow::SetCloseBracket()
{

}

void MainWindow::SetX()
{

}

void MainWindow::SetFunction()
{
    
}

void MainWindow::ClearAll()
{

}

void MainWindow::DrawGraph()
{

}

void MainWindow::Equal()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
