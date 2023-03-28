#include "mainwindow.h"
#include "../Controllers/Validate/Validate.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
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
   connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(Clear()));

   connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(Equal()));
   connect(ui->pushButton_grafik, SIGNAL(clicked()), this, SLOT(DrawGraph()));
   connect(ui->pushButton_CreditResult, SIGNAL(clicked()), this, SLOT(CreditResult()));
}

char* MainWindow::FromQStringToCharArray(QString qstr_input) {
    std::string str_input = qstr_input.toStdString();

    int len = str_input.length();
    char* char_input = new char[len + 1];

    strcpy(char_input, str_input.c_str());

    return char_input;
}

void MainWindow::SetNumber()
{
    Validator check(new NumberValidate);
    ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}

void MainWindow::SetOperator()
{
    Validator check(new OperatorValidate);
    ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}

void MainWindow::SetFactorial()
{
    Validator check(new OperatorValidate);
    ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}

void MainWindow::SetDot()
{
    Validator check(new DotValidate);
    ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}

void MainWindow::SetOpenBracket()
{
    Validator check(new OpenBracketValidate);
    ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}

void MainWindow::SetCloseBracket()
{
    Validator check(new CloseBracketValidate);
    ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}

void MainWindow::SetX()
{
    Validator check(new xValidate);
    ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}

void MainWindow::SetFunction()
{
    Validator check(new FunctionValidate);
    ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}

void MainWindow::ClearAll()
{
    ui->input->setText("");
}

void MainWindow::Clear()
{
   Validator check(new ClearInput);
   ui->input->setText(check.Validate(ui->input->text(), static_cast<QPushButton*>(sender())->text()));
}


void MainWindow::DrawGraph()
{
   char* char_input = FromQStringToCharArray(ui->input->text());

    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->setFixedSize(1000, 600);
    customPlot->show();

    double SetFunctiontion_scope_min = ui->doubleSpinBox->text().toDouble();
    double SetFunctiontion_scope_max = ui->doubleSpinBox_2->text().toDouble();
    double SetFunctiontion_range_min = ui->doubleSpinBox_3->text().toDouble();
    double SetFunctiontion_range_max = ui->doubleSpinBox_4->text().toDouble();

    int max = 10000;
    QVector<double> x(max), y(max), x_input(max), y_line(max);

    char char_output[1024];
    FromInfixToPostfix(char_input, char_output);
    delete[] char_input;

    double x0 = SetFunctiontion_scope_min;
    double y0 = SetFunctiontion_range_min;

    double step_x = (x0 * -1 + SetFunctiontion_scope_max) / max;
    double step_y = (y0 * -1 + SetFunctiontion_range_max) / max;

    double input_x = ui->input_x->text().toDouble();

    for (int i = 0; i < max; i++)
    {
        x[i] += x0;
        y[i] = Calculation(char_output, x[i]);
        x0 += step_x;

        if (input_x != 0) {
            x_input[i] = input_x;
            y_line[i] += y0;
            y0 += step_y;
        }
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    if (input_x != 0) {
        customPlot->addGraph();
        customPlot->graph(1)->setData(x_input, y_line);
    }

    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(SetFunctiontion_scope_min, SetFunctiontion_scope_max);
    customPlot->yAxis->setRange(SetFunctiontion_range_min, SetFunctiontion_range_max);
}

void MainWindow::Equal()
{
    double x = ui->input_x->text().toDouble();

    char* char_input = FromQStringToCharArray(ui->input->text());
    char char_output[1024];

    FromInfixToPostfix(char_input, char_output);
    delete[] char_input;

    long double result = Calculation(char_output, x);
    QString qstr_input = QString::number(result, 'g', 15);
    ui->input->setText(qstr_input);

}

void MainWindow::CreditResult()
{
   Credit annuity;
   Credit differentiated;

   annuity.sum = ui->loan_amount_input->value();
   annuity.percent = ui->percent_input->value();
   annuity.term = ui->credit_term_input->value();

   differentiated.sum = ui->loan_amount_input->value();
   differentiated.percent = ui->percent_input->value();
   differentiated.term = ui->credit_term_input->value();

   if (annuity.sum && annuity.percent && annuity.term) {
       AnnuityLoan(&annuity);
       DifferentiatedLoan(&differentiated);

       ui->monthly_payment_A->setText(QString::number(annuity.monthly_payment, 'f', 2));
       ui->overpayment_A->setText(QString::number(annuity.overpayment, 'f', 2));
       ui->total_payment_A->setText(QString::number(annuity.total_payment, 'f', 2));

       ui->monthly_payment_D->setText(QString::number(differentiated.first_monthly_payment, 'f', 2)+" - "+QString::number(differentiated.monthly_payment, 'f', 2));
       ui->overpayment_D->setText(QString::number(differentiated.overpayment, 'f', 2));
       ui->total_payment_D->setText(QString::number(differentiated.total_payment, 'f', 2));
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}
