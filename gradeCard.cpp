#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> names;
    vector<double> grades;

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        string name;
        double grade;

        cout << "Enter the name of student " << i + 1 << ": ";
        cin.ignore();  
        getline(cin, name);

        cout << "Enter the grade of student " << name << ": ";
        cin >> grade;

        names.push_back(name);
        grades.push_back(grade);
    }

    double total = 0.0;
    double highestGrade = grades[0];
    double lowestGrade = grades[0];

    for (double grade : grades) {
        total += grade;
        highestGrade = max(highestGrade, grade);
        lowestGrade = min(lowestGrade, grade);
    }

    double average = total / numStudents;

    cout << "\nStudent Grades Report:\n";
    cout << "-----------------------\n";

    for (int i = 0; i < numStudents; ++i) {
        cout << names[i] << ": " << grades[i] << endl;
    }

    cout << "\nAverage Grade: " << average << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}