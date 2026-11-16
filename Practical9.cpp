#include <iostream>
using namespace std;

class BankException
{
};

class InsufficientBalance : public BankException
{
};

class InvalidAmount : public BankException
{
};

int main()
{
    int balance = 1000;
    int amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try
    {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientBalance();

        balance = balance - amount;

        cout << "Transaction Successful" << endl;
        cout << "Remaining Balance: " << balance;
    }

    catch (InvalidAmount)
    {
        cout << "Invalid Amount";
    }

    catch (InsufficientBalance)
    {
        cout << "Insufficient Balance";
    }

    return 0;
}
