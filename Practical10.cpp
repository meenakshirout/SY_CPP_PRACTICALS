#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file("students.csv", ios::in | ios::out | ios::trunc);

    string name;
    int marks;

    for(int i = 1; i <= 2; i++)
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter marks: ";
        cin >> marks;

        file.seekp(0, ios::end);
        file << name << "," << marks << endl;

        cout << "Position: " << file.tellp() << endl;
    }

    file.seekg(0, ios::beg);

    cout << "\nStudent Records:\n";

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
        cout << "Position: " << file.tellg() << endl;
    }

    file.close();

    return 0;
}
