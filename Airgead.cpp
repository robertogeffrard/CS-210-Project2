//Roberto Geffrard
//CS 210
//07-21-24
//5-3 Project Two

#include "Airgead.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Banking::Banking() : initialInvestment(0), monthlyDeposit(0), annualInterest(0), numberOfYears(0) {}

// Getter and Setter for Initial Investment
double Banking::GetInitialInvestment() const {
    return initialInvestment;
}

void Banking::SetInitialInvestment(double amount) {
    initialInvestment = amount;
}

// Getter and Setter for Monthly Deposit
double Banking::GetMonthlyDeposit() const {
    return monthlyDeposit;
}

void Banking::SetMonthlyDeposit(double amount) {
    monthlyDeposit = amount;
}

// Getter and Setter for Annual Interest Rate
double Banking::GetInterestRate() const {
    return annualInterest;
}

void Banking::SetInterestRate(double rate) {
    annualInterest = rate;
}

// Getter and Setter for Number of Years
int Banking::GetNumberOfYears() const {
    return numberOfYears;
}

void Banking::SetNumberOfYears(int years) {
    numberOfYears = years;
}

// Method to calculate balance without monthly deposit
void Banking::calcBalanceWithoutMonthlyDeposit(double initialInvestment, double annualInterest, int years) const {
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "========================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    double balance = initialInvestment;
    double interestRate = annualInterest / 100.0;
    for (int i = 1; i <= years; ++i) {
        double interest = balance * interestRate;
        balance += interest;
        cout << i << "\t$" << fixed << setprecision(2) << balance << "\t\t\t\t\t$" << interest << endl;
    }
}

// Method to calculate balance with monthly deposit
void Banking::balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double annualInterest, int years) const {
    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "======================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    double m_totalAmount = initialInvestment;
    double m_yearlyTotalInterest;
    double m_interestAmount;

    for (int i = 0; i < years; i++) {
        m_yearlyTotalInterest = 0;

        for (int j = 0; j < 12; j++) {
            m_interestAmount = (m_totalAmount + monthlyDeposit) * ((annualInterest / 100.00) / 12.00);
            m_yearlyTotalInterest += m_interestAmount;
            m_totalAmount += monthlyDeposit + m_interestAmount;
        }

        cout << setw(5) << (i + 1)
            << setw(20) << fixed << setprecision(2) << m_totalAmount
            << setw(30) << fixed << setprecision(2) << m_yearlyTotalInterest << endl;
    }
}