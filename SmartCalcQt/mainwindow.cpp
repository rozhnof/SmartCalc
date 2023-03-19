#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->input->setAlignment(Qt::AlignRight | Qt:: AlignCenter);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(set_number()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(set_x()));

    connect(ui->pushButton_factorial, SIGNAL(clicked()), this, SLOT(set_operator()));
    connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(set_operator()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(set_operator()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(set_operator()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(set_operator()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(set_operator()));

    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(mod()));

    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(set_dot()));

    connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this, SLOT(open_bracket()));
    connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this, SLOT(close_bracket()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(func()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(func()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(func()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(func()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(func()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(func()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(func()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(func()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(func()));

    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(all_clear()));
    connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(clear()));

    connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(equal()));
    connect(ui->pushButton_grafik, SIGNAL(clicked()), this, SLOT(graph()));

    connect(ui->pushButton_CreditResult, SIGNAL(clicked()), this, SLOT(pushButton_CreditResult()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

char* MainWindow::FromQStringToCharArray(QString qstr_input) {
    std::string str_input = qstr_input.toStdString();;

    int len = str_input.length();
    char* char_input = new char[len + 1];

    strcpy(char_input, str_input.c_str());

    return char_input;
}

void MainWindow::set_number()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    QString tmp_input = (ui->input->text()+ button->text());

    char* char_input = FromQStringToCharArray(tmp_input);
    int result = SetNumberValid(char_input);

    if (result == 1) {
          ui->input->setText(ui->input->text()+ button->text());
    } else if (result == 2) {
        std::string str_input = char_input;
        QString qstr = QString::fromStdString(str_input);

        ui->input->setText(qstr);

    }
}

void MainWindow::open_bracket()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    QString tmp_input = (ui->input->text()+ button->text());

    char* char_input = FromQStringToCharArray(tmp_input);
    int result = SetOpenBracketValid(char_input);

    if (result == 1) {
          ui->input->setText(ui->input->text()+ button->text());
    }
}

void MainWindow::close_bracket()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    QString tmp_input = (ui->input->text()+ button->text());

    char* char_input = FromQStringToCharArray(tmp_input);
    int result = SetCloseBracketValid(char_input);

    if (result == 1) {
          ui->input->setText(ui->input->text()+ button->text());
    }
}

void MainWindow::set_operator()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    QString tmp_input = (ui->input->text()+ button->text());

    char* char_input = FromQStringToCharArray(tmp_input);

    int result = SetOperatorValid(char_input);

    if (result == 1) {
        ui->input->setText(ui->input->text()+ button->text());
    } else if (result == 2) {
        ui->input->setText(char_input);
    }
}

void MainWindow::set_dot()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    QString tmp_input = (ui->input->text()+ button->text());

    char* char_input = FromQStringToCharArray(tmp_input);

    if (SetDotValid(char_input)) {
          ui->input->setText(ui->input->text()+ button->text());
    }
}

void MainWindow::func()
{
      QPushButton *button = static_cast<QPushButton*>(sender());

      char* char_input = FromQStringToCharArray(ui->input->text());

      if (SetFuncValid(char_input)) {
            ui->input->setText(ui->input->text()+ button->text() + "(");
      }
}

void MainWindow::mod()
{
      QPushButton *button = static_cast<QPushButton*>(sender());

      char* char_input = FromQStringToCharArray(ui->input->text());

      if (SetModValid(char_input)) {
            ui->input->setText(ui->input->text()+ button->text());
      }
}

void MainWindow::set_x()
{
      QPushButton *button = static_cast<QPushButton*>(sender());

      char* char_input = FromQStringToCharArray(ui->input->text());

      if (SetXValid(char_input)) {
            ui->input->setText(ui->input->text()+ button->text());
      }
}

void MainWindow::all_clear()
{
      ui->input->setText("");
}

void MainWindow::clear()
{
    QString tmp_input = (ui->input->text());

    char* char_input = FromQStringToCharArray(tmp_input);

    int result = ClearInput(char_input);

    if (result == 1) {
       ui->input->setText(char_input);
    }
}

void MainWindow::graph()
{
    char* char_input = FromQStringToCharArray(ui->input->text());

    if (ResultInputValid(char_input)) {
        QCustomPlot *customPlot = new QCustomPlot();
        customPlot->setFixedSize(1000, 600);
        customPlot->show();

        double function_scope_min = ui->doubleSpinBox->text().toDouble();
        double function_scope_max = ui->doubleSpinBox_2->text().toDouble();
        double function_range_min = ui->doubleSpinBox_3->text().toDouble();
        double function_range_max = ui->doubleSpinBox_4->text().toDouble();

        int max = 10000;
        QVector<double> x(max), y(max);


        char char_output[1024];
        FromInfixToPostfix(char_input, char_output);

        double step = (function_scope_min * -1 + function_scope_max) / max;

        double x0 = function_scope_min;
        for (int i = 0; i < max; i++)
        {
            x[i] += x0;
            y[i] = Calculation(char_output, x[i]);
            x0 += step;
        }

        customPlot->addGraph();
        customPlot->graph(0)->setData(x, y);

        customPlot->xAxis->setLabel("x");
        customPlot->yAxis->setLabel("y");
        customPlot->xAxis->setRange(function_scope_min, function_scope_max);
        customPlot->yAxis->setRange(function_range_min, function_range_max);
    }
}

void MainWindow::equal()
{
    char* char_input = FromQStringToCharArray(ui->input->text());

    if (ResultInputValid(char_input)) {
        double x = ui->input_x->text().toDouble();

        char* char_input = FromQStringToCharArray(ui->input->text());
        char char_output[1024];

        FromInfixToPostfix(char_input, char_output);
        delete[] char_input;

        long double result = Calculation(char_output, x);
        QString qstr_input = QString::number(result, 'g', 15);
        ui->input->setText(qstr_input);
    }
}

void MainWindow::pushButton_CreditResult()
{
    Credit annuity;
    Credit differentiated;

    annuity.sum = ui->loan_amount_input->value();
    annuity.percent = ui->percent_input->value();
    annuity.term = ui->credit_term_input->value();

    differentiated.sum = ui->loan_amount_input->value();
    differentiated.percent = ui->percent_input->value();
    differentiated.term = ui->credit_term_input->value();

    AnnuityLoan(&annuity);
    DifferentiatedLoan(&differentiated);

    ui->monthly_payment_A->setText(QString::number(annuity.monthly_payment, 'f', 2));
    ui->overpayment_A->setText(QString::number(annuity.overpayment, 'f', 2));
    ui->total_payment_A->setText(QString::number(annuity.total_payment, 'f', 2));

    ui->monthly_payment_D->setText(QString::number(differentiated.first_monthly_payment, 'f', 2)+" - "+QString::number(differentiated.monthly_payment, 'f', 2));
    ui->overpayment_D->setText(QString::number(differentiated.overpayment, 'f', 2));
    ui->total_payment_D->setText(QString::number(differentiated.total_payment, 'f', 2));
}



