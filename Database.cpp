#include "Database.h"

Database::Database(string _name)
    :
    file_name(_name)
{

}

bool Database::create(Account &ac)
{
    File.open(file_name,ios::binary | ios::out | ios::app);
    File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
    File.close();
    return true;
}

void Database::display(long long acc_no)
{
    Account ac;
    bool flag=false;
    File.open(file_name, ios::binary | ios::in);
    if(!File)
    {
        cout<<"No Database Found!";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";

    while(File.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
    {
        if(ac.get_acc_no() == acc_no)
        {
            ac.show();
            flag=true;
        }
    }
    File.close();
    if(flag == false)
        cout<<"\n\nAccount number does not exist";
}

void Database::display()
{
    Account ac;
    File.open(file_name, ios::binary | ios::in);
    if(!File)
    {
        cout<<"No Database Found!";
        return;
    }
    cout<<"\n\n\t\tACCOUNT  LIST\n\n";
    cout<<"========================================================================\n";
    cout<<"SL.    A/c no.              NAME                  Balance\n";
    cout<<"========================================================================\n";
    int i = 1;
    while(File.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
    {
        cout<<left<<setw(7)<<(i++) ;
        ac.report();
        cout<<internal;
    }
    File.close();
}


bool Database::deposit(long long acc_no)
{
    long long amount;
    bool isfound=false;
    Account ac;
    File.open(file_name, ios::binary | ios::in | ios::out);
    if(!File)
    {
        cout<<"Database not Found";
        return isfound;
    }
    while(!File.eof() && isfound==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if(ac.get_acc_no() == acc_no)
        {
            ac.show();

            cout<<"\n\nEnter Deposit Amount: ";
            cin>>amount;
            ac.deposit(amount);
            cout<<"\n\nSuccessful";

            int sz = (-1)*static_cast<int>(sizeof(ac));
            File.seekp(sz,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            isfound=true;
        }
    }
    File.close();
    if(isfound==false)
        cout<<"\n\n No Account Found! ";
    return isfound;
}

bool Database::withdraw(long long acc_no)
{
    long long amount;
    bool isfound=false;
    Account ac;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if(!File)
    {
        cout<<"Database Not Found";
        return isfound;
    }
    while(!File.eof() && isfound==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if(ac.get_acc_no() == acc_no)
        {
            ac.show();

            cout<<"\n\nEnter The amount to withdraw: ";
            cin>>amount;
            if (ac.withdraw(amount) == true)
                cout<<"\n\nSuccessfully withdrawn "<<amount<<"$";
            else
                cout<<"\n\n Insufficient Balance!";

            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            isfound=true;
        }
    }
    File.close();
    if(isfound==false)
        cout<<"\n\n Account Not Found! ";
    return isfound;
}

bool Database::close(long long acc_no)
{
    Account ac;
    File.open(file_name, ios::binary | ios::in);
    if(!File)
    {
        cout<<"File not Found!";
        return false;
    }
    ofstream outFile;
    outFile.open("Temp.dat",ios::binary);
    File.seekg(0,ios::beg);
    bool flag = false;
    while(File.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
    {
        if(ac.get_acc_no() != acc_no)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            flag = true;
        }
    }
    File.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"\n\n\tRecord Deleted ..";
    return flag;
}

