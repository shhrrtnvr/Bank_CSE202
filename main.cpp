#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "Account.cpp"
#include "Database.cpp"
using namespace std;


int main()
{
    char ch;
    long long acc_no;
    Database DB("account.dat");
    do
    {
        system("cls");
        cout<<"\n\t\t\t\t  DEVELOPED and Maintained by Saddam, Sabrina & Shahriar";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tPowered by ULAB CSE";
        cout<<"\n\n\t\t\t\t\t\t BEST BANKING SYSTEM";
        cout<<"\n\t\t\t\t\t ===================================";
        cout<<"\n\n\t1. NEW ACCOUNT";
        cout<<"\n\n\t2. DEPOSIT AMOUNT";
        cout<<"\n\n\t3. WITHDRAW AMOUNT";
        cout<<"\n\n\t4. BALANCE ENQUIRY";
        cout<<"\n\n\t5. ALL ACCOUNT LIST";
        cout<<"\n\n\t6. CLOSE AN ACCOUNT";
        cout<<"\n\n\t7. EXIT";
        cout<<"\n\n\tSelect An Option ";

        cin>>ch;
        system("cls");
        if (ch == '1')
        {
            Account acc;
            acc.create();
            DB.create(acc);
        }
        else if (ch == '2')
        {
            cout<<"\n\n\tEnter Account No. : ";
            cin.get();
            cin>>acc_no;
            DB.deposit(acc_no);
        }
        else if (ch == '3')
        {
            cout<<"\n\n\tEnter Account No. : ";
            cin.get();
            cin>>acc_no;
            DB.withdraw(acc_no);
        }
        else if (ch == '4')
        {
            cout<<"\n\n\tEnter Account No. : ";
            cin.get();
            cin>>acc_no;
            DB.display(acc_no);
        }
        else if (ch == '5')
        {
            DB.display();
        }
        else if (ch == '6')
        {
            cout<<"\n\n\tEnter Account No. : ";
            cin>>acc_no;
            DB.close(acc_no);
        }
        else if (ch == '7')
        {
            cout<<"\n\n\tThanks for Banking with us";
        }
        cin.ignore();
        cin.get();
    }
    while (ch != '7');

    return 0;
}
