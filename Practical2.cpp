#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNo;

protected:
    float balance;

public:
    void setData(int a, float b)
    {
        accountNo = a;
        balance = b;
    }

    void display()
    {
        cout << "Account Number: " << accountNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
public:
    void showInterest()
    {
        cout << "Interest: " << balance * 0.05 << endl;
    }
};

int main()
{
    SavingsAccount s;

    s.setData(101, 5000);
    s.display();
    s.showInterest();

    return 0;
}
