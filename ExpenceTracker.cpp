#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Expense {
protected:
    string name;
    float amount;

public:
    Expense() {
        name = "Unknown";
        amount = 0;
    }

    Expense(string n, float a) {
        name = n;
        amount = a;
    }

    Expense(const Expense &e) {
        name = e.name;
        amount = e.amount;
    }

    virtual ~Expense() {
        // Virtual destructor
    }

    float getAmount() const {
        return amount;
    }

    virtual bool isSaving() const {
        return false;
    }

    virtual void display() const = 0;

    // Function overloading
    void show() const {
        cout << name << " : Rs. " << amount << endl;
    }

    void show(string message) const {
        cout << message << " " << name << " : Rs. " << amount << endl;
    }

    friend void showDetails(const Expense &e);
};

void showDetails(const Expense &e) {
    cout << "Name: " << e.name
         << ", Amount: Rs. " << e.amount << endl;
}

// Derived classes
class Food : public Expense {
public:
    Food() : Expense() {}

    Food(string n, float a) : Expense(n, a) {}

    void display() const override {
        cout << "Food - ";
        show();
    }
};

class Travel : public Expense {
public:
    Travel() : Expense() {}

    Travel(string n, float a) : Expense(n, a) {}

    void display() const override {
        cout << "Travel - ";
        show();
    }
};

class Shopping : public Expense {
public:
    Shopping() : Expense() {}

    Shopping(string n, float a) : Expense(n, a) {}

    void display() const override {
        cout << "Shopping - ";
        show();
    }
};

class Accommodation : public Expense {
public:
    Accommodation() : Expense() {}

    Accommodation(string n, float a) : Expense(n, a) {}

    void display() const override {
        cout << "Accommodation - ";
        show();
    }
};

class Savings : public Expense {
public:
    Savings() : Expense() {}

    Savings(string n, float a) : Expense(n, a) {}

    bool isSaving() const override {
        return true;
    }

    void display() const override {
        cout << "Savings - ";
        show();
    }
};

// Stack data structure
class Stack {
    Expense* records[20];
    int top;

public:
    Stack() {
        top = -1;
    }

    ~Stack() {
        while (top >= 0) {
            delete records[top];
            top--;
        }
    }

    void push(Expense* e) {
        if (top == 19) {
            cout << "Record list is full!" << endl;
            delete e;
            return;
        }

        records[++top] = e;
        cout << "Record added successfully." << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "No records to remove." << endl;
            return;
        }

        delete records[top];
        top--;

        cout << "Last record removed." << endl;
    }

    void displayAll() const {
        if (top == -1) {
            cout << "No records available." << endl;
            return;
        }

        cout << "\n--- All Records ---" << endl;

        for (int i = 0; i <= top; i++) {
            records[i]->display();
        }
    }

    friend void totalExpense(const Stack &s);
    friend void totalSavings(const Stack &s);
};

void totalExpense(const Stack &s) {
    float total = 0;

    for (int i = 0; i <= s.top; i++) {
        if (!s.records[i]->isSaving()) {
            total += s.records[i]->getAmount();
        }
    }

    cout << "Total expenses: Rs. " << total << endl;
}

void totalSavings(const Stack &s) {
    float total = 0;

    for (int i = 0; i <= s.top; i++) {
        if (s.records[i]->isSaving()) {
            total += s.records[i]->getAmount();
        }
    }

    cout << "Total savings: Rs. " << total << endl;
}

// Main function
int main() {
    Stack s;
    int choice;
    string name;
    float amount;

    do {
        cout << "\n===== EXPENSE TRACKER =====" << endl;
        cout << "1. Add Food Expense" << endl;
        cout << "2. Add Travel Expense" << endl;
        cout << "3. Add Shopping Expense" << endl;
        cout << "4. Add Accommodation Expense" << endl;
        cout << "5. Add Savings" << endl;
        cout << "6. Remove Last Record" << endl;
        cout << "7. Display All Records" << endl;
        cout << "8. Show Total Expenses" << endl;
        cout << "9. Show Total Savings" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << "Enter record name (one word): ";
            cin >> name;

            cout << "Enter amount: Rs. ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Amount must be greater than zero." << endl;
                continue;
            }

            switch (choice) {
                case 1:
                    s.push(new Food(name, amount));
                    break;

                case 2:
                    s.push(new Travel(name, amount));
                    break;

                case 3:
                    s.push(new Shopping(name, amount));
                    break;

                case 4:
                    s.push(new Accommodation(name, amount));
                    break;

                case 5:
                    s.push(new Savings(name, amount));
                    break;
            }
        }
        else {
            switch (choice) {
                case 6:
                    s.pop();
                    break;

                case 7:
                    s.displayAll();
                    break;

                case 8:
                    totalExpense(s);
                    break;

                case 9:
                    totalSavings(s);
                    break;

                case 0:
                    cout << "Thank you for using Expense Tracker!" << endl;
                    break;

                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        }

    } while (choice != 0);

    return 0;
}
