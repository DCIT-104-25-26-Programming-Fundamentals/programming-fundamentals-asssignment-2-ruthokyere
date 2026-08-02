#include <iostream>
using namespace std;


char getGrade(int score) {
   
    if (score < 0 || score > 100) {
        return '\0';   // signals "invalid" back to main()
    }

   
    if (score >= 80) {          // 80-100
        return 'A';
    } else if (score >= 70) {   // 70-79
        return 'B';
    } else if (score >= 60) {   // 60-69
        return 'C';
    } else if (score >= 50) {   // 50-59
        return 'D';
    } else {                    // below 50
        return 'F';
    }
}

int main() {
    int score;

    cout << "Enter student score (0-100): ";
    cin >> score;

    char grade = getGrade(score);

    if (grade == '\0') {
        cout << "Error: Score must be between 0 and 100." << endl;
    } else {
        cout << "Grade: " << grade << endl;
    }

    return 0;
}

