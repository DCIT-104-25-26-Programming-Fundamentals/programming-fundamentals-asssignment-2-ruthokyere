#include <iostream>
using namespace std;

// printSingleTable()
// Prints the multiplication table (1 to 12) for a single given number.

void printSingleTable(int num) {
    if (num <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return;   
    }

    cout << "Multiplication Table for " << num << ":" << endl;

    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << i << "  =  " << (num * i) << endl;
    }
}

// printTablesUpToN()
// Prints full multiplication tables (1-12) for every number from 1 to n,

void printTablesUpToN(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;   // exit early, no tables printed
    }

    for (int num = 1; num <= n; num++) {
        cout << "Multiplication Table for " << num << ":" << endl;

        for (int i = 1; i <= 12; i++) {
            cout << num << "  x  " << i << "  =  " << (num * i) << endl;
        }

        cout << "---------------------------" << endl;
    }
}


// pauseForNext()

void pauseForNext(string nextPartLabel) {
    cout << "\nPress Enter to continue to " << nextPartLabel << "...";
    cin.ignore();   // clears leftover newline from the previous cin >>
    cin.get();      // waits for the user to press Enter
}


// main()

int main() {
    // ---------------- PART A ----------------
    cout << "=== PART A: SINGLE TABLE ===" << endl;

    int number;
    cout << "Enter a number: ";
    cin >> number;

    printSingleTable(number);

    pauseForNext("PART B: TABLES FROM 1 TO N");

    // ---------------- PART B ----------------
    cout << "\n=== PART B: TABLES FROM 1 TO N ===" << endl;

    int n;
    cout << "Enter N: ";
    cin >> n;

    printTablesUpToN(n);

    return 0;
}
