#include <iostream>
#include <utility>
using namespace std;

class Student
{
public:
    int marks;

    // Default constructor
    Student()
    {
        marks = 0;
    }

    // Parameterized constructor
    Student(int m)
    {
        marks = m;
    }

    // Copy constructor
    Student(const Student &s)
    {
        marks = s.marks;
    }

    // Move constructor
    Student(Student &&s)
    {
        marks = s.marks;
        s.marks = 0;
    }

    void display()
    {
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    Student s1;
    Student s2(90);
    Student s3(s2);
    Student s4(move(s2));

    cout << "Default Constructor: ";
    s1.display();

    cout << "Parameterized Constructor: ";
    s2.display();

    cout << "Copy Constructor: ";
    s3.display();

    cout << "Move Constructor: ";
    s4.display();

    return 0;
}
