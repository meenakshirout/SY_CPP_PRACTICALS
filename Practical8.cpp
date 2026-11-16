#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    // Student marks using vector
    vector<int> marks = {75, 90, 45, 80, 60};

    // Student names using map
    map<int, string> students = {
        {1, "Amit"},
        {2, "Rahul"},
        {3, "Priya"},
        {4, "Neha"},
        {5, "Ravi"}
    };

    // Roll number and marks using unordered_map
    unordered_map<int, int> studentMarks = {
        {1, 75},
        {2, 90},
        {3, 45},
        {4, 80},
        {5, 60}
    };

    // Display student names
    cout << "Student Names:" << endl;
    for (auto s : students) {
        cout << s.first << " " << s.second << endl;
    }

    // Sort marks
    sort(marks.begin(), marks.end());

    cout << "\nSorted Marks: ";
    for (int m : marks) {
        cout << m << " ";
    }

    // Find marks greater than 80
    auto it = find_if(marks.begin(), marks.end(),
        [](int m) {
            return m > 80;
        });

    if (it != marks.end()) {
        cout << "\nMarks greater than 80: " << *it;
    }

    // Transform marks by adding 5 bonus marks
    vector<int> bonusMarks(marks.size());

    transform(marks.begin(), marks.end(),
              bonusMarks.begin(),
              [](int m) {
                  return m + 5;
              });

    cout << "\nBonus Marks: ";
    for (int m : bonusMarks) {
        cout << m << " ";
    }

    // Display unordered_map
    cout << "\n\nStudent Roll No and Marks:" << endl;

    for (auto s : studentMarks) {
        cout << s.first << " : " << s.second << endl;
    }

    return 0;
}
