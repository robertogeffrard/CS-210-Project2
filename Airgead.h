//Roberto Geffrard
//CS 210
//07-21-24
//5-3 Project Two


#ifndef AIRGEAD_H
#define AIRGEAD_H

class Banking {
private:
    double initialInvestment;  // Initial amount invested
    double monthlyDeposit;     // Monthly deposit amount
    double annualInterest;     // Annual interest rate in percentage
    int numberOfYears;         // Number of years for the investment

public:
    // Constructor
    Banking();

    // Getter and Setter for Initial Investment
    double GetInitialInvestment() const;
    void SetInitialInvestment(double amount);

    // Getter and Setter for Monthly Deposit
    double GetMonthlyDeposit() const;
    void SetMonthlyDeposit(double amount);

    // Getter and Setter for Annual Interest Rate
    double GetInterestRate() const;
    void SetInterestRate(double rate);

    // Getter and Setter for Number of Years
    int GetNumberOfYears() const;
    void SetNumberOfYears(int years);

    // Method to calculate balance without monthly deposit
    void calcBalanceWithoutMonthlyDeposit(double initialInvestment, double annualInterest, int years) const;

    // Method to calculate balance with monthly deposit
    void balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double annualInterest, int years) const;
};

#endif // AIRGEAD_H