#include "Account.h"

void Account::create()
{
    cout<<"\n\nEnter Account Name: ";
    cin.ignore();
    cin.getline(name, 50);

    cout<<"\nEnter Account No:";
    cin>>acc_no;

    do
    {
        cout<<"\nEnter The Initial amount(Minimum 1000) : ";
        cin>>balance;
    }
    while (balance < 1000);
    cout<<"\n\n\n Successful!";
}

void Account::show() const
{
    cout<<"\nAccount Name   : "<<name;
    cout<<"\nAccount No     : "<<acc_no;
    cout<<"\nBalance amount : "<<balance;
}




void Account::deposit(long long x)
{
    balance += x;
}

bool Account::withdraw(long long x)
{
    if (balance - x >= 500)
    {
        balance -= x;
        return true;
    }
    return false;
}

void Account::report() const
{
    cout.width(20);
    cout<<left<<acc_no;
    cout.width(25);
    cout<<name;
    cout.width(20);
    cout<<balance<<endl;
    cout<<internal;
}


long long Account::get_acc_no()
{
    return acc_no;
}

long long Account::get_balance() const
{
    return balance;
}

