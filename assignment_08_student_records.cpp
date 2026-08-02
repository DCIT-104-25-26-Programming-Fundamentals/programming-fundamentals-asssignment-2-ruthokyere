#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Student struct

struct Student {
    string name;
    int id;
    vector<double> scores;
};


// calculateAverage()
// Computes the average of a student's scores.

double calculateAverage(const Student& student) {
    double sum = 0;
    for (int i = 0; i < student.scores.size(); i++) {
        sum += student.scores[i];
    }
    return sum / student.scores.size();
}


// displayMenu()

void displayMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}


// addStudent()

void addStudent(vector<Student>& students) {
    Student newStudent;

    cin.ignore();   

    cout << "Student name: ";
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}


// displayAllStudents()

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        const Student& s = students[i];   

        cout << "\nName: " << s.name << endl;
        cout << "ID:   " << s.id << endl;
        cout << "Scores:" << endl;

        for (int j = 0; j < s.scores.size(); j++) {
            cout << "  - " << s.scores[j] << endl;
        }

        cout << fixed << setprecision(2);   
        cout << "Average: " << calculateAverage(s) << endl;
    }
}


// findAverageById()

void findAverageById(const vector<Student>& students) {
    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchId) {
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score: "
                 << calculateAverage(students[i]) << endl;
            return;   // found it, stop searching
        }
    }

    cout << "Error: No student found with ID " << searchId << "." << endl;
}

// main()

int main() {
    vector<Student> students;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            findAverageById(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

        cout << endl;

    } while (choice != 4);

    return 0;
}
