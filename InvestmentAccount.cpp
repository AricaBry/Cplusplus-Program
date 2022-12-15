#include <iostream>
#include<string> 
#include <iomanip>

using namespace std;
#include "InvestmentAccount.h"

// Default constructor
InvestmentAccount::InvestmentAccount()
{
    m_compoundInterest = 0.0;
    m_totalBalance = 0.0;
    m_totalInterest = 0.0;
    m_numberOfYears = 0;
    m_strDesign = 'x';
}

// Displays main menu options
void InvestmentAccount::DataInput()
{
    cout << CharString(34, '*') << endl;
    cout << CharString(11, '*') << " Data Input " << CharString(11, '*') << endl;
    cout << "Initial Investment Amount:" << endl;
    cout << "Monthly Deposit:" << endl;
    cout << "Annual Interest:" << endl;
    cout << "Number of years:" << endl;
}

// Calculates balance without monthly deposits
void InvestmentAccount::BalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears) {

    cout << CharString(5, ' ') << "Balance and Interest Without Additional Monthly Deposits" << CharString(5, ' ') << endl;
    cout << CharString(66, '=') << endl;
    cout << CharString(2, ' ') << "Year" << CharString(10, ' ') << "Year End Balance" << CharString(10, ' ') << "Year End Earned Interest" << endl;

    cout << fixed << setprecision(2);
    m_totalBalance = t_initialInvestment;

    for (int i = 1; i <= t_numberOfYears; ++i) {
        for (int j = 1; j <= M_MONTHS; ++j) {
            m_compoundInterest = (m_totalBalance) * ((t_interestRate / 100) / 12);
            m_totalBalance += m_compoundInterest;
            m_totalInterest += m_compoundInterest;
        }
        PrintDetails(i, m_totalBalance, m_totalInterest);
        m_totalInterest = 0.0;
    }

    cout << endl;
    cout << "Total estimated balance is: " << m_totalBalance << endl;
}

// Calculates balance with monthly deposit
void InvestmentAccount::BalanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears) {

    cout << CharString(5, ' ') << "Balance and Interest With Additional Monthly Deposits" << CharString(5, ' ') << endl;
    cout << CharString(66, '=') << endl;
    cout << CharString(2, ' ') << "Year" << CharString(10, ' ') << "Year End Balance" << CharString(10, ' ') << "Year End Earned Interest" << endl;

    cout << fixed << setprecision(2);
    m_totalBalance = t_initialInvestment;

    for (int i = 1; i <= t_numberOfYears; ++i) {
        for (int j = 1; j <= M_MONTHS; ++j) {
            m_compoundInterest = (m_totalBalance + t_monthlyDeposit) * ((t_interestRate / 100) / 12);
            m_totalInterest += m_compoundInterest;
            m_totalBalance = m_totalBalance + m_compoundInterest + t_monthlyDeposit;
        }
        cout << fixed << setprecision(2);
        PrintDetails(i, m_totalBalance, m_totalInterest);
        m_totalInterest = 0.0;
    }

    cout << endl;
    cout << "Total estimated balance is: " << m_totalBalance << endl;
}

// Formats and prints out investment account stats
void InvestmentAccount::PrintDetails(int t_year, double t_yearEndBalance, double t_interestEarned) {
    cout << fixed << setprecision(2);
    cout << CharString(3, ' ') << t_year << CharString(17, ' ') << "$" << t_yearEndBalance << CharString(23, ' ') << "$" << t_interestEarned << CharString(3, ' ') << endl;
    cout << endl;
}

// Formats the design for the menus
string InvestmentAccount::CharString(size_t t_charLength, char t_char) {
    m_strDesign = "";
    // Adds char to the end of the created string
    for (unsigned int i = 0; i < t_charLength; ++i) {
        m_strDesign.push_back(t_char);
    }

    return m_strDesign;
}
