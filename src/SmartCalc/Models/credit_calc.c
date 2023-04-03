#include "calc.h"


void AnnuityLoan(Credit* values) {
    double monthly_percent = values->percent / 12 / 100;
    
    values->monthly_payment = values->sum * (monthly_percent * pow(1 + monthly_percent, values->term) / (pow(1 + monthly_percent, values->term) - 1));
    values->total_payment = values->monthly_payment * values->term;
    values->overpayment = values->total_payment - values->sum;       
}


void DifferentiatedLoan(Credit* values) {
    double monthly_percent = values->percent / 12 / 100;

    double paid = values->sum;
    for (int i = 1; i <= values->term; i++) {
        paid = values->sum - (values->sum / values->term) * (i - 1);   
        values->monthly_payment = values->sum / values->term + paid * monthly_percent;
        values->total_payment += values->monthly_payment;
        if (i == 1) {
            values->first_monthly_payment = values->monthly_payment;
        }
    }
    values->overpayment = values->total_payment - values->sum;
}
