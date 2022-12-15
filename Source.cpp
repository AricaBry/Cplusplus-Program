/*
Name: Arica N. Bryant
Date: 11/21/2022
*/

#include <iostream>  
#include<string>  
#include <iomanip>
#include <stdexcept>
#include <istream>

using namespace std;

#include "InvestmentAccount.h"


int main() {
    char keyCmd;
    double initialInvest;
    double monthlyDep;
    double annualInterest;
    int numYears;

    InvestmentAccount account;

    account.DataInput();
    cout << "Press any key to continue or press 'Q' to exit the program..." << endl;
    cin >> keyCmd;

    while ((keyCmd != 'Q') && (keyCmd != 'q'))
    {
        system("cls"); // Clears the screen
        account.DataInput();

        cout << "Please enter the Initial Investment Amount. . ." << endl;
        cout << "Initial Investment Amount: $";
        cin >> initialInvest;

        // Error checking for correct input
        while (initialInvest < 0 || cin.fail())
        {
            // Clears the input
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');

            // Prompts user for new investment amount
            cout << endl;
            cout << "Invalid Input. Please enter a positive numerical value" << endl;
            cout << "Initial Investment Amount: $";
            cin >> initialInvest;
        }

        system("cls");
        account.DataInput();

        cout << "Please enter the Monthly Deposit. . ." << endl;
        cout << "Monthly Deposit Amount: $";
        cin >> monthlyDep;

        while (monthlyDep < 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');

            system("cls");
            account.DataInput();

            cout << endl;
            cout << "Invalid Input. Please enter a positive numerical value" << endl;
            cout << "Monthly Deposit Amount: $";
            cin >> monthlyDep;
        }

        system("cls");
        account.DataInput();

        cout << "Please enter the Annual Interest. . ." << endl;
        cout << "Annual Interest Amount: %";
        cin >> annualInterest;

        while (annualInterest < 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');

            system("cls");
            account.DataInput();

            cout << endl;
            cout << "Invalid Input. Please enter a positive numerical value" << endl;
            cout << "Annual Interest Amount: %";
            cin >> annualInterest;
        }

        system("cls");
        account.DataInput();

        cout << "Please enter the Number of Years. . ." << endl;
        cout << "Number of years: ";
        cin >> numYears;

        while (numYears < 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');

            system("cls");
            account.DataInput();

            cout << endl;
            cout << "Invalid Input. Please enter a positive numerical value" << endl;
            cout << "Number of years: ";
            cin >> numYears;
        }

        system("cls");

        // Calculate and display stats if no negative number errors
        account.BalanceWithoutMonthlyDeposit(initialInvest, annualInterest, numYears);
        cout << endl;
        account.BalanceWithMonthlyDeposit(initialInvest, monthlyDep, annualInterest, numYears);

        // Prompt user for continue or exit input
        cout << endl;
        cout << "Enter any key to restart the program or press 'Q' to exit." << endl;
        cin >> keyCmd;
    }

    cout << endl;
    cout << "Thank you for using the Airgead Banking Application!" << endl;

    return 0;
}