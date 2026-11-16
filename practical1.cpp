#include <iostream>
using namespace std;

int main()
{
    float marks;
    int age;
    char grade;

    const double Pi = 3.1415;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your marks: ";
    cin >> marks;

    grade = 'A';

    cout << "\n marks: " << marks;
    cout << "\n age: " << age;
    cout << "\n grade: " << grade;
    cout << "\n constant Pi: " << Pi << endl;

    // Operators
    cout << "\n age + 5: " << age + 5;
    cout << "\n marks * 2: " << marks * 2;

    return 0;
}
