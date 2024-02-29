#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

using namespace std;


//Main Class function prototypes

//Displays the account details, as well as account balances and interest earned for each year.
void displayOutput(InvestmentAccount account, int numberOfYears) {
    string typeOfAccount = "\nBalance and Interest Without Additional Monthly Deposits\n";
    if (account.getMonthlyDeposit() != 0) {
        typeOfAccount = "\nBalance and Interest With Aditional Monthly Deposits\n";
    }
    cout << typeOfAccount << endl;
    cout << "Year            Year End Balance      Year End Earned Interested" << endl;
    for (int i = 1; i <= numberOfYears; i++) {
        cout << i << "                     " << account.getEndingBalanceFormatted(i);
        cout << "                     " << account.getInterestEarnedFormatted(i) << endl;
    }
}    

int main()
{
    double initialInvestmentAmount;
    double monthlyDepositAmount;
    double annualInterestRate;
    int numberOfYears;

    do {
        cout << "Enter Initial Investment Amount: ";
        cin >> initialInvestmentAmount;

        cout << "Enter Monthly Deposit Amount: ";
        cin >> monthlyDepositAmount;

        cout << "Enter Annual Interest Rate (in percentage): ";
        cin >> annualInterestRate;

        cout << "Enter Number of Years: ";
        cin >> numberOfYears;

        if ((initialInvestmentAmount < 0) || (monthlyDepositAmount < 0) || (numberOfYears < 0)) {
            cout << "Invalid input. Please enter positive numbers." << endl;
        }
    } while ((initialInvestmentAmount < 0) || (monthlyDepositAmount < 0) || (numberOfYears < 0));

    // Create InvestmentAccount instances
    InvestmentAccount accountWithoutMonthlyDeposit(initialInvestmentAmount, annualInterestRate);
    InvestmentAccount accountWithMonthlyDeposit(initialInvestmentAmount, annualInterestRate, monthlyDepositAmount);

    cout << "Press enter to continue..." << endl;
    cin.ignore();
    cin.get();

    //Display the output for each investment account
    displayOutput(accountWithoutMonthlyDeposit, numberOfYears);
    displayOutput(accountWithMonthlyDeposit, numberOfYears);

    return 0;
}

