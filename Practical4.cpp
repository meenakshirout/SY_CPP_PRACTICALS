#include <iostream>
using namespace std;

class Person
{
public:
    string name;

    void getName()
    {
        cout << "Enter name: ";
        cin >> name;
    }
};

class Student : public Person
{
public:
    int rollNo;

    void getRoll()
    {
        cout << "Enter roll number: ";
        cin >> rollNo;
    }
};

class GraduateStudent : public Student
{
public:
    void display()
    {
        cout << "\nName: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }
};

int main()
{
    GraduateStudent g;

    g.getName();
    g.getRoll();
    g.display();

    return 0;
}
