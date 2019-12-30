#include <string>
#include <fstream>
#include "Account.h"
using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class Database
{
    public:
        Database(string);
        bool create(Account&);

        bool deposit(long long);
        bool withdraw(long long);

        void display();
        void display(long long);

        bool close(long long);

    protected:

    private:
        string file_name;
        fstream File;
};

#endif // DATABASE_H
