#pragma once
#ifndef AIRGEADBANKAPP_INVESTMENTACCOUNT_H_
#define AIRGEADBANKAPP_INVESTMENTACCOUNT_H_

using namespace std;

class InvestmentAccount
{
	public:
		InvestmentAccount();
		string CharString(size_t t_charLength, char t_char);
		void DataInput();
		void PrintDetails(int t_year, double t_yearEndBalance, double t_interestEarned);
		void BalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int numberOfYears);
		void BalanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);

	private:
		string m_strDesign;
		double m_compoundInterest;
		double m_totalBalance;
		double m_totalInterest;
		int m_numberOfYears;
		int const M_MONTHS = 12;
};

#endif //AIRGEADBAhhNKAPP_INVESTMENTACCOUNT_H_