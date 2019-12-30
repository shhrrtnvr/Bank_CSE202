#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
public:
    void create();	//function to get data from user
    void show() const;	//function to show data on screen
    void deposit(long long);	//function to accept amount and add to balance amount
    bool withdraw(long long);	//function to accept amount and subtract from balance amount
    void report() const;	//function to show data in tabular format
    long long get_acc_no();	//function to return account number
    long long get_balance() const;	//function to return balance amount

protected:

private:
    long long acc_no;
    char name[50];
    long long balance;
};

#endif // ACCOUNT_H
