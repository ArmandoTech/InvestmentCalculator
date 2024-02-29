#pragma once

#include <string>

class InvestmentAccount
{

public:
	InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit = 0);

	double getEndingBalance(int numberOfYears);  //Calculate the ending balance after number of years
	// Use www.calculators.org/savings/monthly.php to test values
	double getInterestEarned(int numberOfYears); //Calculate the interest earned for number of years

	std::string getEndingBalanceFormatted(int numberOfYears);	//Use format and round to get the ending balance as a decimal to 2 places
	std::string getInterestEarnedFormatted(int numberOfYears);  //Use format and round to get the ending balance as a decimal to 2 places

	double getInitialAmount() const;
	double getMonthlyDeposit() const;
	double getAnnualInterestRate() const;

	double round(double value, int places);
	std::string format(double value);


private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;

};

