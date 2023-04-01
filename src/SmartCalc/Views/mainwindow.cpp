#include "mainwindow.h"
#include <QErrorMessage>



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), action(new Controller())
{
    ui->setupUi(this);
    ui->input->setAlignment(Qt::AlignRight | Qt:: AlignCenter);
    this->action->graph->ShowGraph();

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

    connect(ui->ScopeMin, SIGNAL(valueChanged(double)), this, SLOT(SetScopeMin()));
    connect(ui->ScopeMax, SIGNAL(valueChanged(double)), this, SLOT(SetScopeMax()));
    connect(ui->RangeMin, SIGNAL(valueChanged(double)), this, SLOT(SetRangeMin()));
    connect(ui->RangeMax, SIGNAL(valueChanged(double)), this, SLOT(SetRangeMax()));



//    connect(ui->pushButton_CreditResult, SIGNAL(clicked()), this, SLOT(CreditResult()));
}

void MainWindow::IncorrectSymbol() {
    QMessageBox* error = new QMessageBox();
    error->setText("Incorrect input");
    error->setFixedSize(40, 80);
    error->show();
}

void MainWindow::SetNumber()
{
    int status;
    ui->input->setText(this->action->Validate(new NumberValidate, ui->input->text(), static_cast<QPushButton*>(sender())->text(), status));
    if (!status) this->IncorrectSymbol();
}

void MainWindow::SetOperator()
{
    int status;
    ui->input->setText(this->action->Validate(new OperatorValidate, ui->input->text(), static_cast<QPushButton*>(sender())->text(), status));
    if (!status) this->IncorrectSymbol();
}

void MainWindow::SetFactorial()
{
    int status;
    ui->input->setText(this->action->Validate(new FactorialValidate, ui->input->text(), static_cast<QPushButton*>(sender())->text(), status));
    if (!status) this->IncorrectSymbol();
}

void MainWindow::SetDot()
{
    int status;
    ui->input->setText(this->action->Validate(new DotValidate, ui->input->text(), static_cast<QPushButton*>(sender())->text(), status));
    if (!status) this->IncorrectSymbol();
}

void MainWindow::SetOpenBracket()
{
    int status;
    ui->input->setText(this->action->Validate(new OpenBracketValidate, ui->input->text(), static_cast<QPushButton*>(sender())->text(), status));
    if (!status) this->IncorrectSymbol();
}

void MainWindow::SetCloseBracket()
{
    int status;
    ui->input->setText(this->action->Validate(new CloseBracketValidate, ui->input->text(), static_cast<QPushButton*>(sender())->text(), status));
    if (!status) this->IncorrectSymbol();
}

void MainWindow::SetX()
{
    int status;
    ui->input->setText(this->action->Validate(new xValidate, ui->input->text(), static_cast<QPushButton*>(sender())->text(), status));
    if (!status) this->IncorrectSymbol();
}

void MainWindow::SetFunction()
{
    int status;
    ui->input->setText(this->action->Validate(new FunctionValidate, ui->input->text(), static_cast<QPushButton*>(sender())->text(), status));
    if (!status) this->IncorrectSymbol();
}

void MainWindow::ClearAll()
{
    ui->input->setText("");
}


void MainWindow::DrawGraph()
{
    int status;
    this->action->Validate(new ResultValidate, ui->input->text(), "0", status);
}

void MainWindow::GetGraphValues() {
    this->action->
}

void MainWindow::GetLineValues() {

}

void MainWindow::SetScopeMin() {
    this->action->graph->SetScopeMin(ui->ScopeMin->text().toDouble());
}

void MainWindow::SetScopeMax() {
    this->action->graph->SetScopeMax(ui->ScopeMin->text().toDouble());
}

void MainWindow::SetRangeMin() {
    this->action->graph->SetRangeMin(ui->ScopeMin->text().toDouble());
}

void MainWindow::SetRangeMax() {
    this->action->graph->SetRangeMax(ui->ScopeMin->text().toDouble());
}


void MainWindow::Equal()
{
    Validator check(new ResultValidate);
    this->action->Calculate(ui->input_x->text().toDouble());
    ui->input->setText(QString::number(this->action->GetResult(), 'g', 16));
}

// void MainWindow::CreditResult()
// {
//    Credit annuity;
//    Credit differentiated;

//    annuity.sum = ui->loan_amount_input->value();
//    annuity.percent = ui->percent_input->value();
//    annuity.term = ui->credit_term_input->value();

//    differentiated.sum = ui->loan_amount_input->value();
//    differentiated.percent = ui->percent_input->value();
//    differentiated.term = ui->credit_term_input->value();

//    if (annuity.sum && annuity.percent && annuity.term) {
//        AnnuityLoan(&annuity);
//        DifferentiatedLoan(&differentiated);

//        ui->monthly_payment_A->setText(QString::number(annuity.monthly_payment, 'f', 2));
//        ui->overpayment_A->setText(QString::number(annuity.overpayment, 'f', 2));
//        ui->total_payment_A->setText(QString::number(annuity.total_payment, 'f', 2));

//        ui->monthly_payment_D->setText(QString::number(differentiated.first_monthly_payment, 'f', 2)+" - "+QString::number(differentiated.monthly_payment, 'f', 2));
//        ui->overpayment_D->setText(QString::number(differentiated.overpayment, 'f', 2));
//        ui->total_payment_D->setText(QString::number(differentiated.total_payment, 'f', 2));
//    }
// }

MainWindow::~MainWindow()
{
    delete ui;
}
