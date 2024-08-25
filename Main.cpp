//Roberto Geffrard
//CS 210
//07-21-24
//5-3 Project Two


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Airgead.h"

using namespace std;

Banking myInvestment;
char user_input = 'a';

// Function declarations
void PrintHomeScreen();
int validIntInput();
double validDoubleInput();


int main() {
    while (user_input != 'q') {
        system("cls");
        PrintHomeScreen();

       
        myInvestment.calcBalanceWithoutMonthlyDeposit(
            myInvestment.GetInitialInvestment(),
            myInvestment.GetInterestRate(),
            myInvestment.GetNumberOfYears()
        );
        myInvestment.balanceWithMonthlyDeposit(
            myInvestment.GetInitialInvestment(),
            myInvestment.GetMonthlyDeposit(),
            myInvestment.GetInterestRate(),
            myInvestment.GetNumberOfYears()
        );

        cout << "Please enter 'q' to quit or any other character to run another report: ";
        cin >> user_input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    }

    return 0;
}


void PrintHomeScreen() {
    while (true) {
        try {
            cout << "**********************************" << endl;
            cout << "********** Data Input ************" << endl;

            cout << "Initial Investment Amount: $";
            double initialInvestment = validDoubleInput();
            if (initialInvestment < 0) {
                throw runtime_error("Invalid entry: Initial investment must be non-negative.");
            }
            myInvestment.SetInitialInvestment(initialInvestment);

            cout << "Monthly Deposit: $";
            double monthlyDeposit = validDoubleInput();
            if (monthlyDeposit < 0) {
                throw runtime_error("Invalid entry: Monthly deposit must be non-negative.");
            }
            myInvestment.SetMonthlyDeposit(monthlyDeposit);

            cout << "Annual Interest: %";
            double annualInterest = validDoubleInput();
            if (annualInterest < 0) {
                throw runtime_error("Invalid entry: Interest rate must be non-negative.");
            }
            myInvestment.SetInterestRate(annualInterest);

            cout << "Number of years: ";
            int years = validIntInput();
            if (years <= 0) {
                throw runtime_error("Invalid entry: Number of years must be greater than 0.");
            }
            myInvestment.SetNumberOfYears(years);

            
            break;
        }
        catch (const runtime_error& excpt) {
            cout << excpt.what() << endl;
            cout << "Please try again." << endl;
            system("PAUSE");
            system("cls");
        }
    }
}


int validIntInput() {
    int x;
    while (!(cin >> x)) {
        cout << "Invalid Input! Please enter a numerical value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return x;
}


double validDoubleInput() {
    double x;
    while (!(cin >> x)) {
        cout << "Invalid Input! Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return x;
}