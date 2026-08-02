#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Each performs one arithmetic operation on two doubles.

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false;   // signal failure, no result computed
    }
    result = a / b;
    return true;        // signal success
}


// computeModulus()
// Computes the remainder of a / b using integers.

bool computeModulus(int a, int b, int& result) {
    if (b == 0) {
        return false;
    }
    result = a % b;
    return true;
}


// exponent()

double exponent(double base, double exp) {
    return pow(base, exp);
}


// displayMenu()

void displayMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// main()

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        // Modulus needs integer input, so it's handled in its own branch
        if (choice == 5) {
            int a, b, result;
            cout << "Enter first number : ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;

            if (computeModulus(a, b, result)) {
                cout << "Result: " << a << " % " << b << " = " << result << endl;
            } else {
                cout << "Error: Cannot divide by zero." << endl;
            }
        }
        // All other operations use double input for decimal support
        else if (choice >= 1 && choice <= 4 || choice == 6) {
            double a, b;
            cout << "Enter first number : ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;

            cout << fixed << setprecision(2);   

            if (choice == 1) {
                cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
            } else if (choice == 2) {
                cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
            } else if (choice == 3) {
                cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
            } else if (choice == 4) {
                double result;
                if (divide(a, b, result)) {
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
            } else if (choice == 6) {
                cout << "Result: " << a << " ^ " << b << " = " << exponent(a, b) << endl;
            }
        }
        else if (choice == 7) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}
