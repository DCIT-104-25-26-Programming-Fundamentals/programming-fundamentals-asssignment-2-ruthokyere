#include <iostream>
using namespace std;


// printFibonacci()

void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;   
    }

    int first = 0, second = 1;

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++) {
        cout << first << " ";

        // Calculate the next term by shifting the two tracked values forward
        int next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
}


// isFibonacci()
// Checks whether 'target' appears in the Fibonacci sequence by generating

bool isFibonacci(int target) {
    // Negative numbers can never be Fibonacci numbers (sequence is all >= 0)
    if (target < 0) {
        return false;
    }

    int first = 0, second = 1;

    // Keep generating terms as long as we haven't passed the target yet
    while (first <= target) {
        if (first == target) {
            return true;   // found it
        }
        int next = first + second;
        first = second;
        second = next;
    }

    return false;   
}


// main()

int main() {
    // ---------------- PART A ----------------
    int n;
    cout << "How many terms? ";
    cin >> n;

    printFibonacci(n);

    // ---------------- PART B ----------------
    int target;
    cout << "\nEnter a number to check: ";
    cin >> target;

    if (isFibonacci(target)) {
        cout << target << " is a Fibonacci number." << endl;
    } else {
        cout << target << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
